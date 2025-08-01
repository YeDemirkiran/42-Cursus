#include "stack.h"

void	stack_rotate(t_stack *stack, int size)
{
	int	i;
	int	tmp;

	tmp = stack[0].number;
	i = 1;
	while (i < size)
	{
		stack[i - 1].number = stack[i].number;
		i++;
	}
	stack[i - 1].number = tmp;
}

int	stack_rotate_a(t_stack_pair pair)
{
	stack_rotate(pair.stack_a, pair.a_length);
	return (INST_ROT_A);
}

int	stack_rotate_b(t_stack_pair pair)
{
	stack_rotate(pair.stack_b, pair.b_length);
	return (INST_ROT_B);
}
