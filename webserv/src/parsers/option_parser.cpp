#include "config_parser.hpp"

// look up syntax at
// https://nginx.org/en/docs/http/ngx_http_core_module.html

void config_parser::parse_listen_field(server_config &server_conf, const std::string &field_val) {
    std::string host = DEFAULT_HOST;
    std::string port = DEFAULT_PORT;
    if (field_val.find_first_of(WHITESPACE_CHARS) != std::string::npos || field_val.size() == 0) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'listen' is incorrect");
        LOG_INFO("Valid syntax: 'listen address[:port];'");
        return;
    }
    switch (std::count(field_val.begin(), field_val.end(), ':')) {
        case 0: {
            if (field_val.find_first_not_of("0123456789") == std::string::npos)
                port = field_val;
            else
                host = field_val;
        } break;

        case 1: {
            std::size_t colon_pos = field_val.find(':');
            host = field_val.substr(0, colon_pos);
            port = field_val.substr(colon_pos + 1);
        } break;

        default: {
            failed = true;
            LOG_ERROR("Invalid listen value syntax, at line %lu:\n\t%s", line_cnt, field_val.c_str());
            return;
        }
    }
    if (port.find_first_not_of("0123456789") != std::string::npos || std::atol(port.c_str()) > PORT_LIMIT) {
        failed = true;
        LOG_ERROR("Invalid port value, at:\n\t%s", port.c_str());
        return;
    }
    server_conf.port = port;
    if (std::count(host.begin(), host.end(), '.') == 3 && host.find_first_not_of("0123456789.") == std::string::npos)
        server_conf.host = host;
    else if (host == "localhost")
        server_conf.host = "127.0.0.1";
    else if (host == "")
        server_conf.host = DEFAULT_HOST;
    else {
        failed = true;
        LOG_ERROR("Invalid host value, at line %lu:\n\t%s", line_cnt, host.c_str());
        return;
    }
}

void config_parser::parse_server_name_field(server_config &server_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 1) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'server_name' is incorrect");
        LOG_INFO("Valid syntax: 'server_name <name>;'");
        return;
    }
    server_conf.server_name = tokens[0];
}

void config_parser::parse_root_field(server_config &server_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 1) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'root' is incorrect");
        LOG_INFO("Valid syntax: 'root <path>;'");
        return;
    }
    server_conf.root = tokens[0];
}

std::string parse_full_file(std::ifstream &ifs) {
    ASSERT(ifs.is_open());
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}

void config_parser::parse_error_page_field(server_config &server_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 2) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'error_page' is incorrect");
        LOG_INFO("Valid syntax: 'error_page <code> <uri>;'");
        return;
    }
    if (!utils::is_numeric(tokens[0])) {
        failed = true;
        LOG_ERROR("Invalid error_page code, at line %lu:\n\t%s", line_cnt, tokens[0].c_str());
        return;
    }
    std::size_t code = std::stoul(tokens[0]);
    const std::string &uri = tokens[1];
    server_conf.error_pages[code] = uri;
}

void config_parser::parse_client_max_body_size_field(server_config &server_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 1) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'client_max_body_size' is incorrect");
        LOG_INFO("Valid syntax: 'client_max_body_size <size>;'");
        return;
    }
    if (!utils::is_numeric(tokens[0])) {
        failed = true;
        LOG_ERROR("Invalid client_max_body_size value, at line %lu:\n\t%s", line_cnt, tokens[0].c_str());
        return;
    }
    server_conf.client_max_body_size = std::stoul(tokens[0]);
}

void config_parser::parse_location_autoindex_field(location_config &location_conf, const std::string &field_val) {
    if (field_val == "on" || field_val == "off") {
        location_conf.autoindex = (field_val == "on");
    } else {
        failed = true;
        LOG_ERROR("Invalid autoindex value, at line %lu:\n\t%s", line_cnt, field_val.c_str());
        LOG_INFO("Valid syntax: 'autoindex on|off;'");
        return;
    }
}

