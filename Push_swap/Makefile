# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:59:35 by eorer             #+#    #+#              #
#    Updated: 2022/12/07 18:45:52 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h \
	 ftprintf/ft_printf.h \
	 ftprintf/libft/libft.h

NAME = push_swap.out

SRC = *.c

LIB = libftprintf.a


all : $(NAME)

$(NAME) : $(HEADER) $(LIB)
	@$(CC) $(CFLAGS) -include $(HEADER) $(SRC) $(LIB) -o $(NAME)

$(LIB) :
	@make -C ./ftprintf
	@cp ftprintf/$(LIB) ./

fclean : clean
	@make clean -C ./ftprintf
	@rm -rf $(NAME) $(LIB)

clean : 
	@make clean -C ./ftprintf

compile :
	@rm -rf $(NAME)
	@make

re: fclean all
