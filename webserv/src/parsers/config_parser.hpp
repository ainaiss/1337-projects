#ifndef _CONFIG_parser_HPP_
#define _CONFIG_parser_HPP_

#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "../utilities/logger.hpp"
#include "../tcp_server/server_config.hpp"
#include "../utilities/utils.hpp"

static const char *WHITESPACE_CHARS = " \t\r\n\v\f";
static const int PORT_LIMIT = (1 << 16) - 1;

class config_parser {
   public:
    typedef void (config_parser::*option_parser)(server_config &, const std::string &);
    typedef void (config_parser::*location_option_parser)(location_config &, const std::string &);
    struct option_parser_map {
        option_parser_map();
        ~option_parser_map();

        bool contains(const std::string &option) const;
        bool location_contains(const std::string &location_option) const;

        std::map<std::string, option_parser> options;
        std::map<std::string, location_option_parser> location_options;
    };  // struct option_parser_map
    static const option_parser_map option_parser_mapper;

    config_parser(const char *config_path);
    ~config_parser();

    bool has_failed() const;
    const std::vector<server_config> &get_server_configs() const;

   private:
    void parse_config_file();
    void parse_server_block();
    void parse_location_block(server_config &server_conf);

    void parse_server_name_field(server_config &server_conf, const std::string &field_val);
    void parse_listen_field(server_config &server_conf, const std::string &field_val);
    void parse_root_field(server_config &server_conf, const std::string &field_val);
    void parse_error_page_field(server_config &server_conf, const std::string &field_val);
    void parse_client_max_body_size_field(server_config &server_conf, const std::string &field_val);

    void parse_location_autoindex_field(location_config &location_conf, const std::string &field_val);
    void parse_location_root_field(location_config &location_conf, const std::string &field_val);
    void parse_location_index_field(location_config &location_conf, const std::string &field_val);
    void parse_location_allow_methods_field(location_config &location_conf, const std::string &field_val);
    void parse_location_return_field(location_config &location_conf, const std::string &field_val);
    void parse_fastcgi_pass_field(location_config &location_conf, const std::string &field_val);

    const std::string &get_next_line();
    const std::string &get_next_token();
    bool no_token_left() const;
    bool token_prefix(const std::string &prefix);

    void log_pretty_err(const char *err_msg) const;

   private:
    bool failed;
    std::ifstream ifs;
    std::string line;
    std::string token;
    std::size_t line_cnt;
    std::size_t pos;
    std::vector<server_config> server_configs;

};  // class config_parser

#endif  // _CONFIG_parser_HPP_
