#include "tcp_server.hpp"

tcp_server::tcp_server(const server_config &config) : config(config), sockfd(-1), failed(false) {}

tcp_server::~tcp_server() { ::close(sockfd); }

bool tcp_server::has_failed() const { return failed; }

void tcp_server::turn_on() {
    sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        failed = true;
        LOG_ERROR("Cannot create socket");
        LOG_ERRNO;
        return;
    }
    // Mother of all explanations: https://stackoverflow.com/a/14388707
    const int optval = 1;
    if (::setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval)) < 0) {
        failed = true;
        LOG_ERROR("Cannot set socket port to be reusable");
        LOG_ERRNO;
        return;
    }
    struct sockaddr_in address;
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = ::inet_addr(config.host.c_str());
    address.sin_port = htons(std::atoi(config.port.c_str()));
    if (::bind(sockfd, reinterpret_cast<sockaddr *>(&address), sizeof(address)) < 0) {
        failed = true;
        LOG_ERROR("Binding a name to a socket failed");
        LOG_ERRNO;
        return;
    }
    if (::listen(sockfd, DEFAULT_BACKLOG) < 0) {
        failed = true;
        LOG_ERROR("Cannot listen for connections on a socket");
        LOG_ERRNO;
        return;
    }
    LOG_INFO("New TCP server listening on %s:%s", config.host.c_str(), config.port.c_str());
}
