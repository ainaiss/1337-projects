#include "response_generator.hpp"

std::string http_delete(tcp_server *server, webserv::request_parser *request_prsr,
                                 location_config *location_conf) {
    if (location_conf->root[location_conf->root.size() - 1] != '/') location_conf->root += '/';
    std::string url = request_prsr->url.substr(location_conf->uri.size());
    if (url[0] == '/') url = url.substr(1);
    if (location_conf->root[location_conf->root.size() - 1] != '/') location_conf->root += '/';
    const std::string &full_path = location_conf->root + url;
    if (utils::is_directory(full_path)) {
        return get_status_page(server, 405);
    }
    if (remove((full_path).c_str()) != 0) {
        return get_status_page(server, 500);
    }
    std::stringstream ss;
    ss << "HTTP/1.1 200 OK" << CRLF;
    ss << "Content-Type: text/html" << CRLF;
    ss << CRLF;
    ss << "<!DOCTYPE html>" << CRLF;
    ss << "<html>" << CRLF;
    ss << "<head>" << CRLF;
    ss << "<title>DELETE " << request_prsr->url << "</title>" << CRLF;
    ss << "</head>" << CRLF;
    ss << "<body>" << CRLF;
    ss << "<h1>DELETE " << request_prsr->url << "</h1>" << CRLF;
    ss << "<hr>" << CRLF;
    ss << "</body>" << CRLF;
    ss << "</html>" << CRLF;
    return ss.str();
}
