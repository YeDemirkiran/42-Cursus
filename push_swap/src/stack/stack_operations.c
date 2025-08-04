#include "stack.h"

// t_stack find_previous_by_index(t_stack *stack, int stack_size, int index)
// {
// 	if (index == 0)
// 		return (stack[stack_size - 1]);
// 	else
// 		return (stack[index - 1]);
// }

// t_stack find_next_by_index(t_stack *stack, int stack_size, int index)
// {
// 	if (index == stack_size - 1)
// 		return (stack[0]);
// 	else
// 		return (stack[index + 1]);
// }

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
