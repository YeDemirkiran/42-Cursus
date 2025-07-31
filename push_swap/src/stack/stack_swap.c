#include "stack.h"

void	stack_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack[0].number;
	stack[0].number = stack[1].number;
	stack[1].number = tmp;
}

int	stack_swap_a(t_stack_pair *pair)
{
	stack_swap(pair->stack_a);
	return (INST_SWAP_A);
}

int	stack_swap_b(t_stack_pair *pair)
{
	stack_swap(pair->stack_b);
	return (INST_SWAP_B);
}
