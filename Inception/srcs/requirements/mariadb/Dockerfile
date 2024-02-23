FROM debian:bullseye

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt update -y
RUN apt upgrade -y
RUN apt-get install mariadb-server -y

COPY conf/mariadb.conf	/etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/mariadb.sh /mariadb.sh

RUN chmod +x mariadb.sh

ENTRYPOINT [ "./mariadb.sh"]

EXPOSE 3306
