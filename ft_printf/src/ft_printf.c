#include "libftprintf.h"

//asdsdasda%d%s%c%p

static t_bool	is_formspec(const char c) 
{
	const char *format_specifiers = "cspdiuxX%";

	if (ft_strchr(format_specifiers, c))
		return (TRUE);
	return (FALSE);
}

static char*	detect_format(const char *str)
{
	char	format[1024];
	size_t	i;

	i = 0;
	if (is_formspec(*str))
	{
		format[i] = *str;
	}
	return (format);
}

static size_t	print_format(const char **format)
{
	char	*rule;

	rule = detect_format(*format);
}

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

int	ft_printf(const char *format, ...)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;	
		ft_putnstr((char *)format, i);
		len += i;
		if (!format[i])
			break ;
		format += len + 1;
		len += print_format(&format);
	}
	return (len);
}