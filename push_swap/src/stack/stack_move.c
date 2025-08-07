#include "stack.h"

void	stack_a_move_to_first(t_stack_pair pair, t_stack target, t_byte *instructions, int *inst_index)
{
	int	i;

	i = 0;
	while (i < pair.a_length)
	{
		if (pair.stack_a[i].number == target.number)
			break ;
		i++;
	}
	if (i == pair.a_length)
		return ;
	i = 0;
	while (pair.stack_a[0].number != target.number)
	{
		if (pair.a_length - target.index > target.index)
			instructions[(*inst_index)++] = stack_rotate_a(pair);
		else
			instructions[(*inst_index)++] = stack_rotate_rev_a(pair);
		i++;
	}
}
