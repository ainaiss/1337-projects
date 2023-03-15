NAME = Bureaucrat
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++

SRCS =	main.cpp Bureaucrat.cpp 

HEADERS =	Bureaucrat.hpp 

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@
	
clean:
	@rm *.o

fclean: clean
	@rm -rf $(NAME)