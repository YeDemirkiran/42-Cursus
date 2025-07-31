CC = cc
FLAGS = -Wall -Wextra -Werror
INC_DIR = ../include
NAME = push_swap_tester

SRC = ./main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -I$(INC_DIR) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re