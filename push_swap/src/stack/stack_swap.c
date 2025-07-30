#include "stack.h"

void	stack_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack[0].number;
	stack[0].number = stack[1].number;
	stack[1].number = tmp;
}