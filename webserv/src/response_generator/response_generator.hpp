#ifndef _RESPONSE_GENERATOR_HPP_
#define _RESPONSE_GENERATOR_HPP_

#include "../webserv/webserv.hpp"

std::string get_status_page(tcp_server *server, std::size_t status_code);
location_config *find_location_config(server_config &server_conf, const std::string &url);
std::string get_autoindex_page(tcp_server *server, webserv::request_parser *request_prsr,
                               const std::string &full_path);
std::string get_file_page(tcp_server *server, const std::string &full_path);
std::string get_fastcgi_page(tcp_server *server, const std::string &full_path);
std::string http_get(tcp_server *server, webserv::request_parser *request_prsr,
                     location_config *location_conf);
std::string http_post(tcp_server *server, webserv::request_parser *request_prsr,
                      location_config *location_conf);
std::string http_delete(tcp_server *server, webserv::request_parser *request_prsr,
                        location_config *location_conf);

#endif // _RESPONSE_GENERATOR_HPP_
