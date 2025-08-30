/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:39 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 17:07:37 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_sort.h"

static void	sort_three(t_stack_pair *pair, t_instructions *instructions)
{
	while (pair->a_length == 3
		&& !is_stack_sorted(pair->stack_a, pair->a_length))
	{
		if (pair->stack_a[0].number > pair->stack_a[1].number
			&& pair->stack_a[0].number > pair->stack_a[2].number)
			instructions->arr[instructions->index++] = stack_rotate_a(*pair);
		else if (pair->stack_a[0].number > pair->stack_a[1].number)
			instructions->arr[instructions->index++] = stack_swap_a(*pair);
		else
			instructions->arr[instructions->index++]
				= stack_rotate_rev_a(*pair);
	}
}

static void	push_chunks(t_stack_pair *pair,
	t_instructions *instructions, int chunk_size)
{
	int		chunk_border;
	int		current_border;
	int		i;
	t_stack	tmp;

	chunk_border = pair->full_length
		/ ((chunk_size * (chunk_size <= pair->full_length))
			+ (chunk_size > pair->full_length));
	current_border = -1;
	while (++current_border <= chunk_size && pair->a_length > 3)
	{
		i = -1;
		while (++i < chunk_border && pair->a_length > 3)
		{
			if (current_border == chunk_size
				&& i >= pair->a_length % chunk_size)
				break ;
			tmp = get_between(pair->stack_a, pair->a_length,
					chunk_border * current_border,
					chunk_border * (current_border + 1));
			stack_a_move_to_first(*pair, tmp, instructions);
			instructions->arr[instructions->index++] = stack_push_a_to_b(pair);
		}
	}
	sort_three(pair, instructions);
}

static void	sort_stack_b(t_stack_pair *pair, t_instructions *instructions)
{
	t_stack	cheapest[2];

	while (pair->b_length)
	{
		get_cheapest_b(pair, cheapest);
		if (cheapest->index > -1)
			stack_ab_move_to_first(*pair, cheapest, instructions);
		instructions->arr[instructions->index++] = stack_push_b_to_a(pair);
		if (is_smallest(pair->stack_a, pair->a_length, pair->stack_a[0].number)
			&& is_biggest(pair->stack_a, pair->a_length,
				pair->stack_a[1].number))
			instructions->arr[instructions->index++] = stack_swap_a(*pair);
	}
}

static int	push_sort_chunk(t_stack_pair *pair,
	t_instructions *instructions, int chunk_size)
{
	t_stack_pair	tmp_pair;
	t_stack			tmp;
	int				result;

	tmp_pair = duplicate_pair(pair);
	push_chunks(&tmp_pair, instructions, chunk_size);
	sort_stack_b(&tmp_pair, instructions);
	tmp = get_smallest(tmp_pair.stack_a, tmp_pair.a_length);
	stack_a_move_to_first(tmp_pair, tmp, instructions);
	result = is_stack_sorted(tmp_pair.stack_a, tmp_pair.a_length);
	clear_pair(&tmp_pair);
	return (result);
}

void	chunk_sort(t_stack_pair *pair, t_instructions *instructions)
{
	t_instructions	tmp_insts[MAX_CHUNK_SIZE];
	int				i;
	int				inst_len;
	int				chosen_inst_index;

	if (!init_instructions(tmp_insts, MAX_CHUNK_SIZE))
		return ;
	i = 0;
	inst_len = INT_MAX;
	while (i + 1 <= MAX_CHUNK_SIZE)
	{
		if (push_sort_chunk(pair, tmp_insts + i, i + 1)
			&& tmp_insts[i].index < inst_len)
		{
			inst_len = tmp_insts[i].index;
			chosen_inst_index = i;
		}
		i++;
	}
	*instructions = tmp_insts[chosen_inst_index];
	clear_instructions(tmp_insts, MAX_CHUNK_SIZE, chosen_inst_index);
}
