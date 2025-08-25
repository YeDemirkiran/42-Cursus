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

void	chunk_sort(t_stack_pair *pair, t_byte *instructions, int size)
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
			tmp = get_between(pair->stack_a, pair->a_length, chunk_border * current_border, chunk_border * (current_border + 1));
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
			tmp = get_place_before(pair->stack_a, pair->a_length, pair->stack_b[0].number);
			stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
			instructions[inst_index++] = stack_push_b_to_a(pair);
		}
	}
	tmp = get_smallest(pair->stack_a, pair->a_length);
	stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
}
