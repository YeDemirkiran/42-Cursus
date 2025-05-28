#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == (void *)0 && src == (void *)0)
		return (dest);

	while (n-- > 0)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
