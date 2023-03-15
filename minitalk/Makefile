# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 18:02:43 by fel-boua          #+#    #+#              #
#    Updated: 2021/11/03 18:02:47 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		server

NAME2 =		client

CFLAGS +=	-Wall -Wextra -Werror

SRCS1 =		srcs/server.c srcs/utils.c

SRCS2 =		srcs/client.c srcs/utils.c

ifdef 
	OBJS1 =		$(SRCS1:.c=.o)
else
	OBJS1 =		$(SRCS1:.c=.o)
	OBJS2 =		$(SRCS2:.c=.o)
endif

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJS1)
			gcc $(CFLAGS) $(OBJS1) -o $(NAME)

$(NAME2):	$(OBJS2)
			gcc $(CFLAGS) $(OBJS2) -o $(NAME2)

clean:
			rm -f $(OBJS1) $(OBJS2)

fclean:		clean
			rm -f $(NAME) $(NAME2)

re: 		fclean all
