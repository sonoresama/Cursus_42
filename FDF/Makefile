# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:02:57 by eorer             #+#    #+#              #
#    Updated: 2023/02/23 14:51:31 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -I$(INC) $(INCHEAD) -I./minilibx -Wall -Wextra -Werror -g

LFLAGS = -L./minilibx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

HEADERS = ./include/fdf.h \
	  ./libft/include/libft.h \
	  ./libft/ft_printf.h

	   
INC = /usr/include

INCLIB = $(INC)/../lib

INCHEAD = -I./include \

LIB = libft.a

LIBX = libmlx42.a

NAME = fdf

SRC = $(addprefix ./src/, main.c mlx_utils.c draw.c draw_line.c \
      utilities.c init_mlx.c row_and_col.c get_map.c \
      upgrade_height.c event.c move_map.c zoom.c center_map.c init_values.c check_arg.c) \
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
	@/bin/rm -f $(NAME) $(LIB)

re : fclean all
