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
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*convert_int(int num, t_conv_rule rule)
{
	char	*str;
	size_t	len;

	str = ft_utoa(ft_abs(num));
	if (!str)
		return (NULL);
	len = ft_strlen(str) + (num < 0);
	if ((rule.format & F_ZERO) && ((int)len < rule.min_width))
		str_pad_char(&str, '0', rule.min_width - len);
	if (num > 0 && !(rule.format & F_MINUS))
	{
		if (rule.format & F_PLUS)
			str_pad_char(&str, '+', 1);
		else if (rule.format & F_SPACE)
			str_pad_char(&str, ' ', 1);
	}
	else if (num < 0)
		str_pad_char(&str, '-', 1);
	return (str);
}

char	*convert_uint(unsigned int num, t_conv_rule rule)
{
	char	*str;
	size_t	len;

	str = ft_utoa(num);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (rule.format & F_ZERO && (int)len < rule.min_width)
		str_pad_char(&str, '0', rule.min_width - len);
	return (str);
}
