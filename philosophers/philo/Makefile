# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:33:40 by fel-boua          #+#    #+#              #
#    Updated: 2021/12/11 16:54:21 by fel-boua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable files
NAME = ./philo


# Project's directories
OBJECTSDIR = objects
HEADERFILE = philosophers.h


# Name of variables
FLAGS = -Wall -Wextra -Werror
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m


# philosophers files variable
SRC_FILES = ft_actions.c \
ft_init.c \
ft_parsing.c \
philosophers.c \



# Define objects for all sources
OBJS := $(addprefix $(OBJECTSDIR)/, $(SRC_FILES:.c=.o))

# Name the compiler
CC = gcc

# OS specific part
RM = rm -rf
RMDIR = rm -rf
MKDIR = mkdir -p
MAKE = make -C
ECHO = /bin/echo
ERRIGNORE = 2>/dev/null

all: credit $(NAME)
	@echo "$(GREEN)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"

head:
	@echo "$(GREEN)██████████████████████ Making Philosophers █████████████████████$(RESET)"

# philosophers making rules
$(NAME): head $(OBJS)
	@$(CC) -I $(HEADERFILE) $(OBJS) -o $@

$(OBJECTSDIR)/%.o: %.c $(HEADERFILE)
	@$(MKDIR) $(dir $@)
	@echo "$(GREEN)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(GREEN) █$(RESET)"
	@$(CC) $(FLAGS) -I $(HEADERFILE) -o $@ -c $<

# Remove all objects, dependencies and executable files generated during the build
clean:
	@echo "$(RED)deleting$(RESET): " $(OBJECTSDIR)
	@$(RMDIR) $(OBJECTSDIR)


fclean: clean
	@echo "$(RED)deleting$(RESET): " $(NAME)
	@$(RM) $(NAME) philo.dSYM $(ERRIGNORE)

re: fclean all

# Print Credit
credit:
	@echo "▀██▀▀█▄  ▀██       ██  ▀██                                  ▀██"
	@echo " ██   ██  ██ ▄▄   ▄▄▄   ██    ▄▄▄    ▄▄▄▄    ▄▄▄   ▄▄▄ ▄▄▄   ██ ▄▄     ▄▄▄▄  ▄▄▄ ▄▄   ▄▄▄▄"
	@echo " ██▄▄▄█▀  ██▀ ██   ██   ██  ▄█  ▀█▄ ██▄ ▀  ▄█  ▀█▄  ██▀  ██  ██▀ ██  ▄█▄▄▄██  ██▀ ▀▀ ██▄ ▀"
	@echo " ██       ██  ██   ██   ██  ██   ██ ▄ ▀█▄▄ ██   ██  ██    █  ██  ██  ██       ██     ▄ ▀█▄▄"
	@echo "▄██▄     ▄██▄ ██▄ ▄██▄ ▄██▄  ▀█▄▄█▀ █▀▄▄█▀  ▀█▄▄█▀  ██▄▄▄▀  ▄██▄ ██▄  ▀█▄▄▄▀ ▄██▄    █▀▄▄█▀"
	@echo "                                                    ██"


