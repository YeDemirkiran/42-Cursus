# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 11:50:42 by yademirk          #+#    #+#              #
#    Updated: 2025/08/05 11:54:13 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc

SRC_DIR = ./src/
INC_DIR = ./include/

SRC = $(addprefix $(SRC_DIR), main.c)

W_FLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I$(INC_DIR)
FLAGS = $(W_FLAGS) $(INC_FLAGS)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS )-o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY = all clean fclean re