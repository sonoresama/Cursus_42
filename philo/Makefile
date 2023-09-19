# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emileorer <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 14:53:45 by emileorer         #+#    #+#              #
#    Updated: 2023/09/06 17:28:14 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET := $(shell uname -s)

ifeq ($(TARGET), Darwin)
	CC = clang
else
	CC = gcc
endif

CFLAGS = -Wall -Wextra -Werror -g -pthread 

LFLAGS = -lpthread

C_SANITIZE_FLAGS =

L_SANITIZE_FLAGS =

ifeq ($(filter sanitize,$(MAKECMDGOALS)),sanitize)
    C_SANITIZE_FLAGS = -fsanitize=thread
    L_SANITIZE_FLAGS = -L/path/to/tsan/library -ltsan
endif

CFLAGS += $(C_SANITIZE_FLAGS)

LFLAGS += $(L_SANITIZE_FLAGS)

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

.PHONY: all clean

.PHONY: sanitize
sanitize: fclean | all
