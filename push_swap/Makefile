CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c init_stack.c $(SORTING_SRC) $(CONV_SRC) $(PREDICATE_SRC) $(STRING_SRC) $(WRITE_SRC) $(STACK_SRC)) 

SORTING_DIR = sorting/
SORTING_SRC = $(addprefix $(SORTING_DIR), bubble_sort.c)

CONV_DIR = converter/
CONV_SRC = $(addprefix $(CONV_DIR), ft_atol.c)

PREDICATE_DIR = predicate/
PREDICATE_SRC = $(addprefix $(PREDICATE_DIR), ft_isdigit.c ft_isnumber.c)

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_strlen.c)

WRITE_DIR = write/
WRITE_SRC = $(addprefix $(WRITE_DIR), ft_putchar.c ft_putstr.c)

STACK_DIR = stack/
STACK_SRC = $(addprefix $(STACK_DIR), stack_rotate.c stack_rotate_rev.c stack_swap.c)

INC = ./include

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(INC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re