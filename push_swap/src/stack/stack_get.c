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
	int	i;

	if (stack[0].number > target_num && stack[size - 1].number < target_num)
		return (stack[0]);
	i = 1;
	while (i < size)
	{
		if (stack[i].number > target_num && stack[i - 1].number < target_num)
			return (stack[i]);
		i++;
	}
	return (stack[i - 1]);
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
			break;
		}
		i++;
	}
	i = size - 1;
	while (i >= size / 2)
	{
		if (stack[i].number >= min && stack[i].number < max)
		{
			num_2 = stack[i];
			break;
		}
		i--;
	}
	if (num.index == -1 || (num.index > size - num_2.index))
		return (num_2);
	return (num);
}
