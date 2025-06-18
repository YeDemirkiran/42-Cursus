NAME = libftprintf.a
CC = cc
SRCS = ./ft_printf.c ./conversion.c ./predicate.c
OBJS = $(SRCS:.c=.o)
INC = -I$(LIBFT_PATH)
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
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

clean:
	rm -f $(OBJS)
	make -s -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re