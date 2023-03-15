#include "response_generator.hpp"

std::string http_get(tcp_server *server, webserv::request_parser *request_prsr,
                                   location_config *location_conf) {
    if (location_conf->root[location_conf->root.size() - 1] != '/')
        location_conf->root += '/';
    std::string url = request_prsr->url.substr(location_conf->uri.size());
    if (url[0] == '/')
        url = url.substr(1);
    if (location_conf->root[location_conf->root.size() - 1] != '/')
        location_conf->root += '/';
    std::string full_path = location_conf->root + url;
    if (utils::is_directory(full_path)) {
        if (location_conf->autoindex) {
            return get_autoindex_page(server, request_prsr, full_path);
        } else if (location_conf->index.size() > 0) {
            if (full_path[full_path.size() - 1] != '/')
                full_path += '/';
            if (location_conf->index[0] == '/')
                location_conf->index = location_conf->index.substr(1);
            return get_file_page(server, full_path + location_conf->index);
        } else {
            return get_status_page(server, 403);
        }
    }
    return get_file_page(server, full_path);
}

std::string get_autoindex_page(tcp_server *server, webserv::request_parser *request_prsr,
                               const std::string &full_path) {
    std::stringstream ss;
    ss << "HTTP/1.1 200 OK" << CRLF;
    ss << "Content-Type: text/html" << CRLF;
    ss << CRLF;
    ss << "<!DOCTYPE html>" << CRLF;
    ss << "<html>" << CRLF;
    ss << "<head>" << CRLF;
    ss << "<title>Index of " << request_prsr->url << "</title>" << CRLF;
    ss << "</head>" << CRLF;
    ss << "<body>" << CRLF;
    ss << "<h1>Index of " << request_prsr->url << "</h1>" << CRLF;
    ss << "<hr>" << CRLF;
    ss << "<pre>" << CRLF;
    struct dirent *entry;
    DIR *dir = opendir(full_path.c_str());
    if (dir == NULL) {
        return get_status_page(server, 500);
    }
    if (request_prsr->url[request_prsr->url.size() - 1] != '/') {
        request_prsr->url += '/';
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            ss << "<a href=\"" << request_prsr->url + entry->d_name << "/\">" << entry->d_name << "/</a>" << CRLF;
        } else {
            ss << "<a href=\"" << request_prsr->url + entry->d_name << "\">" << entry->d_name << "</a>" << CRLF;
        }
    }
    closedir(dir);
    ss << "</pre>" << CRLF;
    ss << "<hr>" << CRLF;
    ss << "</body>" << CRLF;
    ss << "</html>" << CRLF;
    return ss.str();
}

std::string get_file_page(tcp_server *server, const std::string &full_path) {
    if (server->config.supported_fastcgi_exts.find(utils::get_extension(full_path)) ==
        server->config.supported_fastcgi_exts.end()) {
        std::stringstream ss;
        ss << "HTTP/1.1 200 OK" << CRLF;
        const std::string &content_type = webserv::http_mapper.content_type.find(utils::get_extension(full_path)) !=
                                                  webserv::http_mapper.content_type.end()
                                              ? webserv::http_mapper.content_type.at(utils::get_extension(full_path))
                                              : "application/octet-stream";  // "text/plain";
        ss << "Content-Type: " << content_type << CRLF;
        if (access(full_path.c_str(), F_OK) != 0)
            return get_status_page(server, 404);
        if (access(full_path.c_str(), R_OK) == -1 || utils::is_directory(full_path))
            return get_status_page(server, 403);
        std::ifstream ifs(full_path.c_str());
        if (!ifs.is_open()) {
            return get_status_page(server, 404);
        }
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        const std::string &body = buffer.str();
        ss << "Content-Length: " << body.size() << CRLF;
        ss << CRLF;
        ss << body;
        return ss.str();
    } else {
        return get_fastcgi_page(server, full_path);
    }
}
