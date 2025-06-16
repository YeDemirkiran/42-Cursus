#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"

int	ft_printf(const char *format, ...)
{
	ft_putstr_fd((char *)format, 1);
	return (0);
}

#endif