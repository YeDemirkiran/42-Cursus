# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:09:08 by yademirk          #+#    #+#              #
#    Updated: 2025/08/30 12:08:19 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I./include -I./include/structs -I./include/enums -I./include/modules -I./include/modules/stack  -I./include/modules/sorting
NAME = push_swap

C_FILES = main.c $(SORTING_SRC) $(CONV_SRC) $(PREDICATE_SRC) $(STRING_SRC) $(WRITE_SRC) $(STACK_SRC)

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(C_FILES))

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

SORTING_DIR = sorting/
SORTING_SRC = $(addprefix $(SORTING_DIR), insertion_sort.c chunk_sort.c)

CONV_DIR = converter/
CONV_SRC = $(addprefix $(CONV_DIR), ft_atol.c)

PREDICATE_DIR = predicate/
PREDICATE_SRC = $(addprefix $(PREDICATE_DIR), ft_isdigit.c ft_isnumber.c)

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_strlen.c)

WRITE_DIR = write/
WRITE_SRC = $(addprefix $(WRITE_DIR), ft_putchar.c ft_putstr.c)

STACK_DIR = stack/
STACK_SRC = $(addprefix $(STACK_DIR), stack_init.c stack_rotate.c stack_rotate_rev.c stack_swap.c stack_push.c stack_utils.c stack_move.c stack_predicate.c stack_get.c)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC_FLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC_FLAGS) -c -o $@ $<

test:
	make -C ./test

test_re:
	make re -C ./test

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all test test_re clean fclean re
