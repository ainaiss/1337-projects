FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get install nginx -y

RUN apt-get install wget -y
RUN apt-get install openssl -y
RUN apt-get install mariadb-server -y

RUN apt-get install php-mbstring php-zip php-gd php-xml php-pear php-gettext php-cli php-cgi -y
RUN apt-get install php-mysql -y
RUN apt-get install php7.3-fpm -y

RUN mkdir -p /var/www/fts

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=MA/ST=Khouribga/L=Khouribga/O=Organisation_NAME/CN=SERVER_NAME"

COPY srcs /tmp

RUN bash /tmp/phpmyadmin_n_wordpress_setup.sh

RUN mv /tmp/default /etc/nginx/sites-available/default

RUN mv /var/www/html/index.nginx-debian.html /var/www/fts/index.nginx-debian.html

RUN bash /tmp/database_setup.sh

CMD bash /tmp/init.sh