# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 10:45:13 by fel-boua          #+#    #+#              #
#    Updated: 2020/12/24 10:45:21 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	display_c.c display_d_utils.c display_p_utils.c	display_s_utils.c \
		display_u_utils.c display_x_utils.c ft_itoa.c ft_strlen.c \
		display_d.c display_p.c display_s.c display_u.c display_x.c ft_atoi.c \
		ft_printf.c	ft_printf_utils.c percent.c
	
		

OUTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OUTS) 
		    ar rcs $(NAME) $(OUTS)
%.o: %.c
	gcc -Wall -Wextra -Werror -c $<

clean :
	    /bin/rm -rf $(OUTS)

fclean : clean
	    /bin/rm -rf $(NAME)

re : fclean all
