#include "response_generator.hpp"

std::string webserv::generate_response(webserv::request_parser *request_prsr) {
    // get appropriate tcp_server using the server_fd from request_prsr
    tcp_server *server = sockfd_server[request_prsr->server_fd];
    // if any failure in the request_prsr, generate the appropriate status page.
    if (request_prsr->has_failed())
        return get_status_page(server, request_prsr->failed);
    // fatine: check on the body size ( > client_max_body_size?) return error 413 if so
    if (request_prsr->body.size() > server->config.client_max_body_size)
        return get_status_page(server, 413);
    // get location config, if no location found return error 404
    location_config *location_conf = find_location_config(server->config, request_prsr->url);
    if (location_conf == NULL)
        return get_status_page(server, 404);
    // use server root as default for location
    if (location_conf->root.empty()) {
        location_conf->root = server->config.root;
    }
    // handle redirection if it is the case
    if (location_conf->redirection.first != 0) {
        std::stringstream ss;
        ss << "HTTP/1.1 " << location_conf->redirection.first << CRLF;
        ss << "Location: " << location_conf->redirection.second << CRLF;
        ss << CRLF;
        return ss.str();
    }
    // check if method is allowed, if not return 405
    if (location_conf->allowed_methods.size() > 0
        && location_conf->allowed_methods.find(request_prsr->method) == location_conf->allowed_methods.end())
        return get_status_page(server, 405);
    // run the appropriate function depending on the method (get() for GET, ...)
    if (request_prsr->method == "GET") {
        return http_get(server, request_prsr, location_conf);
    } else if (request_prsr->method == "POST") {
        return http_post(server, request_prsr, location_conf);
    } else if (request_prsr->method == "DELETE") {
        return http_delete(server, request_prsr, location_conf);
    } else {
        return get_status_page(server, 405);
    }
}

std::string get_status_page(tcp_server *server, std::size_t status_code) {
    std::stringstream ss;
    ss << "HTTP/1.1 " << webserv::http_mapper.status_code.at(status_code) << CRLF;
    ss << "Content-Type: text/html" << CRLF;
    const std::string &body = (server->config.error_pages.find(status_code) != server->config.error_pages.end())
                                  ? server->config.error_pages.at(status_code)
                                  : webserv::http_mapper.status_code.at(status_code);
    ss << "Content-Length: " << body.size() << CRLF;
    ss << CRLF;
    ss << body;
    return ss.str();
}

location_config *find_location_config(server_config &server_conf, const std::string &url) {
    // Looks for the longest match of location_config and the url
    location_config *location_conf = NULL;
    for (std::size_t i = 0; i < server_conf.location_configs.size(); i++) {
        if (url == server_conf.location_configs[i].uri) {
            location_conf = &server_conf.location_configs[i];
            break;
        } else if (url.find(server_conf.location_configs[i].uri) == 0) {
            if (location_conf == NULL || location_conf->uri.size() < server_conf.location_configs[i].uri.size()) {
                location_conf = &server_conf.location_configs[i];
            }
        }
    }
    LOG_DEBUG("Location config: %s", location_conf->to_string().c_str());
    return location_conf;
}
