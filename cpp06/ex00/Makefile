NAME			= convert

HEADERS			=  Convert.hpp
					
SRCS			=   main.cpp  \
					Convert.cpp
					
		  
OBJS			= $(SRCS:.cpp=.o)

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -rf 

%.o : %.cpp $(HEADERS)
	@clang++ ${FLAGS} -o $@ -c $<

all:			$(NAME)

$(NAME):		$(OBJS)
	@clang++ ${FLAGS} ${OBJS} -o ${NAME}

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)
