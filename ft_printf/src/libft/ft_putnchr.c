#include "libft.h"

void	ft_putnchr(char c, size_t n)
{
	while (n-- > 0)
		write(1, &c, 1);
}
