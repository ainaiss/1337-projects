#ifndef _SERVER_CONFIG_HPP_
#define _SERVER_CONFIG_HPP_

#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

static const std::string &DEFAULT_SERVER_NAME = "";
static const std::string &DEFAULT_HOST = "0.0.0.0";
static const std::string &DEFAULT_PORT = "8080";
static const std::string &DEFAULT_SERVER_ROOT_PATH = "var/www/";
static const std::string &DEFAULT_LOCATION_URI = "/";

struct location_config {
   public:
    location_config();
    location_config(const location_config &other);
    ~location_config();
    location_config &operator=(const location_config &other);

    std::string to_string() const;

   public:
    std::string uri;
    std::set<std::string> allowed_methods;
    std::pair<std::size_t, std::string> redirection;
    std::string root;
    std::string index;
    std::string fastcgi_addr;
    bool autoindex;

};  // struct location_config

struct server_config {
   public:
    server_config();
    server_config(const server_config &other);
    ~server_config();
    server_config &operator=(const server_config &other);

    std::string to_string() const;

   public:
    std::string server_name;
    std::string host;
    std::string port;
    std::string root;
    std::map<std::size_t, std::string> error_pages;
    std::size_t client_max_body_size;
    std::vector<location_config> location_configs;
    std::set<std::string> supported_fastcgi_exts;

};  // struct server_config

#endif  // _SERVER_CONFIG_HPP_
