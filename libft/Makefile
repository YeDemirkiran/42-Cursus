CC = cc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . ! -name "main.c" -name "ft_*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

test: re
	$(CC) $(FLAGS) test.c $(NAME) -o test.out -lbsd
	make clean

$(NAME): 
	$(CC) $(FLAGS) $(SRCS) -c
	ar rcs $(NAME) ${OBJS}

clean:
	rm -f ./$(OBJS)

fclean: clean
	rm -f ./$(NAME)
	rm -f ./test.out

re: fclean all

.PHONY = all main bonus clean fclean re