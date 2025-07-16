CC = cc
FLAGS = -Wall -Wextra -Werror
INC = ./includes
NAME = push_swap

SRC = ./main.c $(SORTING)
SORTING = ./sorting/bubble_sort.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(INC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re