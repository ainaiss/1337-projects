#include "config_parser.hpp"

config_parser::config_parser(const char *config_path)
    : failed(false), ifs(config_path, std::fstream::in), line(), token(), line_cnt(0), pos(std::string::npos) {
    if (ifs.is_open())
        parse_config_file();
    else {
        failed = true;
        LOG_ERROR("%s", "Cannot open configuration file");
        LOG_ERRNO;
    }
}

config_parser::~config_parser() { ifs.close(); }

bool config_parser::has_failed() const { return failed; }

const std::vector<server_config> &config_parser::get_server_configs() const {
    for (std::vector<server_config>::const_iterator it = server_configs.begin(); it != server_configs.end(); ++it) {
        LOG_DEBUG("%s", it->to_string().c_str());
    }
    return server_configs;
}

void config_parser::parse_config_file() {
    while (!failed) {
        get_next_token();
        if (failed) {  // eof
            failed = false;
            break;
        }
        if (token_prefix("server")) {
            parse_server_block();
            if (failed) break;
        } else {
            failed = true;
            log_pretty_err("Invalid syntax: Expected a `server` block");
        }
    }
}

static bool field_name_is_valid(const std::string &field_name) {
    if (field_name.size() == 0) return false;
    char c = field_name[0];
    if (!std::isalpha(c) && c != '_') return false;
    for (std::size_t i = 1; i < field_name.size(); i++) {
        if (!std::isalnum(field_name[i]) && field_name[i] != '_') return false;
    }
    return true;
}

void config_parser::parse_server_block() {
    server_config server_conf;
    get_next_token();
    if (!token_prefix("{")) {
        failed = true;
        log_pretty_err("Invalid syntax: Expected '{'");
        return;
    }
    while (!failed) {
        get_next_token();
        if (failed) {
            line_cnt++;
            log_pretty_err("Invalid syntax: Expected '}'");
            return;
        }
        if (token[0] == '}') break;
        if (token_prefix(";")) {
            failed = true;
            log_pretty_err("Invalid syntax: Unexpected ';' found");
            return;
        }
        if (!field_name_is_valid(token)) {
            failed = true;
            std::string err_msg = "Invalid syntax: '" + token + "' is an invalid field name";
            log_pretty_err(err_msg.c_str());
            return;
        }
        if (token == "location") {
            parse_location_block(server_conf);
            continue;
        }
        std::size_t val_begin = line.find_first_not_of(WHITESPACE_CHARS, pos);
        std::size_t val_end = line.find_first_of(';', val_begin);
        if (val_begin == std::string::npos || val_begin == val_end) {
            failed = true;
            const std::string &err_msg = "Invalid syntax: value for '" + token + "' was not provided";
            log_pretty_err(err_msg.c_str());
            LOG_INFO("Valid syntax: '<field name> <field value> [field values];'");
            return;
        }
        if (val_end == std::string::npos) {
            failed = true;
            token = ";";  // hacking log_pretty_err
            log_pretty_err("Invalid syntax: Expected ';'");
            return;
        }
        const std::string &field_val = line.substr(val_begin, val_end - val_begin);
        // `field_value` is alparsey trimmed from the left
        const std::string &trimmed = field_val.substr(0, field_val.find_last_not_of(WHITESPACE_CHARS) + 1);
        pos = val_end + 1;
        if (option_parser_mapper.contains(token))
            (this->*(option_parser_mapper.options.find(token)->second))(server_conf, trimmed);
        else
            LOG_INFO("Option %s is unsupported. Its configuration was ignored!", token.c_str());
    }
    if (server_conf.root[server_conf.root.size() - 1] != '/') server_conf.root += '/';
    for (std::map<std::size_t, std::string>::iterator it = server_conf.error_pages.begin();
         it != server_conf.error_pages.end(); ++it) {
        if (it->second[0] == '/') it->second = it->second.substr(1);
        std::ifstream ifs((server_conf.root + it->second).c_str());
        if (!ifs.is_open()) {
            failed = true;
            LOG_ERROR("Error page %s for error code %lu was not found!", it->second.c_str(), it->first);
            return;
        }
        std::stringstream ss;
        ss << ifs.rdbuf();
        const std::string &content = ss.str();
        ifs.close();
        server_conf.error_pages[it->first] = content;
    }
    for (std::vector<location_config>::const_iterator it = server_conf.location_configs.begin();
         it != server_conf.location_configs.end(); ++it) {
        if (it->uri[0] == '*') server_conf.supported_fastcgi_exts.insert(utils::get_extension(it->uri));
    }
    if (failed) return;
    if (server_conf.location_configs.size() == 0) server_conf.location_configs.push_back(location_config());
    if (token_prefix("}")) server_configs.push_back(server_conf);
}

static bool is_valid_location_uri(const std::string &uri) {
    if (uri.size() == 0) return false;
    if (uri[0] == '*') {
        if (uri.size() <= 2 || uri.find_last_of(".") != 1) return false;
        return true;
    } else if (uri[0] != '/')
        return false;
    return true;
}

