NAME = libftprintf.a
CC = cc
SRCS = ./ft_printf.c ./converters.c ./converters_2.c ./predicate.c ./utils.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_PATH = ./libft/

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(LIBFT_PATH)$(LIBFT)
	cp $(LIBFT_PATH)$(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_PATH)$(LIBFT): 
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

.PHONY: all bonus clean fclean re