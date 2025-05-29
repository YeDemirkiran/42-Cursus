#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*last;

	last = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			last = str;
		str++;
	}
	if (*str == c)
		last = str;
	return (last);
}
