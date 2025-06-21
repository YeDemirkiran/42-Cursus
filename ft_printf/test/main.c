#include "main.h"


int	main(void)
{
	int	res;

	res = printf("[%2d]", 42);
	printf(" (res: %i)\n", res);
	res = ft_printf("[%2d]", 42);
	printf(" (res: %i)\n", res);

	return (0);
}