void config_parser::parse_location_block(server_config &server_conf) {
    location_config location_conf;
    get_next_token();
    if (failed) {
        log_pretty_err("Invalid syntax: Expected location's uri");
        return;
    }
    location_conf.uri = token;
    if (!is_valid_location_uri(location_conf.uri)) {
        failed = true;
        log_pretty_err("Invalid syntax: Location's uri is invalid");
        LOG_INFO("Valid syntax: '/' or '/<file name>' or '/<file name>.<file extension>' or '*.<file extension>'");
        return;
    }
    get_next_token();
    if (!token_prefix("{")) {
        failed = true;
        log_pretty_err("Invalid syntax: Expected '{'");
        return;
    }
    while (!failed) {
        get_next_token();
        if (failed) {
            line_cnt++;
            log_pretty_err("Invalid syntax: Expected '}'");
            return;
        }
        if (token[0] == '}') break;
        if (token_prefix(";")) {
            failed = true;
            log_pretty_err("Invalid syntax: Unexpected ';' found");
            return;
        }
        if (!field_name_is_valid(token)) {
            failed = true;
            std::string err_msg = "Invalid syntax: '" + token + "' is an invalid field name";
            log_pretty_err(err_msg.c_str());
            return;
        }
        std::size_t val_begin = line.find_first_not_of(WHITESPACE_CHARS, pos);
        std::size_t val_end = line.find_first_of(';', val_begin);
        if (val_begin == std::string::npos || val_begin == val_end) {
            failed = true;
            const std::string &err_msg = "Invalid syntax: value for '" + token + "' was not provided";
            log_pretty_err(err_msg.c_str());
            LOG_INFO("Valid syntax: '<field name> <field value> [field values];'");
            return;
        }
        if (val_end == std::string::npos) {
            failed = true;
            token = ";";  // hacking log_pretty_err
            log_pretty_err("Invalid syntax: Expected ';'");
            return;
        }
        const std::string &field_val = line.substr(val_begin, val_end - val_begin);
        // `field_value` is alparsey trimmed from the left
        const std::string &trimmed = field_val.substr(0, field_val.find_last_not_of(WHITESPACE_CHARS) + 1);
        pos = val_end + 1;
        if (option_parser_mapper.location_contains(token))
            (this->*(option_parser_mapper.location_options.find(token)->second))(location_conf, trimmed);
        else
            LOG_INFO("Option %s is unsupported. Its configuration was ignored!", token.c_str());
    }
    if (failed) return;
    if (token_prefix("}")) server_conf.location_configs.push_back(location_conf);
}

// parse the next valid line from `ifs` and put it in `line`
// (A valid line is non-empty and not a comment)
// If no valid line is found, `failed` is set to `true`
const std::string &config_parser::get_next_line() {
    ASSERT(failed == false);
    while (std::getline(ifs, line)) {
        line_cnt++;
        pos = 0;
        std::size_t first_non_whitespace_pos = line.find_first_not_of(WHITESPACE_CHARS, pos);
        std::size_t first_sharp_pos = line.find_first_of('#', pos);
        if (first_non_whitespace_pos != std::string::npos && first_non_whitespace_pos != first_sharp_pos) {
            line = line.substr(first_non_whitespace_pos, first_sharp_pos - first_non_whitespace_pos);
            return line;
        }
    }
    failed = true;
    line = "";
    return line;
}

// parse the next token in `line` starting from `pos` and put it in `token`
// If no token is found, `failed` is set to `true`
const std::string &config_parser::get_next_token() {
    ASSERT(failed == false);
    while (!failed && no_token_left()) get_next_line();
    if (failed) {
        token = "";
        return token;
    }
    std::size_t begin = line.find_first_not_of(WHITESPACE_CHARS, pos);
    std::size_t end = line.find_first_of(WHITESPACE_CHARS, begin);
    pos = end;
    token = line.substr(begin, end - begin);
    return token;
}

// Checks whether a token is to be found in `line` starting from `pos`
bool config_parser::no_token_left() const {
    ASSERT(failed == false);
    return line.find_first_not_of(WHITESPACE_CHARS, pos) == std::string::npos;
}

// Returns `true` if `token` starts with `prefix`
// If so, `token` will be set to the calue of `prefix`
// Else it won't change value
// `pos` is altered accordinaly
bool config_parser::token_prefix(const std::string &prefix) {
    ASSERT(failed == false);
    if (token.find(prefix) == 0) {
        pos = line.rfind(token, pos);
        token = prefix;
        pos += token.size();
        return true;
    }
    return false;
}

static std::size_t size_t_len(std::size_t num) {
    std::size_t len = 0;
    do {
        len++;
        num /= 10;
    } while (num);
    return len;
}

void config_parser::log_pretty_err(const char *err_msg) const {
    std::size_t begin = line.rfind(token, pos);
    // hacky way to handle ';' (we set token to ';' and we are sure it won't be
    // found)
    if (begin == std::string::npos) begin = line.size();
    std::string skip(std::string("line : ").size() + size_t_len(line_cnt) + begin, ' ');
    LOG_ERROR("%s, at:\n\tline %zu: %s\n\t%s^", err_msg, line_cnt, line.c_str(), skip.c_str());
}
