#include "libft.h"

void	ft_putnstr(char *s, size_t n)
{
	size_t len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	write(1, s, len);
}
