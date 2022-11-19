# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:28:44 by eorer             #+#    #+#              #
#    Updated: 2022/11/19 12:56:28 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -include ft_printf.h libft/libft.h


DIR = $(shell dirname $(shell pwd))

LIBFT_PATH = $(DIR)/libft

SRC = ft_format.c ft_functions_2.c ft_functions.c ft_printf.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	cp libft/libft.a ./
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(INCLUDE) $(SRC)
	ar -rcs $(NAME) $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME) libft.a

clean :
	make clean -C libft
	rm -rf $(OBJ)

re : fclean all
