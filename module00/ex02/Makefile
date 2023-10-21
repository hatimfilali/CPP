SRC = Account.cpp tests.cpp 

OBJ = $(SRC:.cpp=.o)

NAME = MyBank

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(OBJ) $(CPPFLAGS) -o $(NAME)

clean : 
	rm $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME)

re : fclean $(NAME)