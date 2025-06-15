CC = cc
NAME = test
LIB = ../src/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

test: normal
	$(CC) test.c $(LIB) -o $(NAME) -lbsd -g -I../src/

testf: bonus
	$(CC) $(FLAGS) test.c $(LIB) -o $(NAME) -lbsd -g -I../src/

normal:
	make -C ../src/

bonus:
	make bonus -C ../src/

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re