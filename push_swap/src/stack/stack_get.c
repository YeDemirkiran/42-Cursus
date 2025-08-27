#include "stack.h"

t_stack	get_biggest(t_stack *stack, int size)
{
	int		i;
	t_stack	num;

	if (size <= 1)
		return (stack[0]);
	i = 1;
	num = stack[0];
	while (i < size)
	{
		if (num.number < stack[i].number)
			num = stack[i];
		i++;
	}
	return (num);
}

t_stack	get_smallest(t_stack *stack, int size)
{
	int		i;
	t_stack	num;

	if (size <= 1)
		return (stack[0]);
	i = 1;
	num = stack[0];
	while (i < size)
	{
		if (num.number > stack[i].number)
			num = stack[i];
		i++;
	}
	return (num);
}

t_stack	get_place_before(t_stack *stack, int size, int target_num)
{
	int		i;
	t_stack	stack_1;

	stack_1.index = -1;
	stack_1.number = -1;
	i = 1;
	while (i < size)
	{
		if (stack[i].number > target_num && stack[i - 1].number < target_num && (stack_1.index == -1 || size - stack[i].index <= stack_1.index))
		{
			stack_1 = stack[i];
		}
		i++;
	}
	return (stack_1);
}

static t_stack	get_between_last_half(t_stack *stack,
	int size, int min, int max)
{
	int		i;
	t_stack	target_stack;

	i = size - 1;
	target_stack.index = -1;
	while (i >= size / 2)
	{
		if (stack[i].number >= min && stack[i].number < max)
			return (stack[i]);
		i--;
	}
	return (target_stack);
}

t_stack	get_between(t_stack *stack, int size, int min, int max)
{
	int		i;
	t_stack	num;
	t_stack	num_2;

	i = 0;
	num.index = -1;
	num_2.index = -1;
	while (i < size / 2)
	{
		if (stack[i].number >= min && stack[i].number < max)
		{
			num = stack[i];
			break ;
		}
		i++;
	}
	num_2 = get_between_last_half(stack, size, min, max);
	if (num.index == -1 || (num.index > size - num_2.index))
		return (num_2);
	return (num);
}
