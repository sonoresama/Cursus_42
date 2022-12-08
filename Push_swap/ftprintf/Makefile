# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:28:44 by eorer             #+#    #+#              #
#    Updated: 2022/12/07 18:21:10 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -include ft_printf.h libft/libft.h

HEADER = ft_printf.h

DIR = $(shell dirname $(shell pwd))

LIBFT_PATH = $(DIR)/libft

SRC = ft_hexa.c ft_functions.c ft_printf.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@make -C ./libft
	@cp libft/libft.a ./
	@mv libft.a $(NAME)
	@$(CC) $(CFLAGS) -c $(INCLUDE) $(SRC)
	@ar -rcs $(NAME) $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME) libft.a

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

re : fclean all
