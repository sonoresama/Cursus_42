FROM debian:bullseye

RUN apt update -y
RUN apt upgrade -y
RUN apt-get install nginx -y
RUN apt-get install vim -y 
RUN apt-get install curl -y 
RUN apt install openssl -y

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -newkey rsa:4096 -days 365 \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42 School/OU=mdarbois/CN=mdarbois/"

RUN mkdir -p /var/run/nginx
COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

CMD [ "nginx", "-g", "daemon off;" ]
