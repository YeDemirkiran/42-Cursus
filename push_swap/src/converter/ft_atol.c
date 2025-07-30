#include "converter.h"

long long	ft_atol(char *str)
{
	long long	total;
	char		sign;

	total = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (*str && ft_isdigit(*str))
	{
		total = (total * 10) + (*str - '0');
		str++;
	}
	return (total * sign);
}