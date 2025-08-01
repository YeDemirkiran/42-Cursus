# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 13:03:01 by yademirk          #+#    #+#              #
#    Updated: 2025/08/01 13:21:24 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -lm
NAME = so_long

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c) 

INC = ./include

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(INC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re