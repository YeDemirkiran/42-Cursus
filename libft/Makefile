CC = cc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c ./ft_strdup.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c
BSRCS = ./ft_lstadd_back_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstclear_bonus.c ./ft_lstdelone_bonus.c ./ft_lstiter_bonus.c ./ft_lstlast_bonus.c ./ft_lstmap_bonus.c ./ft_lstnew_bonus.c ./ft_lstsize_bonus.c 

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

testb: fclean bonus
	$(CC) $(FLAGS) test.c $(NAME) -o test.out -lbsd -g
	make clean

testf: re
	$(CC) $(FLAGS) test.c $(NAME) -o test.out -lbsd -g
	make clean

test: re
	$(CC) test.c $(NAME) -o test.out -lbsd -g
	make clean

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) ${OBJS}

bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME) ${OBJS} ${BOBJS} 

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f ./$(NAME)
	rm -f ./test.out

re: fclean all

.PHONY: all main bonus clean fclean re bonus