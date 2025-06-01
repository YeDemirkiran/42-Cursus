#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;

	src_len = ft_strlen(src);
	if (size <= 0 || src_len <= 0)
		return (src_len);
	while ((size--) - 1 > 0 && *src)
	{
		*dst++ = *((char *)src++);
	}
	*dst = 0;
	return (src_len);
}
