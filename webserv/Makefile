NAME = webserv
CXX = clang++
CPPFLAGS = -std=c++98 -Wall -Werror -Wextra
CPPFLAGS_DEB = -std=c++98 -Wall -Werror -Wextra -DDEBUG
INC = -Isrcs

SRC = src/main.cpp \
src/parsers/config_parser.cpp \
src/parsers/option_parser.cpp \
src/parsers/request_parser.cpp \
src/response_generator/fastcgi.cpp \
src/response_generator/generate_response.cpp \
src/response_generator/http_delete.cpp \
src/response_generator/http_get.cpp \
src/response_generator/http_map.cpp \
src/response_generator/http_post.cpp \
src/tcp_server/server_config.cpp \
src/tcp_server/tcp_server.cpp \
src/utilities/utils.cpp \
src/webserv/webserv.cpp

HDR = src/parsers/config_parser.hpp \
src/response_generator/response_generator.hpp \
src/tcp_server/server_config.hpp \
src/tcp_server/tcp_server.hpp \
src/utilities/logger.hpp \
src/utilities/utils.hpp \
src/webserv/webserv.hpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

debug : CPPFLAGS = $(CPPFLAGS_DEB)
debug : $(NAME)

$(OBJ) : $(HDR)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(INC) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
