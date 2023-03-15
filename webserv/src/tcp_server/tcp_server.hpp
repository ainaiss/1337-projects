#ifndef _TCP_SERVER_HPP_
#define _TCP_SERVER_HPP_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>

#include "../utilities/logger.hpp"
#include "server_config.hpp"

static const int DEFAULT_BACKLOG = -1;

class tcp_server {
   public:
    tcp_server(const server_config &config);
    ~tcp_server();

    bool has_failed() const;
    void turn_on();

   public:
    server_config config;
    int sockfd;

   private:
    bool failed;

};  // class tcp_server

#endif  // _TCP_SERVER_HPP_
