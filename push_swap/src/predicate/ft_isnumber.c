#include "predicate.h"

int	ft_isnumber(char *str)
{
	if (*str == '\0')
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}