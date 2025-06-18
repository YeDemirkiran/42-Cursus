#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include "stdarg.h"

enum e_formats
{
	NONE = 0,
	F_PLUS = 1,
	F_MINUS = 2,
	F_ZERO = 4,
	F_SPACE = 8,
	F_HASH = 16,
	C_HEX_UP = 32,
	C_HEX_LOW = 64,
	C_UINT = 128,
	C_INT = 256,
	C_CHAR = 512,
	C_STR = 1024,
	C_POINTER = 2048,
	C_PERCENT = 4096
};

typedef struct s_conv_rule
{
	enum e_formats	format;
	int				format_len;
	int				min_width;
	int				max_width;
}				t_conv_rule;

int		is_flag(const char c);
int		is_formspec(const char c);

char	*uint_to_hex(unsigned int n);
char	*ulong_to_hex(unsigned long n);

size_t	print_char(char c);
size_t	print_string(char *str);
int		ft_printf(const char *format, ...);

#endif