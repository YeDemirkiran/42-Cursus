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

static void	push_chunks(t_stack_pair *pair, t_byte *instructions,
	int *inst_index)
{
	int		chunk_border;
	int		current_border;
	int		i;
	t_stack	tmp;

	chunk_border = pair->full_length / 10;
	current_border = 0;
	while (current_border < 10)
	{
		i = 0;
		while (i < chunk_border)
		{
			tmp = get_between(pair->stack_a, pair->a_length,
					chunk_border * current_border,
					chunk_border * (current_border + 1));
			stack_a_move_to_first(*pair, tmp, instructions, inst_index);
			instructions[(*inst_index)++] = stack_push_a_to_b(pair);
			i++;
		}
		current_border++;
	}
}

static t_stack	smallest_or_biggest(t_stack_pair *pair)
{
	t_stack	tmp;

	tmp.index = -1;
	if (is_biggest(pair->stack_a, pair->a_length, pair->stack_b[0].number))
		tmp = get_biggest(pair->stack_a, pair->a_length);
	else if (is_smallest(pair->stack_a, pair->a_length,
			pair->stack_b[0].number))
		tmp = get_smallest(pair->stack_a, pair->a_length);
	return (tmp);
}

static void	sort_stack(t_stack_pair *pair, t_byte *instructions,
	int *inst_index)
{
	t_stack	tmp;

	while (pair->b_length)
	{
		tmp = smallest_or_biggest(pair);
		if (tmp.index == -1)
			tmp = get_place_before(pair->stack_a, pair->a_length,
					pair->stack_b[0].number);
		stack_a_move_to_first(*pair, tmp, instructions, inst_index);
		instructions[(*inst_index)++] = stack_push_b_to_a(pair);
		if (pair->stack_a[0].number > pair->stack_a[1].number
			&& pair->stack_a[0].number > pair->stack_a[pair->a_length - 1].number)
			instructions[(*inst_index)++] = stack_swap_a(*pair);
	}
}

void	chunk_sort(t_stack_pair *pair, t_byte *instructions)
{
	int		inst_index;
	t_stack	tmp;

	if (is_stack_sorted(pair->stack_a, pair->a_length))
		return ;
	inst_index = 0;
	push_chunks(pair, instructions, &inst_index);
	sort_stack(pair, instructions, &inst_index);
	tmp = get_smallest(pair->stack_a, pair->a_length);
	stack_a_move_to_first(*pair, tmp, instructions, &inst_index);
}
