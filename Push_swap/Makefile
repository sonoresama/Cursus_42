# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:59:35 by eorer             #+#    #+#              #
#    Updated: 2022/12/13 18:02:11 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h \
	 libft/ft_printf.h \
	 libft/libft_og/libft.h

NAME = push_swap

SRC = ./push_swap.c \
      ./utils/inst_push.c \
      ./utils/inst_rev_rotate.c \
      ./utils/inst_rotate.c \
      ./utils/inst_swap.c \
      ./utils/utilities.c \
      ./sort_algo/sort_insertion.c \
      ./sort_algo/sort_three_digit.c \
      ./sort_algo/sort_quick.c \

LIB = libft.a


all : $(NAME)

$(NAME) : $(HEADER) $(LIB) $(SRC)
	@$(CC) $(CFLAGS) -include $(HEADER) $(SRC) $(LIB) -o $(NAME)

$(LIB) :
	@make -C ./libft
	@cp libft/$(LIB) ./

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME) $(LIB)

clean : 
	@make clean -C ./libft

re: fclean all
