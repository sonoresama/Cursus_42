# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 01:58:18 by eorer             #+#    #+#              #
#    Updated: 2023/03/26 03:05:12 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c get_next_line.c get_next_line_utils.c

NAME = test


all : $(NAME)

$(NAME) :
	@$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean : 
	rm *.o

fclean : clean
	rm $(NAME)

re : fclean all
