# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 14:08:47 by yademirk          #+#    #+#              #
#    Updated: 2025/08/23 16:01:12 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
B_NAME = so_long_bonus
MAND_DIR = ./mandatory/
BONUS_DIR = ./bonus/

all: $(NAME)

$(NAME):
	make -C $(MAND_DIR)
	mv $(MAND_DIR)$(NAME) .

bonus: $(B_NAME)

$(B_NAME):
	make -C $(BONUS_DIR)
	mv $(BONUS_DIR)$(B_NAME) .

clean:
	rm -rf $(NAME) $(B_NAME)

fclean: clean
	make fclean -C $(MAND_DIR)
	make fclean -C $(BONUS_DIR)

re: fclean all

reb: fclean bonus

.PHONY: all bonus clean fclean re