#include "../webserv/webserv.hpp"

webserv::request_parser::request_parser()
    : failed(0),
      server_fd(-1),
      client_fd(-1),
      method(),
      url(),
      http_version(),
      body(),
      headers(),
      response(),
      bytes_sent(std::string::npos) {}

webserv::request_parser::~request_parser() {}

bool webserv::request_parser::has_failed() const { return failed != 0; }

static std::string http_url_decoder(const std::string &url) {
    std::string result;
    result.reserve(url.size());
    for (size_t i = 0; i < url.size(); ++i) {
        if (url[i] == '%') {
            if (i + 3 <= url.size()) {
                int value = 0;
                std::istringstream is(url.substr(i + 1, 2));
                if (is >> std::hex >> value) {
                    result += static_cast<char>(value);
                    i += 2;
                } else {
                    return "";
                }
            } else {
                return "";
            }
        } else if (url[i] == '+') {
            result += ' ';
        } else {
            result += url[i];
        }
    }
    return result;
}

void webserv::request_parser::parse_headers() {
    if (http_version.size() > 0) return;  // request header was alparsey parse
    std::size_t header_end = body.find(DOUBLE_CRLF);
    if (header_end == std::string::npos) {
        failed = 400;
        LOG_INFO("Server received a request with a too large header");
        return;
    }
    const std::string &header = body.substr(0, header_end);
    body = body.erase(0, header_end + 4);

    const std::vector<std::string> &tokens = utils::split(header, CRLF);
    std::stringstream ss(tokens[0]);
    std::string check_format;
    ss >> method >> url >> http_version >> check_format;
    if (http_version != "HTTP/1.1") {
        failed = 505;
        LOG_INFO("Server received a request with an unsupported HTTP version");
        return;
    }
    if (url.size() > MAX_URL_LENGTH) {
        failed = 414;
        LOG_INFO("Server received a request with a request-URI that is too long");
        return;
    }
    url = http_url_decoder(url);
    if (method.size() == 0 || url.size() == 0 || http_version.size() == 0 || check_format.size() != 0) {
        failed = 400;
        LOG_INFO("Server received a request with malformed syntax");
        return;
    }
    for (std::size_t i = 1; i < tokens.size(); i++) {
        const std::string &line = tokens[i];
        std::size_t dp_pos = line.find_first_of(":");
        if (dp_pos == std::string::npos) {
            failed = 400;
            LOG_INFO("Server received a request with malformed syntax");
            return;
        }
        const std::string &key = line.substr(0, dp_pos);
        const std::string &value = line.substr(line.find_first_not_of(' ', dp_pos + 1));
        headers.insert(std::make_pair(key, value));
    }
}

std::string webserv::request_parser::to_string() const {
    std::stringstream ss;
    ss << "method: " << method << std::endl;
    ss << "url: " << url << std::endl;
    ss << "http_version: " << http_version << std::endl;
    ss << "body: " << body << std::endl;
    ss << "headers: " << std::endl;
    for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); it++) {
        ss << it->first << ": " << it->second << std::endl;
    }
    return ss.str();
}
