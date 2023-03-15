# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 21:28:28 by fel-boua          #+#    #+#              #
#    Updated: 2019/11/13 02:26:26 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./ft_atoi.c \
	  ./ft_bzero.c \
	  ./ft_calloc.c \
	  ./ft_isalnum.c \
	  ./ft_isalpha.c \
	  ./ft_isascii.c \
	  ./ft_isdigit.c \
	  ./ft_isprint.c \
	  ./ft_itoa.c \
	  ./ft_memccpy.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_memcpy.c \
	  ./ft_memmove.c \
	  ./ft_memset.c \
	  ./ft_putchar_fd.c \
	  ./ft_putendl_fd.c \
	  ./ft_putnbr_fd.c \
	  ./ft_putstr_fd.c \
	  ./ft_split.c \
	  ./ft_strchr.c \
	  ./ft_strdup.c \
	  ./ft_strjoin.c \
	  ./ft_strlcpy.c \
	  ./ft_strlcat.c \
	  ./ft_strlen.c \
	  ./ft_strmapi.c \
	  ./ft_strncmp.c \
	  ./ft_strnstr.c \
	  ./ft_strrchr.c \
	  ./ft_strtrim.c \
	  ./ft_substr.c \
	  ./ft_tolower.c \
	  ./ft_toupper.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
