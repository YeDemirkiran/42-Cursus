/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:39 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 13:10:40 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static	t_stack	get_between_closest(t_stack *stack, int size, int min, int max)
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
	int		chunk_border;
	int		current_border;
	int		i;
	t_stack	tmp;

	(void)size;
	if (is_stack_sorted(pair->stack_a, pair->a_length))
		return ;
	inst_index = 0;
	chunk_border = pair->full_length / 10;
	current_border = 0;
	while (current_border < 10)
	{
		i = 0;
		while (i < chunk_border)
		{
			tmp = get_between_closest(pair->stack_a, pair->a_length, chunk_border * current_border, chunk_border * (current_border + 1));
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			instructions[inst_index++] = stack_push_a_to_b(pair);
			i++;
		}
		current_border++;
	}
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
