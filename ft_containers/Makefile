# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 01:29:19 by fel-boua          #+#    #+#              #
#    Updated: 2022/11/02 20:41:52 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC = main.cpp

OBJ = main.o

FLAGS = --std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	clang++ ${FLAGS} $(SRC)  -o $(NAME)

clean:
	@rm -rf ${OBJ}

fclean: clean
	@rm -f $(NAME)

re: fclean all

