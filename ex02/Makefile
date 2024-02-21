NAME = PmergeMe

CC = c++

SRC = main.cpp 

OBJ = $(SRC:.cpp=.o)

.cpp.o:
	$(CC) -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean
