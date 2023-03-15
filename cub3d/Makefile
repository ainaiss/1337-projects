# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 16:58:35 by fel-boua          #+#    #+#              #
#    Updated: 2021/04/15 15:34:14 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MLX = -lmlx -lm -framework OpenGL -framework AppKit

NAME = cub3D

NAMELIB = printflib.a

SRCS = 	files/ft_init.c \
		files/ft_key_pressed.c \
		files/ft_move.c \
		files/ft_player.c \
		files/ft_puterror.c \
		files/ft_readmap.c \
		files/ft_screenshot.c \
		files/ft_sprite.c \
		files/ft_texture.c \
		files/ft_update.c \
		files/ft_check.c \
		files/ft_draw.c \
		files/ft_utils.c \
		files/ft_utils1.c \
		files/ft_utils2.c \
		files/ft_utils3.c \
		files/ft_utils4.c \
		files/ft_utils5.c \
		files/main.c
CC = gcc

CFLAGS = -Wall -Werror -Wextra

GETNEXT =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)
OBJGET	= $(GETNEXT:.c=.o)

$(NAME) : $(OBJ) $(OBJGET)
	@echo "[Remove last version Of Cub3D...]"
	@rm -rf Cub3D
	@$(MAKE) -C ./ft_printf
	@mv ./ft_printf/printflib.a .
	@echo "[Cub3D compilation...]"
	@$(CC) $(OBJ) $(OBJGET) -I ./includes -Wall -Wextra -Werror $(MLX) $(NAMELIB) -o $(NAME) -g
	@echo "[Done !]"

all : $(NAME)

clean :
	@echo "[Cleaning The Old Files...!]"
	@rm -rf $(OBJ) $(B_OBJ)
	@$(MAKE) clean -C ./ft_printf

fclean : clean
	@echo "[Cleaning printf Files...!]"
	@$(MAKE) fclean -C ./ft_printf
	@rm -rf printflib.a
	@echo "[Cleaning Cub3D Files...!]"
	@rm -rf $(NAME) $(OBJ) $(OBJGET)
	@echo "[Deleting Old Screenshot...!]"
	@rm -rf Screenshot.bmp

re : fclean all
