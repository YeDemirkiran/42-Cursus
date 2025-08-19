#include "so_long.h"

int	is_full_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != OBJ_WALL_CHAR)
			return (0);
		i++;
	}
	return (1);
}

int	is_enclosed_wall(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	return (str[0] == OBJ_WALL_CHAR && str[len - 1] == OBJ_WALL_CHAR);
}