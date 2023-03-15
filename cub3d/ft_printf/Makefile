# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 17:13:36 by fel-boua          #+#    #+#              #
#    Updated: 2021/04/03 17:13:43 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = printflib.a

INCLUDES = /includes/libftprintf.h ./libft/libft.h

NAMELIB = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ./SRC/*.c

OBJ = *.o *SORTED

all: $(NAME)

$(NAMELIB):
	@echo "[Libft compilation...]"
	@make -C ./libft
	@echo "[Moving Libft...]"
	@mv ./libft/$(NAMELIB) .
	
$(NAME):$(NAMELIB)
	@echo "[ft_printf compilation...]"
	@ar -x libft.a
	@$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -f libft.a

fclean: clean
	@make fclean -C libft
	@rm -f *.a

re: fclean all
