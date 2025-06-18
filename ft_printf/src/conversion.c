#include "libftprintf.h"

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
	return(ft_strinv(str));
}

char	*ulong_to_hex(unsigned long n)
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
	return(ft_strinv(str));
}
