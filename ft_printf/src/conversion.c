#include "libftprintf.h"

static char	*invert_string(char *str)
{
	size_t	len;
	size_t	i;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}		
	return (str);
}

char	*uint_to_hex(unsigned int n)
{
	char		*str;
	int			i;
	const char	*digits = "0123456789abcdef";

	str = ft_calloc(9, sizeof(char));
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
	return(invert_string(str));
}
