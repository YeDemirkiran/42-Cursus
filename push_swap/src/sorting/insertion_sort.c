#include "sorting.h"

static	int	is_biggest(t_stack *stack, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (number < stack[i].number)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static	t_stack	get_biggest(t_stack *stack, int size)
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

void	insertion_sort(t_stack_pair *pair, t_byte *instructions, int size)
{
	int		inst_index;
	t_stack	tmp;

	(void)size;
	if (is_stack_sorted(pair->stack_a, pair->a_length))
		return ;
	inst_index = 0;
	while (TRUE)
	{
		while (pair->stack_a[1].number > pair->stack_a[0].number)
			instructions[inst_index++] = stack_rotate_a(*pair);
		while (pair->stack_a[1].number < pair->stack_a[0].number)
			instructions[inst_index++] = stack_push_a_to_b(pair);
		if (is_stack_sorted(pair->stack_a, pair->a_length))
			break ;
	}
	while (pair->b_length)
	{
		if (is_biggest(pair->stack_a, pair->a_length, pair->stack_b[0].number))
		{
			tmp = get_biggest(pair->stack_a, pair->a_length);
			while (pair->stack_a[0].number != tmp.number)
				stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
		}
		else
		{
			while (!(pair->stack_b[0].number < pair->stack_a[1].number && pair->stack_b[0].number > pair->stack_a[0].number))
				instructions[inst_index++] = stack_rotate_a(*pair);
		}
		instructions[inst_index++] = stack_rotate_a(*pair);
		instructions[inst_index++] = stack_push_b_to_a(pair);
	}
	tmp = find_smallest_index(pair->stack_a, pair->a_length);
	while (pair->stack_a[0].number != tmp.number)
		stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
}
