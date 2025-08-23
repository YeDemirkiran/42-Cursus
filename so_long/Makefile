# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 14:08:47 by yademirk          #+#    #+#              #
#    Updated: 2025/08/23 14:08:48 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MAND_DIR = ./mandatory/
BONUS_DIR = ./bonus/

all: $(NAME)

$(NAME):
	make -C $(MAND_DIR)
	cp $(MAND_DIR)$(NAME) ./$(NAME)

bonus:
	make -C $(BONUS_DIR)
	cp $(BONUS_DIR)$(NAME) ./$(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	make fclean -C $(MAND_DIR)

re: fclean all

.PHONY: all bonus clean fclean re