# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 17:32:32 by fel-boua          #+#    #+#              #
#    Updated: 2021/11/14 19:48:08 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_intsize.c ft_isalnum.c ft_isalpha.c \
	  	ft_isdigit.c ft_isascii.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_putstr_fd.c ft_memcmp.c ft_strcmp.c my_split.c

OBJ = $(SRC:%.c=%.o)


CC = gcc

CFLAGS = #-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean: 
	@/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
