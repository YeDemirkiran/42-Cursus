CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c $(SORTING_SRC) $(CONV_SRC)) 

SORTING_DIR = sorting/
SORTING_SRC = $(addprefix $(SORTING_DIR), bubble_sort.c)

CONV_DIR = converter/
CONV_SRC = $(addprefix $(CONV_DIR), atoi.c)

INC = ./include

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(INC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re