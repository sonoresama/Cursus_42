# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eorer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:17:25 by eorer             #+#    #+#              #
#    Updated: 2022/12/16 14:02:35 by eorer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I

NAME = libft.a

INCLUDES = ./include

HEADERS = ./include/ft_printf.h\
	  ./include/libft.h

SRC_DIR = src/

SRC_FILES = ft_atoi.c ft_isascii.c ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c \
      ft_substr.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c \
      ft_strncmp.c ft_tolower.c ft_calloc.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c \
      ft_strnstr.c ft_toupper.c ft_isalnum.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c \
      ft_strrchr.c ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
      ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c \
      ft_lstclear.c ft_lstiter.c ft_lstmap.c \
      ft_functions.c ft_hexa.c ft_printf.c 

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJECTS = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))


all: $(NAME)

$(NAME) : $(OBJECTS) $(HEADERS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	/bin/rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all
