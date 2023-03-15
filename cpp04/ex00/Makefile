NAME = Polymorphism
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++

SRCS =	main.cpp Dog.cpp Cat.cpp Animal.cpp  WrongCat.cpp WrongAnimal.cpp

HEADERS =	Cat.hpp Animal.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp

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