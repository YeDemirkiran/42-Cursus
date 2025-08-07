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

// int		smallest_after_target_index_bs(int *arr, int size, int target)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size && arr[i] < target)
// 		i++;
// 	if (i == size)
// 		return (size);
// 	else
// 		return (i - 1);
// }

// 2 4 10 1 6 7 5 8 3 9

// t_lis	*get_lis(t_stack *stack, int size)
// {
// 	int		i;
// 	int		j;
// 	t_lis	lis;

// 	i = 0;
// 	lis.length = 0;
// 	lis.arr = malloc(sizeof(int) * size);
// 	while (i < size)
// 	{
// 		if (lis.length == 0)
// 			lis.arr[0] = stack[i].number;
// 		else
// 		{
// 			j = smallest_after_target_index_bs(lis.arr, lis.length, stack[i].number);
// 			if (j == lis.length)
// 				lis.arr[i] = stack[i].number;
// 			else
// 				lis.arr[j] = stack[i].number;
// 		}
// 		i++;
// 	}
// }

void	insertion_sort(t_stack_pair *pair, t_byte *instructions, int size)
{
	int		inst_index;
	int		chunk_border;
	int		current_border;
	int		i;
	t_stack	tmp;

	(void)size;
	if (is_stack_sorted(pair->stack_a, pair->a_length))
		return ;
	inst_index = 0;
	// while (pair->a_length > 1 && !is_stack_sorted(pair->stack_a, pair->a_length))
	// 	instructions[inst_index++] = stack_push_a_to_b(pair);
	chunk_border = pair->full_length / 5;
//	printf("BORDER: %i\n", chunk_border);
	current_border = 0;
	while (current_border < 5)
	{
		i = 0;
		while (i < chunk_border)
		{
			while (!(pair->stack_a[0].number >= chunk_border * current_border && pair->stack_a[0].number < chunk_border * (current_border + 1)))
			{
				//printf("a: %i\n", pair->stack_a[0].number);
				instructions[inst_index++] = stack_rotate_a(*pair);
			}
			instructions[inst_index++] = stack_push_a_to_b(pair);
			i++;
		}
		current_border++;
	}
	// while (!is_stack_sorted(pair->stack_a, pair->a_length))
	// {
	// 	while (pair->stack_a[1].number > pair->stack_a[0].number)
	// 		instructions[inst_index++] = stack_rotate_a(*pair);
	// 	while (pair->stack_a[1].number < pair->stack_a[0].number)
	// 		instructions[inst_index++] = stack_push_a_to_b(pair);
	// }
	while (pair->b_length)
	{
		if (is_biggest(pair->stack_a, pair->a_length, pair->stack_b[0].number))
		{
			tmp = get_biggest(pair->stack_a, pair->a_length);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			instructions[inst_index++] = stack_rotate_a(*pair);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		}
		else if (is_smallest(pair->stack_a, pair->a_length, pair->stack_b[0].number))
		{
			tmp = get_smallest(pair->stack_a, pair->a_length);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		}
		else
		{
			tmp = get_between(pair->stack_a, pair->a_length, pair->stack_b[0].number);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		}
	}
	tmp = get_smallest(pair->stack_a, pair->a_length);
	stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
}
