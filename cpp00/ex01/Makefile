NAME = PhoneBook
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++

SRCS =	main.cpp PhoneBook.cpp Contact.cpp

HEADERS =	Contact.hpp	PhoneBook.hpp

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

re : fclean all
