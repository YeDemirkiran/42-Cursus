# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 16:19:41 by yademirk          #+#    #+#              #
#    Updated: 2025/08/30 17:30:21 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
INC_DIR = ../include
INC_FLAGS = -I. -I$(INC_DIR) -I$(INC_DIR)/structs -I$(INC_DIR)/enums -I$(INC_DIR)/modules -I$(INC_DIR)/modules/stack -I$(INC_DIR)/modules/sorting -I$(INC_DIR)/modules/pair
NAME = checker

C_FILES = $(CONV_SRC) $(PREDICATE_SRC) $(STRING_SRC) $(WRITE_SRC) $(STACK_SRC) $(PAIR_SRC) $(INST_SRC) $(SORTING_SRC) $(GNL_SRC)

SRC_DIR = ../src/
SRC = checker.c checker_extra.o error.c $(addprefix $(SRC_DIR), $(C_FILES))

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), checker.o checker_extra.o error.o $(C_FILES:.c=.o))

SORTING_DIR = sorting/
SORTING_SRC = $(addprefix $(SORTING_DIR), insertion_sort.c chunk_sort.c chunk_sort_utils.c)

CONV_DIR = converter/
CONV_SRC = $(addprefix $(CONV_DIR), ft_atol.c)

PREDICATE_DIR = predicate/
PREDICATE_SRC = $(addprefix $(PREDICATE_DIR), ft_isdigit.c ft_isnumber.c)

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_strlen.c ft_strncmp.c)

WRITE_DIR = write/
WRITE_SRC = $(addprefix $(WRITE_DIR), ft_putchar.c ft_putstr.c)

GNL_DIR = gnl/
GNL_SRC = $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)

STACK_DIR = stack/
STACK_SRC = $(addprefix $(STACK_DIR), stack_init.c stack_rotate.c stack_rotate_rev.c stack_swap.c stack_push.c stack_utils.c stack_move.c stack_predicate.c stack_get.c)

PAIR_DIR = pair/
PAIR_SRC = $(addprefix $(PAIR_DIR), pair_utils.c)

INST_DIR = instructions/
INST_SRC = $(addprefix $(INST_DIR), instructions.c)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC_FLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC_FLAGS) -c -o $@ $<

$(OBJ_DIR)%.o: ./%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
