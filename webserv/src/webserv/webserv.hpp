#ifndef _WEBSERV_HPP_
#define _WEBSERV_HPP_

#include <dirent.h>
#include <sys/event.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <utility>

#include "../parsers/config_parser.hpp"
#include "../utilities/logger.hpp"
#include "../tcp_server/tcp_server.hpp"
#include "../utilities/utils.hpp"

static const char *DEFAULT_CONFIG_PATH = "./default.conf";
static const int MAX_HTTP_HEADER_SIZE = 4096;
static const int BUFFER_SIZE = MAX_HTTP_HEADER_SIZE;
static const char *CRLF = "\r\n";
static const char *DOUBLE_CRLF = "\r\n\r\n";
static const std::size_t MAX_URL_LENGTH = 128;

class webserv {
   public:
    webserv(const char *config_path);
    ~webserv();

    bool has_failed() const;
    void serve_forever();

    struct request_parser {
       public:
        request_parser();
        ~request_parser();

        bool has_failed() const;
        void parse_headers();

        std::string to_string() const;

       public:
        std::size_t failed;
        int server_fd;
        int client_fd;
        std::string method;
        std::string url;
        std::string http_version;
        std::string body;
        std::map<std::string, std::string> headers;

        std::string response;
        std::size_t bytes_sent;
    };  // struct request_parser

    struct http_map {
        http_map();
        ~http_map();

        bool contains_status_code(std::size_t code) const;
        bool contains_content_type(const std::string &type) const;

        std::map<std::size_t, std::string> status_code;
        std::map<std::string, std::string> content_type;

    };  // struct http_map
    static const http_map http_mapper;

   private:
    void setup_default_servers(const std::vector<server_config> &server_configs);
    void serve();
    void parse_request(request_parser *request_prsr);
    std::string generate_response(request_parser *request_prsr);
    void set_response(request_parser *request_prsr, const std::string &response);
    void send_response(request_parser *request_prsr);

   private:
    bool failed;
    std::map<std::string, tcp_server *> default_servers;
    std::map<int, tcp_server *> sockfd_server;
    int kq;

};  // class webserv

#endif  // _WEBSERV_HPP_
