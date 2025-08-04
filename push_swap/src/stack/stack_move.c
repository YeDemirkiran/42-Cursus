#include "stack.h"
#include "stdio.h"

void	stack_a_move_to_first(t_stack_pair pair, t_stack target, t_byte *instructions, int *inst_index)
{
	while (pair.stack_a[0].number != target.number)
	{
		//printf("ANAAAN\n");
		if (pair.a_length - target.index > target.index)
			instructions[*inst_index++] = stack_rotate_a(pair);
		else
			instructions[*inst_index++] = stack_rotate_rev_a(pair);
	}
}