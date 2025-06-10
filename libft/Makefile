CC = cc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . ! -name "main.c" -name "ft_*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

testf: re
	$(CC) $(FLAGS) test.c $(NAME) -o test.out -lbsd -g
	make clean

test: re
	$(CC) test.c $(NAME) -o test.out -lbsd -g
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