# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emileorer <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 23:00:02 by emileorer         #+#    #+#              #
#    Updated: 2023/10/02 23:35:30 by emileorer        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ 

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

NAME = zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
