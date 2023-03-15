NAME = template

HEADER = whatever.hpp
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

%.o : %.cpp $(HEADER)
	@clang++ $(FLAGS) -o $@ -c  $<

all:	$(NAME)

$(NAME):	$(OBJ)
	@clang++ ${FLAGS} ${OBJ} -o ${NAME}

clean:
				@$(RM) $(OBJ)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)
