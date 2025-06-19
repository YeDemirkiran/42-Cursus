#include "libftprintf.h"

static t_conv_rule	detect_format(const char **str)
{
	t_conv_rule	rule;

	rule.format = 0;
	rule.min_width = 0;
	rule.max_width = -1;
	rule.format_len = 0;
	while (is_flag(**str))
		rule.format |= is_flag(*(*str)++);
	while (ft_isdigit(**str))
	{
		rule.min_width *= 10;
		rule.min_width += *(*str)++ - '0';
	}
	if (**str == '.')
	{
		(*str)++;
		rule.max_width = 0;
		while (ft_isdigit(**str))
		{
			rule.max_width *= 10;
			rule.max_width += *(*str)++ - '0';
		}
	}
	rule.format |= is_formspec(*(*str)++);
	return (rule);
}

static char	*get_format_string(t_conv_rule rule, va_list args)
{
	char	*str;

	if (rule.format & C_PERCENT)
		str = convert_char('%');
	else if (rule.format & C_CHAR)
		str = convert_char((char)va_arg(args, int));
	else if (rule.format & C_STR)
		str = convert_string(va_arg(args, char *));
	else if (rule.format & C_POINTER)
		str = convert_pointer(va_arg(args, void *), rule);
	else if (rule.format & C_INT)
		str = convert_int(va_arg(args, int), rule);
	else if (rule.format & C_UINT)
		str = convert_uint(va_arg(args, unsigned int), rule);
	else if (rule.format & (C_HEX_LOW | C_HEX_UP))
		str = convert_hex(va_arg(args, unsigned int), rule);
	return (str);
}

static void	print_order(char *str, t_conv_rule rule, size_t *len)
{
	if (!(rule.format & F_MINUS) && (int)(*len) < rule.min_width)
		ft_putnchr(' ', rule.min_width - (int)(*len));
	ft_putstr_fd(str, 1);
	if ((rule.format & F_MINUS) && (int)(*len) < rule.min_width)
		ft_putnchr(' ', rule.min_width - (int)(*len));
	if ((int)(*len) < rule.min_width)
		(*len) = (size_t)rule.min_width;
}

static size_t	print_format(const char **format, va_list args)
{
	t_conv_rule		rule;
	char			*str;
	size_t			len;

	rule = detect_format(format);
	str = get_format_string(rule, args);
	if (!str)
		return (0);
	len = ft_strlen(str);
	print_order(str, rule, &len);
	free(str);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		if (i)
			ft_putnstr((char *)format, i);
		len += i;
		if (!format[i])
			break ;
		format += i + 1;
		len += print_format(&format, args);
	}
	va_end(args);
	return (len);
}
