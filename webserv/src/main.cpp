#include "./webserv/webserv.hpp"

int main(int ac, char **av) {
    if (ac <= 2) {
        const char *config_path = (ac == 2 ? av[1] : DEFAULT_CONFIG_PATH);
        webserv websrv(config_path);
        if (websrv.has_failed()) return EXIT_FAILURE;
        websrv.serve_forever();
    } else {
        std::cerr << "Usage: " << av[0] << " [configuration file]" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
