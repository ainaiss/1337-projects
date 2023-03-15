#include "response_generator.hpp"

std::string http_post(tcp_server *server, webserv::request_parser *request_prsr,
                                    location_config *location_conf) {
    if (location_conf->root[location_conf->root.size() - 1] != '/') location_conf->root += '/';
    std::string url = request_prsr->url.substr(location_conf->uri.size());
    if (url[0] == '/') url = url.substr(1);
    if (location_conf->root[location_conf->root.size() - 1] != '/') location_conf->root += '/';
    const std::string &full_path = location_conf->root + url;
    if (utils::is_directory(full_path)) {
        if (request_prsr->headers.find("Content-Type") == request_prsr->headers.end())
            return get_status_page(server, 400);
        const std::string &content_type = request_prsr->headers.at("Content-Type");
        if (content_type.find("multipart/form-data") != std::string::npos) {
            LOG_DEBUG("REQUEST: %s", request_prsr->body.c_str());
            const std::string &boundary = content_type.substr(content_type.find("boundary=") + 9);
            if (boundary.size() == 0) return get_status_page(server, 400);
            const std::vector<std::string> &body_parts = utils::split(request_prsr->body, "--" + boundary);
            if (body_parts[body_parts.size() - 1].find("--") != 0) get_status_page(server, 400);
            for (std::size_t i = 0; i < body_parts.size() - 1; i++) {
                const std::vector<std::string> &header_content = utils::split(body_parts[i], DOUBLE_CRLF);
                if (header_content.size() != 2) return get_status_page(server, 400);
                const std::string &header = header_content[0];
                const std::string &content = header_content[1];
                std::string filename;
                const std::vector<std::string> &header_lines = utils::split(header, CRLF);
                for (std::size_t i = 0; i < header_lines.size(); i++) {
                    std::size_t filename_begin = header_lines[i].find("filename=\"");
                    if (filename_begin != std::string::npos) {
                        std::size_t filename_end = header_lines[i].find("\"", filename_begin + 10);
                        LOG_DEBUG("DIFF: %lu", filename_end - filename_begin - 10);
                        filename = header_lines[i].substr(filename_begin + 10, filename_end - filename_begin - 10);
                        break;
                    }
                }
                LOG_DEBUG("FILENAME: %s", filename.c_str());
                LOG_DEBUG("CONTENT: %s", content.c_str());
                if (filename.size() == 0) return get_status_page(server, 400);
                LOG_DEBUG("file %s", (full_path + filename).c_str());
                std::ofstream ofs((full_path + filename).c_str(), std::ios::out | std::ios::trunc);
                if (!ofs.is_open()) {
                    LOG_ERRNO;
                    return get_status_page(server, 500);
                }
                LOG_DEBUG("Content: %s", content.c_str());
                ofs << content;
                ofs.close();
            }
        }
        return get_status_page(server, 201);
    }
    return get_status_page(server, 403);
}
