# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:09:08 by yademirk          #+#    #+#              #
#    Updated: 2025/08/13 13:09:09 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c $(SORTING_SRC) $(CONV_SRC) $(PREDICATE_SRC) $(STRING_SRC) $(WRITE_SRC) $(STACK_SRC) $(ARRAY_SRC))

SORTING_DIR = sorting/
SORTING_SRC = $(addprefix $(SORTING_DIR), bubble_sort.c insertion_sort.c selection_sort.c)

CONV_DIR = converter/
CONV_SRC = $(addprefix $(CONV_DIR), ft_atol.c)

PREDICATE_DIR = predicate/
PREDICATE_SRC = $(addprefix $(PREDICATE_DIR), ft_isdigit.c ft_isnumber.c)

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_strlen.c)

WRITE_DIR = write/
WRITE_SRC = $(addprefix $(WRITE_DIR), ft_putchar.c ft_putstr.c)

STACK_DIR = stack/
STACK_SRC = $(addprefix $(STACK_DIR), init_stack.c stack_rotate.c stack_rotate_rev.c stack_swap.c stack_push.c stack_operations.c stack_move.c)

ARRAY_DIR = array/
ARRAY_SRC = $(addprefix $(ARRAY_DIR), dup_array.c)

INC = ./include

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(INC) -o $(NAME)

test:
	make -C ./test

test_re:
	make re -C ./test

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all test test_re clean fclean re
