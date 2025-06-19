#include "libftprintf.h"

size_t	print_len(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putnstr((char *)str, len);
	return (len);
}

static char	*char_rep(char c, size_t len)
{
	char	*str;

	if (!len)
		return (NULL);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		while (len-- > 0)
			str[len] = c;
	}
	return (str);
}

static char	*ft_strapp(char *str1, char *str2)
{
	char	*str;

	if (!str1 || !str2)
		return (NULL);
	str = ft_strjoin(str1, str2);
	if (str)
	{
		free(str1);
		free(str2);
	}
	return (str);
}

void	str_pad_char(char **str, char c, size_t amount)
{
	char	*tmp;

	tmp = char_rep(c, amount);
	*str = ft_strapp(tmp, *str);
	//*str = tmp;
}

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
		if (!(rule.format & F_MINUS))
		{
			if (rule.format & F_PLUS)
				str_pad_char(&str, '+', 1);
			else if (rule.format & F_SPACE)
				str_pad_char(&str, ' ', 1);
		}
	}
	return (str);
}

char	*convert_int(int num, t_conv_rule rule)
{
	char	*str;
	size_t	len;

	str = ft_utoa(ft_abs(num));
	if (!str)
		return (NULL);
	len = ft_strlen(str) + (num < 0);
	if (rule.format & F_ZERO && (int)len < rule.min_width)
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

char	*convert_hex(unsigned int num, t_conv_rule rule)
{
	char	*str;
	char	*tmp;
	size_t	len;

	if (!num)
		str = ft_strdup("0");
	else
	{
		str = uint_to_hex(num);
		if (!str)
			return (NULL);
		len = ft_strlen(str);
		if (rule.format & F_HASH)
			len += 2;
		if (rule.format & F_ZERO && (int)len < rule.min_width)
			str_pad_char(&str, '0', rule.min_width - len);
		if (rule.format & F_HASH)
		{
			tmp = ft_strjoin("0x", str);
			free(str);
			str = tmp;
		}
		if (rule.format & C_HEX_UP)
			ft_str_toupper(str);
	}
	return (str);
}
