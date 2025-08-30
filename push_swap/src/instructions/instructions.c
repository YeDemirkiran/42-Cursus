#include "instructions.h"

int	init_instructions(t_instructions *inst_arr, int length)
{
	int	i;
	int	clear;

	i = 0;
	clear = 0;
	while (i < length)
	{
		inst_arr[i].arr = malloc(sizeof(t_byte) * INSTRUCTIONS_SIZE);
		if (!inst_arr[i].arr)
		{
			clear = 1;
			i--;
			break ;
		}
		inst_arr[i].index = 0;
		i++;
	}
	if (clear)
	{
		while (i >= 0)
			free (inst_arr[i--].arr);
		return (0);
	}
	return (1);
}

void	clear_instructions(t_instructions *inst_arr,
	int length, int preserve_index)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		if (i == preserve_index)
			continue ;
		free(inst_arr[i].arr);
	}
}
