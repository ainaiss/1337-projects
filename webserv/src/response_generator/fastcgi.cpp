#include "response_generator.hpp"

std::string get_fastcgi_page(tcp_server *server, const std::string &full_path) {
    const std::string &cgi_path = "*." + utils::get_extension(full_path);
    location_config *location_conf = NULL;
    for (std::size_t i = 0; i < server->config.location_configs.size(); i++) {
        if (server->config.location_configs[i].uri == cgi_path) {
            location_conf = &server->config.location_configs[i];
            break;
        }
    }
    if (location_conf == NULL || access(full_path.c_str(), F_OK) != 0) return get_status_page(server, 404);
    if (access(full_path.c_str(), R_OK) == -1 || utils::is_directory(full_path))
        return get_status_page(server, 403);
    std::ifstream ifs(full_path.c_str(), std::ios::in);
    if (!ifs.is_open()) {
        LOG_ERRNO;
        return get_status_page(server, 404);
    }
    std::stringstream ss;
    ss << ifs.rdbuf();
    ifs.close();
    const std::string &file_content = ss.str();
    int in[2], out[2];
    pid_t pid;
    if (pipe(in) == -1 || pipe(out) == -1 || (pid = fork()) == -1) {
        LOG_ERRNO;
        return get_status_page(server, 500);
    }
    std::stringstream body_ss;
    if (pid == 0) {
        dup2(in[0], STDIN_FILENO);
        dup2(out[1], STDOUT_FILENO);
        close(in[0]);
        close(in[1]);
        close(out[0]);
        close(out[1]);
        const char *argv[] = {const_cast<char *>(location_conf->fastcgi_addr.c_str()),
                              const_cast<char *>(full_path.c_str()), NULL};
        execve(argv[0], const_cast<char **>(argv), NULL);
    } else {
        char buf[1024];
        close(in[0]);
        close(out[1]);
        write(in[1], file_content.c_str(), file_content.size());
        close(in[1]);
        int ret;
        while ((ret = read(out[0], buf, 1023)) > 0) {
            buf[ret] = '\0';
            body_ss << buf;
        }
        close(out[0]);
        waitpid(pid, NULL, 0);
    }
    const std::string &body = body_ss.str();
    std::stringstream response;
    response << "HTTP/1.1 200 OK" << CRLF;
    response << "Content-Type: text/html" << CRLF;
    response << "Content-Length: " << body.size() << CRLF;
    response << CRLF;
    response << body;
    return response.str();
}
