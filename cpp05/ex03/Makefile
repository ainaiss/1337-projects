NAME = Bureaucrat

SRCS		=	main.cpp					\
				Bureaucrat.cpp				\
				Form.cpp					\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp	\
				Intern.cpp


HEADERS 	=	Bureaucrat.hpp				\
				Form.hpp					\
				ShrubberyCreationForm.hpp	\
				RobotomyRequestForm.hpp		\
				PresidentialPardonForm.hpp	\
				Intern.hpp

CC			= clang++

CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

OBJS		= $(SRCS:%.cpp=%.o)

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CPP_FLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery


re: fclean all
