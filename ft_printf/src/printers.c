#include "libftprintf.h"

size_t	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	print_string(char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (len);
}
