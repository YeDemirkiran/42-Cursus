#include "libftprintf.h"

static char	*ulong_to_hex(unsigned long n)
{
	char		*str;
	int			i;
	const char	*digits = "0123456789abcdef";

	str = ft_calloc(17, sizeof(char));
	if (!n)
	{
		str[0] = '0';
		return (str);
	}
	i = 0;
	while (n > 0)
	{
		str[i++] = digits[n % 16];
		n /= 16;
	}
	str[i] = 0;
	return (ft_strinv(str));
}

static char	*uint_to_hex(unsigned int n)
{
	return (ulong_to_hex((unsigned long)n));
}

char	*convert_hex(unsigned int num, t_conv_rule rule)
{
	char	*str;
	char	*tmp;
	size_t	len;

	if (!num)
		str = ft_strdup("0");
	else
		str = uint_to_hex(num);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (num && (rule.format & F_HASH))
		len += 2;
	if (rule.format & F_ZERO && (int)len < rule.min_width)
		str_pad_char(&str, '0', rule.min_width - len);
	if (num && rule.format & F_HASH)
	{
		tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	if (num && rule.format & C_HEX_UP)
		ft_str_toupper(str);
	return (str);
}

char	*convert_pointer(void *p, t_conv_rule rule)
{
	char	*str;
	char	*tmp;
	size_t	len;

	if (!p)
		str = ft_strdup("(nil)");
	else
	{
		str = ulong_to_hex((unsigned long)p);
		if (!str)
			return (NULL);
		len = ft_strlen(str) + 2;
		if (rule.format & F_ZERO && (int)len < rule.min_width)
			str_pad_char(&str, '0', rule.min_width - len);
		tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
		if ((rule.format & F_PLUS) && !(rule.format & F_MINUS))
			str_pad_char(&str, '+', 1);
		else if (rule.format & F_SPACE && !(rule.format & F_MINUS))
			str_pad_char(&str, ' ', 1);
	}
	return (str);
}
