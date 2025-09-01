#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 21:37:32 by yademirk          #+#    #+#              #
#    Updated: 2025/09/01 21:52:22 by yademirk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

CC = cc

W_FLAGS = -Wall -Wextra -Werror

FLAGS = $(W_FLAGS)

SRC_DIR = ./src/
OBJ_DIR = ./obj/

C_FILES = main.c
SRCS = $(addprefix $(SRC_DIR), $(C_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
