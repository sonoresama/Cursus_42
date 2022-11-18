# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:28:44 by eorer             #+#    #+#              #
#    Updated: 2022/11/18 12:32:24 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -include libftprintf.h ../libft.h

SRC = *.c

DIR = $(shell dirname $(shell pwd))

LIBFT_PATH = $(DIR)



all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_PATH) -lft $(INCLUDE) && ./a.out

c :
	rm -f a.out

fclean : clean
	make fclean -C libft

clean :
	make clean -C libft

re : c all