void config_parser::parse_location_root_field(location_config &location_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 1) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'root' is incorrect");
        LOG_INFO("Valid syntax: 'root <path>;'");
        return;
    }
    if (!utils::valid_directory(tokens[0])) {
        failed = true;
        log_pretty_err("Invalid value: cannot parse on directory");
        return;
    }
    location_conf.root = tokens[0];
}

void config_parser::parse_location_index_field(location_config &location_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 1) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'index' is incorrect");
        LOG_INFO("Valid syntax: 'index <file>;'");
        return;
    }
    location_conf.index = tokens[0];
}

void config_parser::parse_location_allow_methods_field(location_config &location_conf, const std::string &field_val) {
    std::vector<std::string> tokens;
    const std::vector<std::string> &tmp1 = utils::split(field_val, ",");
    if (tmp1.size() == 0) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'allow_methods' is incorrect");
        LOG_INFO("Valid syntax: 'allow_methods <method>[,method...];'");
        return;
    }
    for (std::size_t i = 0; i < tmp1.size(); i++) {
        const std::vector<std::string> &tmp = utils::split(tmp1[i], " ");
        for (std::size_t j = 0; j < tmp.size(); j++) tokens.push_back(tmp[j]);
    }
    for (std::size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "GET" || tokens[i] == "POST" || tokens[i] == "DELETE")
            location_conf.allowed_methods.insert(tokens[i]);
        else {
            failed = true;
            LOG_ERROR("Invalid method, at line %lu:\n\t%s", line_cnt, tokens[i].c_str());
            LOG_INFO("Valid methods: GET, POST, DELETE");
            return;
        }
    }
}

void config_parser::parse_location_return_field(location_config &location_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 2) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'return' is incorrect");
        LOG_INFO("Valid syntax: 'return <code> <url>;'");
        return;
    }
    std::size_t code = std::stoul(tokens[0]);
    if (code < 300 || code > 399 || !utils::is_numeric(tokens[0]) ||
        webserv::http_mapper.status_code.find(code) == webserv::http_mapper.status_code.end()) {
        failed = true;
        LOG_ERROR("Invalid return code, at line %lu:\n\t%s", line_cnt, tokens[0].c_str());
        LOG_INFO("Valid codes: 3xx");
        return;
    }
    const std::string &url = tokens[1];
    location_conf.redirection = std::make_pair(code, url);
}

void config_parser::parse_fastcgi_pass_field(location_config &location_conf, const std::string &field_val) {
    const std::vector<std::string> &tokens = utils::split(field_val, " ");
    if (tokens.size() != 1) {
        failed = true;
        log_pretty_err("Invalid syntax: value for 'fastcgi_pass' is incorrect");
        LOG_INFO("Valid syntax: 'fastcgi_pass <address>;'");
        return;
    }
    location_conf.fastcgi_addr = tokens[0];
}

const config_parser::option_parser_map config_parser::option_parser_mapper;

config_parser::option_parser_map::option_parser_map() : options(), location_options() {
    options["listen"] = &config_parser::parse_listen_field;
    options["server_name"] = &config_parser::parse_server_name_field;
    options["root"] = &config_parser::parse_root_field;
    options["error_page"] = &config_parser::parse_error_page_field;
    options["client_max_body_size"] = &config_parser::parse_client_max_body_size_field;

    location_options["autoindex"] = &config_parser::parse_location_autoindex_field;
    location_options["root"] = &config_parser::parse_location_root_field;
    location_options["index"] = &config_parser::parse_location_index_field;
    location_options["allow_methods"] = &config_parser::parse_location_allow_methods_field;
    location_options["return"] = &config_parser::parse_location_return_field;
    location_options["fastcgi_pass"] = &config_parser::parse_fastcgi_pass_field;
}

config_parser::option_parser_map::~option_parser_map() {}

bool config_parser::option_parser_map::contains(const std::string &option) const {
    return options.find(option) != options.end();
}

bool config_parser::option_parser_map::location_contains(const std::string &location_option) const {
    return location_options.find(location_option) != location_options.end();
}
