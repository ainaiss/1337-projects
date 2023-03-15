#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "../webserv/webserv.hpp"

namespace utils {
std::vector<std::string> split(const std::string &str, const std::string &delim);
bool is_numeric(const std::string &str);
bool valid_directory(const std::string &path);
bool valid_file(const std::string &path);
std::string parse_full_file(const std::string &file_path);
std::string get_extension(const std::string &path);
bool is_directory(const std::string &path);

};  // namespace utils

#endif  // _UTILS_HPP_
