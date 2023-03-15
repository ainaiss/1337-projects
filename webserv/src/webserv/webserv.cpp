#include "webserv.hpp"

webserv::webserv(const char *config_path) : failed(false), default_servers(), sockfd_server(), kq(-1) {
    if (utils::get_extension(config_path) != "conf") {
        failed = true;
        LOG_ERROR("%s", "Invalid configuration file extension");
        return;
    }
    config_parser config_prsr(config_path);
    const std::vector<server_config> &server_configs = config_prsr.get_server_configs();
    failed = config_prsr.has_failed() || server_configs.size() == 0;
    if (!failed) {
        kq = ::kqueue();
        if (kq < 0) {
            failed = true;
            LOG_ERROR("Failed to create the kernel event queue");
            LOG_ERRNO;
            return;
        }
        setup_default_servers(server_configs);
    }
}

webserv::~webserv() {
    if (kq >= 0) {
        ::close(kq);
    }
    for (std::map<std::string, tcp_server *>::iterator it = default_servers.begin(); it != default_servers.end(); ++it)
        delete it->second;
}

bool webserv::has_failed() const { return failed; }

static bool interrupted = false;
static void interrupt(int) {
    interrupted = true;
    LOG_INFO("Received signal to quit");
}

void webserv::serve_forever() {
    ASSERT(failed == false);
    ::signal(SIGINT, interrupt);
    while (!interrupted) {
        serve();
    }
}

void webserv::setup_default_servers(const std::vector<server_config> &server_configs) {
    for (std::vector<server_config>::const_iterator it = server_configs.begin(); it != server_configs.end(); ++it) {
        const std::string &port = it->port;
        if (default_servers.find(port) == default_servers.end())
            default_servers[port] = new tcp_server(*it);
        else {
            failed = true;
            LOG_ERROR("Multiple servers are listening on port %s", port.c_str());
            return;
        }
        default_servers[port]->turn_on();
        if (!default_servers[port]->has_failed()) {
            sockfd_server[default_servers[port]->sockfd] = default_servers[port];
            struct kevent changelist;
            std::memset(&changelist, 0, sizeof(changelist));
            EV_SET(&changelist, default_servers[port]->sockfd, EVFILT_READ, EV_ADD, 0, 0, NULL);
            if (::kevent(kq, &changelist, 1, NULL, 0, NULL) < 0) {
                failed = true;
                LOG_ERROR(
                    "Failed to add the server socket to the kernel event "
                    "queue");
                LOG_ERRNO;
                return;
            }
        }
    }
}

void webserv::serve() {
    struct kevent eventlist;
    std::memset(&eventlist, 0, sizeof(eventlist));
    if (::kevent(kq, NULL, 0, &eventlist, 1, NULL) < 0) {
        failed = true;
        LOG_ERROR("Failed to wait for events on the kernel event queue");
        LOG_ERRNO;
        return;
    }
    if (eventlist.flags & EV_ERROR) {
        failed = true;
        LOG_ERROR("An error occurred on the kernel event queue");
        LOG_ERRNO;
        return;
    }
    if (eventlist.flags & EV_EOF) {
        request_parser *request_prsr = (request_parser *)eventlist.udata;
        delete request_prsr;
        ::close(eventlist.ident);
        LOG_INFO("The client socket was closed");
        return;
    } else if (eventlist.filter == EVFILT_READ) {
        if (sockfd_server.find(eventlist.ident) != sockfd_server.end()) {
            int connfd = ::accept(eventlist.ident, NULL, NULL);
            struct kevent changelist;
            std::memset(&changelist, 0, sizeof(changelist));
            request_parser *request_prsr = new request_parser();
            request_prsr->server_fd = eventlist.ident;
            request_prsr->client_fd = connfd;
            EV_SET(&changelist, connfd, EVFILT_READ, EV_ADD, 0, 0, (void *)request_prsr);
            if (::kevent(kq, &changelist, 1, NULL, 0, NULL) < 0) {
                ::close(connfd);
                LOG_ERROR(
                    "Failed to add the client socket to the kernel event "
                    "queue");
                LOG_ERRNO;
                return;
            }
            LOG_INFO("A client socket was opened");
        } else
            parse_request((request_parser *)eventlist.udata);
    } else if (eventlist.filter == EVFILT_WRITE) {
        send_response((request_parser *)eventlist.udata);
    } else {
        if (eventlist.udata != NULL) {
            request_parser *request_prsr = (request_parser *)eventlist.udata;
            delete request_prsr;
        }
        ::close(eventlist.ident);
        LOG_ERROR("An unknown event occurred on the kernel event queue");
        return;
    }
}

