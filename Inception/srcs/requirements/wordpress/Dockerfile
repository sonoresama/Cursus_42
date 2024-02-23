FROM debian:bullseye

RUN apt update -y
RUN apt upgrade -y
RUN apt-get install vim wget php7.4 php-fpm php-mysql curl mariadb-client -y

COPY tools/script.sh /usr/local/bin/script.sh

RUN  chmod +x /usr/local/bin/script.sh

#RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
#RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN wget https://wordpress.org/latest.tar.gz -P /var/www
RUN cd /var/www && tar -xzf latest.tar.gz && rm latest.tar.gz
RUN chown -R root:root /var/www/wordpress

WORKDIR /var/www/wordpress
ENTRYPOINT [ "/usr/local/bin/script.sh" ]
 
EXPOSE 9000
