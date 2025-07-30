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