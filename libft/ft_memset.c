#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_char;

	i = 0;
	temp_char = (unsigned char *)s;
	while (i++ < n)
		*(temp_char++) = (unsigned char) c;
	return (s);
}
