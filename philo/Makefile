# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emileorer <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 14:53:45 by emileorer         #+#    #+#              #
#    Updated: 2023/07/28 16:09:29 by emileorer        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET := $(shell uname -s)

ifeq ($(TARGET), Darwin)
	CC = clang
else
	CC = cc
endif

CFLAGS = -Wall -Wextra -Werror -g 

LFLAGS = -lpthread

SRCS = $(wildcard ./srcs/*.c) 

OBJ = $(SRCS:.c=.o)

NAME = philo

HEADER = philo.h


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
