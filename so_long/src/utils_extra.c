#include "so_long.h"

void	destroy_object(t_object *buffer, int index)
{
	int	i;

	i = index;
	buffer[i].sprite = NULL;
	while (buffer[i + 1].sprite)
	{
		buffer[i] = buffer[i + 1];
		i++;
	}
	buffer[i].sprite = NULL;
}
