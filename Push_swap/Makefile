# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:59:35 by eorer             #+#    #+#              #
#    Updated: 2022/12/12 17:22:52 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h \
	 ftprintf/ft_printf.h \
	 ftprintf/libft/libft.h

NAME = push_swap

SRC = ./push_swap.c \
      ./utils/inst_push.c \
      ./utils/inst_rev_rotate.c \
      ./utils/inst_rotate.c \
      ./utils/inst_swap.c \
      ./utils/utilities.c \
      ./sort_algo/sort_insertion.c \
      ./sort_algo/sort_three_digit.c

LIB = libftprintf.a


all : $(NAME)

$(NAME) : $(HEADER) $(LIB) $(SRC)
	@$(CC) $(CFLAGS) -include $(HEADER) $(SRC) $(LIB) -o $(NAME)

$(LIB) :
	@make -C ./ftprintf
	@cp ftprintf/$(LIB) ./

fclean : clean
	@make fclean -C ./ftprintf
	@rm -rf $(NAME)

clean : 
	@make clean -C ./ftprintf

compile :
	@rm -rf $(NAME)
	@make

re: fclean all
