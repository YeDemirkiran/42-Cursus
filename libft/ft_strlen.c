#include "libft.h"

size_t	ft_strlen(const char *c)
{
	int	count;

	count = 0;
	while (*c++ != 0)
		count++;
	return (count);
}
