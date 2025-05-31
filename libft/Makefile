CC = cc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . ! -name "main.c" -name "ft_*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

main: re
	$(CC) $(FLAGS) main.c $(NAME) -o main.out -lbsd
	make clean

$(NAME): 
	$(CC) $(FLAGS) $(SRCS) -c
	ar rcs $(NAME) ${OBJS}

clean:
	rm -f ./$(OBJS)

fclean: clean
	rm -f ./$(NAME)
	rm -f ./main.out

re: fclean all

.PHONY = all main bonus clean fclean re