# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:28:44 by eorer             #+#    #+#              #
#    Updated: 2022/12/13 11:59:14 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADERS = ft_printf.h libft_og/libft.h


DIR = $(shell dirname $(shell pwd))

LIBFT_PATH = $(DIR)/libft

SRC = ft_hexa.c ft_functions.c ft_printf.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@make -C ./libft_og
	@cp libft_og/libft_og.a ./
	@mv libft_og.a $(NAME)
	@$(CC) $(CFLAGS) -include $(HEADERS) -c $(SRC)
	@ar -rcs $(NAME) $(OBJ)

fclean : clean
	@make fclean -C libft_og
	@rm -rf $(NAME) libft_og.a

clean :
	@make clean -C libft_og
	@rm -rf $(OBJ)

re : fclean all
