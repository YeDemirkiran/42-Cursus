#include "libft.h"

char	*ft_str_toupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}	
	return (str);
}
