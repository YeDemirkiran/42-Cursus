NAME = test.out
CC = cc
SRCS = ./main.c
INC = -I$(PRINTF_PATH) -I$(PRINTF_PATH)libft/
FLAGS = -Wall -Wextra -Werror
PRINTF = libftprintf.a
PRINTF_PATH = ../src/

all: $(NAME)

$(NAME): $(PRINTF)
	$(CC) $(FLAGS) $(SRCS) $(PRINTF_PATH)$(PRINTF) -o $(NAME) $(INC)

$(PRINTF):
	make -s -C $(PRINTF_PATH)

noflag: $(PRINTF)
	$(CC) $(SRCS) $(PRINTF_PATH)$(PRINTF) -o $(NAME) $(INC)

clean:
	rm -f $(OBJS)
	make -s -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re