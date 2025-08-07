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

static	int	is_smallest(t_stack *stack, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (number > stack[i].number)
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

static	t_stack	get_smallest(t_stack *stack, int size)
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

static	t_stack	get_between(t_stack *stack, int size, int target_num)
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
	//printf("WAAAAAA\n");
	while (pair->b_length)
	{
		if (is_biggest(pair->stack_a, pair->a_length, pair->stack_b[0].number))
		{
		//	printf("BIGGEST: %i\n", pair->stack_b[0].number);
			tmp = get_biggest(pair->stack_a, pair->a_length);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			//printf("0 before: %i\n", pair->stack_a[0].number);
			instructions[inst_index++] = stack_rotate_a(*pair);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		//	printf("0 now: %i\n", pair->stack_a[0].number);
		}
		else if (is_smallest(pair->stack_a, pair->a_length, pair->stack_b[0].number))
		{
			//printf("SMALLEST: %i\n", pair->stack_b[0].number);
			tmp = get_smallest(pair->stack_a, pair->a_length);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		}
		else
		{
			//printf("NORMAL: %i\n", pair->stack_b[0].number);
			tmp = get_between(pair->stack_a, pair->a_length, pair->stack_b[0].number);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			// while (!(pair->stack_b[0].number < pair->stack_a[1].number && pair->stack_b[0].number > pair->stack_a[0].number))
			// {
			// 	//printf("B[0]. %i, A[0]: %i, A[1]: %i\n", pair->stack_b[0].number, pair->stack_a[0].number, pair->stack_a[1].number);
			// 	instructions[inst_index++] = stack_rotate_a(*pair);
			// }
			//instructions[inst_index++] = stack_rotate_a(*pair);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		}
	}
	tmp = find_smallest_index(pair->stack_a, pair->a_length);
	//printf("WOOOOO\n");
	while (pair->stack_a[0].number != tmp.number)
		stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
}
