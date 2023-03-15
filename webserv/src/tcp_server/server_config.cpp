#include "server_config.hpp"

server_config::server_config()
    : server_name(DEFAULT_SERVER_NAME),
      host(DEFAULT_HOST),
      port(DEFAULT_PORT),
      root(DEFAULT_SERVER_ROOT_PATH),
      client_max_body_size(std::string::npos),
      supported_fastcgi_exts() {}

server_config::~server_config() {}

server_config::server_config(const server_config &other)
    : server_name(other.server_name),
      host(other.host),
      port(other.port),
      root(other.root),
      error_pages(other.error_pages),
      client_max_body_size(other.client_max_body_size),
      location_configs(other.location_configs),
      supported_fastcgi_exts(other.supported_fastcgi_exts) {}

server_config &server_config::operator=(const server_config &other) {
    if (this != &other) {
        server_name = other.server_name;
        host = other.host;
        port = other.port;
        root = other.root;
        error_pages = other.error_pages;
        client_max_body_size = other.client_max_body_size;
        location_configs = other.location_configs;
        supported_fastcgi_exts = other.supported_fastcgi_exts;
    }
    return *this;
}

std::string server_config::to_string() const {
    std::stringstream ss;
    ss << "server_config {";
    ss << "server_name: " << server_name << ", ";
    ss << "host: " << host << ", ";
    ss << "port: " << port << ", ";
    ss << "root: " << root << ", ";
    ss << "client_max_body_size: " << client_max_body_size << ", ";
    ss << "error_pages: {";
    for (std::map<std::size_t, std::string>::const_iterator it = error_pages.begin(); it != error_pages.end(); it++) {
        ss << it->first << ": " << it->second << ", ";
    }
    ss << "}, ";
    ss << "location_configs: {";
    for (std::vector<location_config>::const_iterator it = location_configs.begin(); it != location_configs.end();
         it++) {
        ss << it->to_string() << ", ";
    }
    ss << "}";
    ss << "}";
    return ss.str();
}

location_config::location_config()
    : uri(DEFAULT_LOCATION_URI), allowed_methods(), redirection(), root(), index(), fastcgi_addr(), autoindex(false) {}

location_config::~location_config() {}

location_config::location_config(const location_config &other)
    : uri(other.uri),
      allowed_methods(other.allowed_methods),
      redirection(other.redirection),
      root(other.root),
      index(other.index),
      fastcgi_addr(other.fastcgi_addr),
      autoindex(other.autoindex) {}

location_config &location_config::operator=(const location_config &other) {
    uri = other.uri;
    allowed_methods = other.allowed_methods;
    redirection = other.redirection;
    root = other.root;
    index = other.index;
    fastcgi_addr = other.fastcgi_addr;
    autoindex = other.autoindex;
    return *this;
}

std::string location_config::to_string() const {
    std::stringstream ss;
    ss << "location_config {\n";
    ss << "\turi: " << uri << "\n";
    ss << "\tallowed_methods: [";
    for (std::set<std::string>::const_iterator it = allowed_methods.begin(); it != allowed_methods.end(); ++it) {
        ss << *it << ", ";
    }
    ss << "]\n";
    ss << "\tredirection: " << redirection.first << " " << redirection.second << "\n";
    ss << "\troot: " << root << "\n";
    ss << "\tindex: " << index << "\n";
    ss << "\tfastcgi_addr: " << fastcgi_addr << "\n";
    ss << "\tautoindex: " << autoindex << "\n";
    ss << "}";
    return ss.str();
}
