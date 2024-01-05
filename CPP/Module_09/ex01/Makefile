# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 17:27:33 by eorer             #+#    #+#              #
#    Updated: 2024/01/05 17:28:06 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

NAME = RPN


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
