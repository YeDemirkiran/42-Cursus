CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = ./main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re