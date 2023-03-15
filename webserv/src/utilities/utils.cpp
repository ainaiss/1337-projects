#include "utils.hpp"

std::vector<std::string> utils::split(const std::string &str, const std::string &delim) {
    std::vector<std::string> tokens;
    std::size_t pos_begin = 0;
    while (true) {
        std::size_t pos_end = str.find(delim, pos_begin);
        const std::string &token = str.substr(pos_begin, pos_end - pos_begin);
        if (token.size() > 0) tokens.push_back(token);
        if (pos_end == std::string::npos) break;
        pos_begin = pos_end + delim.size();
    }
    return tokens;
}

bool utils::is_numeric(const std::string &str) {
    for (std::size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

bool utils::valid_directory(const std::string &path) { return ::access(path.c_str(), R_OK) == 0; }

bool utils::valid_file(const std::string &path) {
    std::ifstream ifs(path);
    return ifs.good();
}

std::string utils::parse_full_file(const std::string &path) {
    std::ifstream ifs(path);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}

std::string utils::get_extension(const std::string &path) {
    std::size_t pos = path.find_last_of('.');
    if (pos == std::string::npos) {
        return "";
    }
    return path.substr(pos + 1);
}

bool utils::is_directory(const std::string &path) {
    struct stat statbuf;
    if (stat(path.c_str(), &statbuf) != 0) {
        return false;
    }
    return S_ISDIR(statbuf.st_mode);
}