static std::size_t hex_to_dec(const std::string &hex_num) {
    if (hex_num.size() == 0) return 0;
    std::stringstream ss;
    ss << std::hex << hex_num;
    std::size_t ans;
    ss >> ans;
    return ans;
}

void webserv::parse_request(request_parser *request_prsr) {
    char buffer[BUFFER_SIZE + 1];

    std::memset(buffer, 0, BUFFER_SIZE + 1);
    ssize_t ret = ::recv(request_prsr->client_fd, buffer, BUFFER_SIZE, 0);
    if (ret <= 0) {
        ::close(request_prsr->client_fd);
        delete request_prsr;
        LOG_ERROR("Failed to receive a message from client");
        LOG_ERRNO;
        return;
    }
    request_prsr->body.append(buffer, ret);
    request_prsr->parse_headers();
    if (request_prsr->has_failed()) {
        const std::string &response = generate_response(request_prsr);
        set_response(request_prsr, response);
        return;
    }
    if (request_prsr->headers["Transfer-Encoding"] == "chunked" &&
        request_prsr->body.find("0\r\n\r\n") != std::string::npos) {
        std::stringstream ss;
        while (true) {
            std::size_t crlf_pos = request_prsr->body.find(CRLF);
            if (crlf_pos == std::string::npos) break;
            std::size_t chunk_size = hex_to_dec(request_prsr->body.substr(0, crlf_pos));
            request_prsr->body.erase(0, crlf_pos + 2);
            ss << request_prsr->body.substr(0, chunk_size);
            request_prsr->body.erase(0, chunk_size + 2);
        }
        request_prsr->body = ss.str();
    }
    if (request_prsr->headers["Content-Length"].size() == 0 ||
        std::stoul(request_prsr->headers["Content-Length"]) <= request_prsr->body.size()) {
        if (request_prsr->headers["Content-Length"].size() != 0 &&
            std::stoul(request_prsr->headers["Content-Length"]) < request_prsr->body.size()) {
            request_prsr->failed = 413;
        }
        LOG_INFO("A client request was received successfully");
        LOG_DEBUG("%s", request_prsr->to_string().c_str());
        const std::string &response = generate_response(request_prsr);
        LOG_DEBUG("%s", response.c_str());
        set_response(request_prsr, response);
    }
}

void webserv::send_response(webserv::request_parser *request_prsr) {
    int ret = ::send(request_prsr->client_fd, request_prsr->response.c_str() + request_prsr->bytes_sent,
                     std::min<int>(BUFFER_SIZE, request_prsr->response.size() - request_prsr->bytes_sent), 0);
    if (ret <= 0) {
        ::close(request_prsr->client_fd);
        delete request_prsr;
        if (ret < 0) {
            LOG_ERROR("Failed to send a message to client");
            LOG_ERRNO;
        } else {
            LOG_INFO("The client socket was closed");
        }
        return;
    }
    request_prsr->bytes_sent += ret;
    if (request_prsr->bytes_sent == request_prsr->response.size()) {
        ::close(request_prsr->client_fd);
        delete request_prsr;
        LOG_INFO("The response was sent successfully");
    }
}

void webserv::set_response(webserv::request_parser *request_prsr, const std::string &response) {
    request_prsr->response = response;
    request_prsr->bytes_sent = 0;
    struct kevent changelist;
    std::memset(&changelist, 0, sizeof(changelist));
    EV_SET(&changelist, request_prsr->client_fd, EVFILT_WRITE, EV_ADD, 0, 0, (void *)request_prsr);
    if (::kevent(kq, &changelist, 1, NULL, 0, NULL) < 0) {
        ::close(request_prsr->client_fd);
        delete request_prsr;
        LOG_ERROR("Failed to add the client socket to the kernel event queue");
        LOG_ERRNO;
        return;
    }
}
