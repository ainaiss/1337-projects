 SRC_FILE = main.cpp
OBJ_FILE = $(SRC_FILE:.c=.o)
NAME = main
# the compiler: gcc for C program, define as g++ for C++
CC = c++
# compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
FLAGS = -Wall -Wextra -Werror -std=c++98
# a build command to build myprogram executable from myprogram.o and mylib.lib
all: $(NAME)
 # The build target 
%.c:%.o
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJ_FILE)
	$(CC) $(FLAGS) $(OBJ_FILE) -o $(NAME)
# a build command to build myprogram executable from myprogram.o and mylib.lib
fclean :
	rm -rf $(NAME)
re : clean all
.PHONY : clean fclean re
