# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:02:57 by eorer             #+#    #+#              #
#    Updated: 2023/02/15 17:28:48 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -I$(INC) $(INCHEAD) -I./minilibx

LFLAGS = -L./minilibx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

HEADERS = ./include/so_long.h \
	  ./libft/include/libft.h \
	  ./libft/ft_printf.h

	   
INC = /usr/include

INCLIB = $(INC)/../lib

INCHEAD = -I./include \

LIB = libft.a

LIBX = libmlx42.a

NAME = so_long

SRC = $(addprefix ./src/, draw_rect.c init_game.c main.c mlx_utils.c render_background.c render_mobile.c \
      utilities.c init_map.c parsing.c move_parsing.c) \
      		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME) : $(LIB) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(LFLAGS)

$(LIB) : 
	@make -C ./libft
	@cp ./libft/$(LIB) ./

clean :
	@make clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean : clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re : fclean all
