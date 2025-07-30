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