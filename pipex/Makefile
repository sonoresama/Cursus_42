# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:15:01 by eorer             #+#    #+#              #
#    Updated: 2023/03/31 15:10:07 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a

INCLUDE = -I./include

HEADERS = ./include/pipex.h ./include/get_next_line.h

NAME = pipex

SRCS = $(addprefix ./srcs/, main.c utilities.c parsing.c check_args.c set_argv.c cmd.c)

OBJ = $(SRCS:.c=.o)

HEADERS_BONUS = ./include/pipex_bonus.h

SRC_BONUS = $(addprefix ./bonus/, main_bonus.c cmd_bonus.c utilities.c check_args.c set_argv.c parsing.c) \
      get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)


all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIB) :
	@make -C ./libft

bonus : $(LIB) $(OBJ_BONUS)
	@$(CC) -o $(NAME) $(OBJ_BONUS) $(LIB)

clean :
	@make clean -C ./libft
	@/bin/rm -f $(OBJ)

clean_bonus :
	@make clean -C ./libft
	@/bin/rm -f $(OBJ_BONUS)

fclean : clean clean_bonus
	@make fclean -C ./libft
	@/bin/rm -f $(NAME) $(BONUS)

re : fclean all
