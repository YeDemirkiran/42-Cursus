#include "stack.h"
#include "stdio.h"

void	stack_a_move_to_first(t_stack_pair pair, t_stack target, t_byte *instructions, int *inst_index)
{
	int	i;

	i = 0;
	while (i < pair.a_length)
	{
		if (pair.stack_a[i].number == target.number)
		{
			// printf("ANAAAAN\n");
			break ;
		}
		i++;
	}
	if (i == pair.a_length)
		return ;
	i = 0;
	while (pair.stack_a[0].number != target.number)
	{
		//printf("I BEFORE: %i\n", i);
		if (pair.a_length - target.index > target.index)
		{
			//printf("INST INDEX BEFORE: %i\n", *inst_index);
			instructions[(*inst_index)++] = stack_rotate_a(pair);
			//printf("INST INDEX NOW: %i\n", *inst_index);
		}
		else
		{
			//printf("INST INDEX BEFORE: %i\n", *inst_index);
			instructions[(*inst_index)++] = stack_rotate_rev_a(pair);
			//printf("INST INDEX NOW: %i\n", *inst_index);
		}
		i++;
		// printf("I: %i\n", i);
	}
	//printf("heheeh\n");
}