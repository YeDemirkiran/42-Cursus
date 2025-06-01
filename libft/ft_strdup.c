#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = sizeof(char) * (ft_strlen(s) + 1);
	str = (char *)malloc(len);
	ft_bzero(str, len);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len);
	return (str);
}
