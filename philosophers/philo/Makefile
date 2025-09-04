#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 21:37:32 by yademirk          #+#    #+#              #
#    Updated: 2025/09/04 18:39:15 by yademirk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

CC = cc

W_FLAGS = -Wall -Wextra -Werror
LIB_FLAGS = -pthread
INC_FLAGS = -I./include/
FLAGS = $(W_FLAGS) $(INC_FLAGS) $(LIB_FLAGS)

SRC_DIR = ./src/
OBJ_DIR = ./obj/

UTILS_DIR = ./utils/
UTILS_SRC = $(addprefix $(UTILS_DIR), convert.c)

C_FILES = main.c mutex.c philosophers.c simulation.c table.c $(UTILS_SRC)
SRCS = $(addprefix $(SRC_DIR), $(C_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
