#include "libft.h"

size_t	ft_intlen(int n)
{
	unsigned int	un;
	size_t			len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	un = ft_abs(n);
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}