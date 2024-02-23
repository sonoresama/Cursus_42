all : up

up :
	sudo mkdir -p /home/eorer/data/mariadb_vol
	sudo mkdir -p /home/eorer/data/wordpress_vol
	docker-compose -f ./srcs/docker-compose.yml up -d --build
down : 
	docker-compose -f ./srcs/docker-compose.yml down
	docker system prune -a
#	sudo /bin/rm -rf /home/eorer/data/mariadb_vol
#	sudo /bin/rm -rf /home/eorer/data/wordpress_vol

stop : 
	docker-compose -f ./srcs/docker-compose.yml stop

start : 
	docker-compose -f ./srcs/docker-compose.yml start

re: down up
