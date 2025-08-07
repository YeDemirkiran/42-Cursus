#include "stack.h"

int		is_stack_sorted(t_stack *stack, int size)
{
	int	i;

	if (size <= 1)
		return (1);
	i = 1;
	while (i < size)
	{
		if (stack[i].number < stack[i - 1].number)
			return (0);
		i++;
	}
	return (1);
}

t_stack	find_smallest_index(t_stack *stack, int size)
{
	int		i;
	t_stack	smallest;

	i = 1;
	smallest = *stack;
	while (i < size)
	{
		if (stack[i].number < smallest.number)
			smallest = stack[i];
		i++;
	}
	return (smallest);
}
