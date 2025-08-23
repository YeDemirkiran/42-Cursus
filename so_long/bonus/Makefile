# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 13:03:01 by yademirk          #+#    #+#              #
#    Updated: 2025/08/23 15:58:18 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long_bonus

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_split.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c ft_itoa.c)

WRITE_DIR = write/
WRITE_SRC = $(addprefix $(WRITE_DIR), ft_putchar.c ft_putstr.c ft_putnbr.c)

GNL_DIR = gnl/
GNL_SRC = $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)

EVENTS_DIR = events/
EVENTS_SRC = $(addprefix $(EVENTS_DIR), events.c events_extra.c)

INIT_DIR = init/
INIT_SRC = $(addprefix $(INIT_DIR), init.c init_extra.c)

MAP_DIR = map/
MAP_SRC = $(addprefix $(MAP_DIR), map.c map_extra.c map_utils.c map_bonus.c)

PATH_DIR = path/
PATH_SRC = $(addprefix $(PATH_DIR), path.c path_extra.c)

UTILS_DIR = utils/
UTILS_SRC = $(addprefix $(UTILS_DIR), utils.c utils_extra.c)

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), main.c overlap.c render.c update.c $(STRING_SRC) $(WRITE_SRC) $(GNL_SRC) $(EVENTS_SRC) $(INIT_SRC) $(MAP_SRC) $(PATH_SRC) $(UTILS_SRC))

MLX_DIR = ../minilibx
MLX_LIBFILE = $(MLX_DIR)/libmlx_Linux.a $(MLX_DIR)/libmlx.a
MLX_LIB = mlx_Linux

LIB_DIRS = -L/usr/lib -L$(MLX_DIR)
LIBS = -lm -l$(MLX_LIB) -lXext -lX11 -lz

INC_DIRS = ./include ./include/enums ./include/structs ./include/modules /usr/include $(MLX_DIR)
INC =  $(addprefix -I, $(INC_DIRS))

all: $(NAME)

$(NAME): $(SRC) $(MLX_LIBFILE)
	$(CC) $(SRC) $(FLAGS) $(LIB_DIRS) $(LIBS) $(INC) -o $(NAME)

$(MLX_LIBFILE):
	make -C $(MLX_DIR)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(MLX_LIBFILE)

re: fclean all

.PHONY: all clean fclean re
