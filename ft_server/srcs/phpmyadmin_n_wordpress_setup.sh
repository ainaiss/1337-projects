cd /var/www/fts/
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.3/phpMyAdmin-4.9.3-english.tar.gz
tar -xf phpMyAdmin-4.9.3-english.tar.gz
mv phpMyAdmin-4.9.3-english phpmyadmin
mv /tmp/config.inc.php /var/www/fts/phpmyadmin/config.inc.php

wget https://wordpress.org/latest.tar.gz
tar -xf latest.tar.gz -o wordpress
mv /tmp/wp-config.php /var/www/fts/wordpress/wp-config.php
chown -R www-data:www-data /var/www/fts