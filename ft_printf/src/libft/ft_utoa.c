#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	size_t			digits;

	digits = ft_uintlen(n);
	str = malloc((digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digits--] = 0;
	while (digits-- > 0)
	{
		str[digits] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
