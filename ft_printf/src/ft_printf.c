#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		while (format[len] && format[len] != '%')
			len++;	
		ft_putstr_fd(format, 1);
		if (!format[i])
			break ;
	}
	return (len);
}

//asdsdasda%d%s%c%p

static size_t	format_count(const char *s)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			i++;
		if (!s[i])
			break ;
		if (is_formspec(s[i]))
			count++;
	}
}

static void		str_insert(char str, ...)
{
	va_list args;

	va_start(args, str);
	va_arg(args, int);
}

static t_bool	is_formspec(const char c) 
{
	const char *format_specifiers = "cspdiuxX%";

	if (ft_strchr(format_specifiers, c))
		return (TRUE);
	return (FALSE);
}