# # Infinite Mario Game on Nginx

# From debian:latest


# EXPOSE 80

# RUN apt-get update -y
# RUN apt-get upgrade -y
# RUN apt-get install -y vim
# RUN apt-get install -y nginx

# WORKDIR /var/www
# CMD rm -rf html

# COPY html /var/www/html

# ENTRYPOINT /bin/bash

# # To build it
# # docker build -t b04 .

# # To run it
# docker run -it -p 8004:80 b04




FROM alpine:latest
RUN apk update
RUN apk add apache2 openrc git
RUN openrc
RUN touch /run/openrc/softlevel

# Copy website 
ADD ./tools/htdocs /var/www/localhost/htdocs/.

COPY ./tools/script.sh /
RUN chmod +x /script.sh
ENTRYPOINT ["/script.sh"]