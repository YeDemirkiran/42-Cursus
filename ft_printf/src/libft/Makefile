CC = cc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putnchr.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_putnstr.c ./ft_split.c ./ft_strchr.c ./ft_strdup.c ./ft_strinv.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c ./ft_str_toupper.c ./ft_str_tolower.c ./ft_abs.c ./ft_intlen.c ./ft_uintlen.c ./ft_utoa.c ./ft_smaller.c ./ft_int_bigger.c
BSRCS = ./ft_lstadd_back_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstclear_bonus.c ./ft_lstdelone_bonus.c ./ft_lstiter_bonus.c ./ft_lstlast_bonus.c ./ft_lstmap_bonus.c ./ft_lstnew_bonus.c ./ft_lstsize_bonus.c 

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) ${OBJS}

bonus: $(NAME) ${BOBJS}
	ar rcs $(NAME) ${BOBJS} 

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: all bonus clean fclean re