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

char	*convert_string(char *str, t_conv_rule rule)
{
	char	*new;
	size_t	len;

	if (!str)
		new = ft_strdup("(null)");
	else if (rule.max_width > 0)
	{
		len = ft_smaller((size_t)rule.max_width, ft_strlen(str)) + 1;
		new = malloc(len);
		ft_strlcpy(new, str, len);
	}
	else if (rule.max_width == 0)
		new = NULL;
	else
		new = ft_strdup(str);
	return (new);
}

char	*convert_int(int num, t_conv_rule rule)
{
	char	*str;
	size_t	len;
	int		consider_sign;

	if (rule.max_width == 0 && !num)
		return (NULL);
	str = ft_utoa(ft_abs(num));
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	consider_sign = (num < 0 || rule.format & (F_PLUS | F_SPACE));
	if ((int)len < rule.max_width)
		str_pad_char(&str, '0', rule.max_width - len);
	else if (rule.format & F_ZERO && ((int)len) + consider_sign < rule.min_width)
		str_pad_char(&str, '0', rule.min_width - len - consider_sign);
	if (num > 0)
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

	if (rule.max_width == 0 && !num)
		return (NULL);
	str = ft_utoa(num);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if ((int)len < rule.max_width)
		str_pad_char(&str, '0', rule.max_width - len);
	else if (rule.format & F_ZERO && (int)len < rule.min_width)
		str_pad_char(&str, '0', rule.min_width - len);
	return (str);
}
