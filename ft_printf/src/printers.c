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
	else
	{
		len = 6;
		ft_putstr_fd("(null)", 1);
	}
	return (len);
}

size_t	print_pointer(void *p, t_conv_rule rule)
{
	char	*str;
	size_t	len;

	if (!p)
		str = ft_strdup("(nil)");
	else
		str = ulong_to_hex((unsigned long)p);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (p)
		len += print_string("0x");
	if (!(rule.format & F_MINUS) && (int)len < rule.min_width)
	{
		if (rule.format & F_ZERO)
			ft_putnchr('0', rule.min_width - len);
		len = rule.min_width;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
