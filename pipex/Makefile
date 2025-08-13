# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 11:50:42 by yademirk          #+#    #+#              #
#    Updated: 2025/08/13 12:43:43 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc

SRC_DIR = ./src/
INC_DIR = ./include/

STRING_DIR = string/
STRING_SRC = $(addprefix $(STRING_DIR), ft_split.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_substr.c ft_strncmp.c ft_strcmp.c)

SRC = $(addprefix $(SRC_DIR), main.c init.c parser.c process.c utils.c error_handling.c $(STRING_SRC))

W_FLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I$(INC_DIR)
FLAGS = $(W_FLAGS) $(INC_FLAGS)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) -o $(NAME)

bonus: all

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY = all clean fclean re