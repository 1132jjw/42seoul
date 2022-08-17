#!/bin/bash

service nginx start
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
cp ./tmp/default etc/nginx/sites-available/default
service php7.3-fpm start

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
cp ./tmp/config.inc.php var/www/html/phpmyadmin/config.inc.php

service nginx reload
service mysql start
service php7.3-fpm restart
mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysqladmin -u root -p password
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' IDENTIFIED BY '1111' WITH GRANT OPTION;" | mysql
echo "FLUSH PRIVILEGES;" | mysql

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp ./tmp/wp-config.php var/www/html/wordpress/wp-config.php
service nginx reload

bash