# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:15:01 by eorer             #+#    #+#              #
#    Updated: 2023/03/01 14:44:12 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a

INCLUDE = -I./include

HEADERS = ./include/pipex.h

NAME = pipex

SRC = $(addprefix ./src/, main.c utilities.c parsing.c check_args.c set_argv.c cmd_in.c cmd_out.c)

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIB) :
	@make -C ./libft
	
clean :
	@make clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean : clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re : fclean all
