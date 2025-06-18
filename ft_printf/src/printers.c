#include "libftprintf.h"

char	*convert_char(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	*str = c;
	return (str);
}

char	*convert_string(char *str)
{
	if (!str)
		str = ft_strdup("(null)");
	return (ft_strdup(str));
}

char	*convert_pointer(void *p, t_conv_rule rule)
{
	char	*str;

	(void)rule;
	if (!p)
		str = ft_strdup("(nil)");
	else
		str = ulong_to_hex((unsigned long)p);
	// if (p)
	// 	len += print_string("0x");
	// if (!(rule.format & F_MINUS) && (int)len < rule.min_width)
	// {
	// 	if (rule.format & F_ZERO)
	// 		ft_putnchr('0', rule.min_width - len);
	// 	len = rule.min_width;
	// }
	return (str);
}

char	*convert_int(int num, t_conv_rule rule)
{
	char	*str;

	str = ft_itoa((int)num);
	if (num > 0 && (rule.format & (F_PLUS | F_SPACE)))
	{
		if (rule.format & F_PLUS)
			ft_putchar_fd('+', 1);
		else if (rule.format & F_SPACE)
			ft_putchar_fd(' ', 1);
	}
	return (str);
}
