#include "libft.h"
#include <stdio.h>

static size_t	ft_smaller(size_t x, size_t y);

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_rmng;
	size_t	size;

	str_rmng = ft_strlen(str + start);
	size = ft_smaller(str_rmng, len) + 1;
	substr = malloc(size * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, str + start, size);
	return (substr);
}

static size_t	ft_smaller(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}
