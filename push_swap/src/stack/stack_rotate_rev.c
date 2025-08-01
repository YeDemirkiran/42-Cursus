#include "stack.h"

void	stack_rotate_rev(t_stack *stack, int size)
{
	int	i;
	int	tmp;

	tmp = stack[size - 1].number;
	i = size - 2;
	while (i >= 0)
	{
		stack[i + 1].number = stack[i].number;
		i--;
	}
	stack[i + 1].number = tmp;
}

int	stack_rotate_rev_a(t_stack_pair pair)
{
	stack_rotate_rev(pair.stack_a, pair.a_length);
	return (INST_RROT_A);
}

int	stack_rotate_rev_b(t_stack_pair pair)
{
	stack_rotate_rev(pair.stack_b, pair.b_length);
	return (INST_RROT_B);
}
