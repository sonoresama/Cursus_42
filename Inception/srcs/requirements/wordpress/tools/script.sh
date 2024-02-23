#!/bin/bash

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar  && chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

sleep 5

if [ -e ./wp-config.php ]; then
	echo PHP config already exists
else
	mv wp-config-sample.php wp-config.php
fi

sed -i -r "s/database_name_here/$SQL_DATABASE/1"   wp-config.php
sed -i -r "s/username_here/$SQL_USER/1"  wp-config.php
sed -i -r "s/password_here/$SQL_PASSWORD/1"    wp-config.php
sed -i -r "s/localhost/mariadb:3306/1"    wp-config.php 

wp core install --url=$DOMAIN_NAME/ --title=$WEBSITE_TITLE --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --skip-email --allow-root
wp user create $WP_USER $WP_MAIL --role=author --user_pass=$WP_PASSWORD --allow-root

wp theme install astra --activate --allow-root

sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf
sed -i 's/;clear_env = no/clear_env = no/g' /etc/php/7.4/fpm/pool.d/www.conf

mkdir /run/php

/usr/sbin/php-fpm7.4 -F
