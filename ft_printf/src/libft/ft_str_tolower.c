#include "libft.h"

char	*ft_str_tolower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (str);
}
