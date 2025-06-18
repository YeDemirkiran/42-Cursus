#include "libft.h"

size_t	ft_uintlen(unsigned int n)
{
	size_t			len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
