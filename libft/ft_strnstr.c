#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	len2;

	if (!*little)
		return ((char *) big);
	while (*big && len > 0)
	{
		i = 0;
		len2 = len--;
		while (little[i] && big[i] == little[i] && len2-- > 0)
			i++;
		if (little[i] == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
