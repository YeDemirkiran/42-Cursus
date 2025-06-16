NAME = libftprintf.a
CC = cc
SRCS = ./ft_printf.c
OBJS = $(SRCS:.c=.o)
INC = $(LIBFT_PATH)
FLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT_PATH)$(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) bonus

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -s -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

test: $(NAME) test.c
	$(CC) $(FLAGS) test.c $(NAME) -o test.out -I$(INC)