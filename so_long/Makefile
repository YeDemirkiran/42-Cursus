# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 13:03:01 by yademirk          #+#    #+#              #
#    Updated: 2025/08/20 11:02:55 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long

MLX_DIR = ./minilibx
MLX_LIB = mlx_Linux

LIB_DIRS = -L/usr/lib -L$(MLX_DIR)
LIBS = -lm -l$(MLX_LIB) -lXext -lX11 -lz

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_split.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c)

WRITE_DIR = write/
WRITE_SRC = $(addprefix $(WRITE_DIR), ft_putchar.c ft_putstr.c ft_putnbr.c)

GNL_DIR = gnl/
GNL_SRC = $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c check.c events.c events_extra.c generate.c init_extra.c init.c map.c map_extra.c map_utils.c render.c update.c utils.c utils_extra.c $(STRING_SRC) $(WRITE_SRC) $(GNL_SRC))

INC = -I./include -I/usr/include -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) $(LIB_DIRS) $(LIBS) $(INC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re