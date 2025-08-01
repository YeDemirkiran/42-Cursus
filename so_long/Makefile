# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 13:03:01 by yademirk          #+#    #+#              #
#    Updated: 2025/08/01 16:30:11 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long

MLX_DIR = ./minilibx
MLX_LIB = mlx_Linux

LIB_DIRS = -L/usr/lib -L$(MLX_DIR)
LIBS = -lm -l$(MLX_LIB) -lXext -lX11 -lz

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c)

INC = -I./include -I/usr/include -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) $(LIB_DIRS) $(LIBS) $(INC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re