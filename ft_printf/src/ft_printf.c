#include "libftprintf.h"

// FLAGS: '+-0 #' (yes, space)
static int	is_flag(const char c)
{
	int	flag;

	flag = 0;
	if (c == '+')
		flag = F_PLUS;
	else if (c == '-')
		flag = F_MINUS;
	else if (c == '0')
		flag = F_ZERO;
	else if (c == ' ')
		flag = F_SPACE;
	else if (c == '#')
		flag = F_HASH;
	return (flag);
}

// FORMATS: 'cspdiuxX%'
static int	is_formspec(const char c)
{
	int	flag;

	flag = 0;
	if (c == 'c')
		flag = C_CHAR;
	else if (c == 's')
		flag = C_STR;
	else if (c == 'p')
		flag = C_POINTER;
	else if (c == 'd' || c == 'i')
		flag = C_INT;
	else if (c == 'u')
		flag = C_UINT;
	else if (c == 'x')
		flag = C_HEX_LOW;
	else if (c == 'X')
		flag = C_HEX_UP;
	else if (c == '%')
		flag = C_PERCENT;
	return (flag);
}

// %-#50.50x
static t_conv_rule	detect_format(const char *str)
{
	t_conv_rule	rule;

	rule.format = 0;
	rule.min_width = 0;
	rule.max_width = -1;
	while (is_flag(*str))
		rule.format |= is_flag(*str++);
	while (ft_isdigit(*str))
	{
		rule.min_width *= 10;
		rule.min_width += *str++ - '0';
	}
	if (*str == '.')
	{
		str++;
		rule.max_width = 0;
		while (ft_isdigit(*str))
		{
			rule.max_width *= 10;
			rule.max_width += *str++ - '0';
		}
	}
	rule.format |= is_formspec(*str);
	return (rule);
}

static size_t	print_format(const char *format, va_list args)
{
	t_conv_rule	rule;
	char		*tmp;

	rule = detect_format(format);
	if (rule.format & C_HEX_LOW)
	{
		tmp = uint_to_hex(va_arg(args, unsigned int));
		if (!tmp)
			return (0);
		if (rule.format & F_HASH)
			ft_putstr_fd("0x", 1);
		if ((int)ft_strlen(tmp) < rule.min_width && !(rule.format & F_MINUS))
		{
			if (rule.format & F_ZERO)
				ft_putnchr('0', rule.min_width - ft_strlen(tmp));
			else
				ft_putnchr(' ', rule.min_width - ft_strlen(tmp));
		}
		// if (rule.max_width >= 0)
		// 	ft_putnstr(tmp, rule.max_width);
		// else
		ft_putstr_fd(tmp, 1);
		if ((int)ft_strlen(tmp) < rule.min_width && (rule.format & F_MINUS))
			ft_putnchr(' ', rule.min_width - ft_strlen(tmp));
		free(tmp);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	//char	*str;
	size_t	i;
	size_t	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		ft_putnstr((char *)format, i);
		len += i;
		if (!format[i])
			break ;
		format += len;
		len += print_format(format + 1, args);
	}
	return (len);
}
