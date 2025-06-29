CC = cc
FLAGS = -Wall -Wextra -Werror -g
MAIN = ./main.c 
SRC = ../src/get_next_line.c ../src/get_next_line_utils.c 
BSRC = ../src/get_next_line_bonus.c ../src/get_next_line_utils_bonus.c 
INC = -I../src/
NAME = test.out

ifdef BUFFER_SIZE
BUFFER = -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

all: $(SRC)
	$(CC) $(FLAGS) $(MAIN) $(SRC) -o $(NAME) $(INC) $(BUFFER)

bonus: $(BSRC)
	$(CC) $(FLAGS) $(MAIN) $(BSRC) -o $(NAME) $(INC) $(BUFFER) -D BONUS=1

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re