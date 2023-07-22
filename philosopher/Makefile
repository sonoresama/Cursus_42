# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 15:16:00 by eorer             #+#    #+#              #
#    Updated: 2023/04/13 17:04:51 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = $(INCLUDE) -Wall -Wextra -Werror

LFLAGS = -lpthread

INCLUDE = -I./include

HEADER = ./include/philosophers.h

SRC = main.c utilities.c

OBJ = $(SRC:.c=.o)

NAME = philo


all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@echo "linking..."
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
