CC = cc
NAME = test
LIB = ../src/libft.a
FLAGS = -Wall -Wextra -Werror -I../src/

all: $(NAME)

test: bonus
	$(CC) test.c $(LIB) -o $(NAME) -lbsd -g

testf: bonus
	$(CC) $(FLAGS) test.c $(LIB) -o $(NAME) -lbsd -g

bonus:
	make bonus -C ../src/

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re