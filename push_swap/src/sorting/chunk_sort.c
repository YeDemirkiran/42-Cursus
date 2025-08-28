/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:39 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/26 13:12:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	push_chunks(t_stack_pair *pair, t_instructions *instructions)
{
	int			chunk_border;
	int	current_border;
	int			i;
	t_stack		tmp;

	chunk_border = pair->full_length / CHUNK_SIZE;
	current_border = 0;
	while (current_border <= CHUNK_SIZE)
	{
		i = 0;
		while (i < chunk_border)
		{
			if (current_border == CHUNK_SIZE && i >= pair->a_length % CHUNK_SIZE)
				break ;
			tmp = get_between(pair->stack_a, pair->a_length,
					chunk_border * current_border,
					chunk_border * (current_border + 1));
			stack_a_move_to_first(*pair, tmp, instructions);
			instructions->arr[instructions->index++] = stack_push_a_to_b(pair);
			i++;
		}
		current_border++;
	}
	// while (!is_stack_sorted(pair->stack_a, pair->a_length))
	// {
	// 	if (pair->stack_a[0].number > pair->stack_a[1].number && pair->stack_a[0].number > pair->stack_a[2].number)
	// 		instructions->arr[instructions->index++] = stack_swap_a(*pair);
	// 	else if (pair->stack_a[0].number > pair->stack_a[1].number)
	// 		instructions->arr[instructions->index++] = stack_rotate_a(*pair);
	// 	else
	// 		instructions->arr[instructions->index++] = stack_rotate_rev_a(*pair);
	// }
}

static t_stack	*get_cheapest_b(t_stack_pair *pair)
{
	int		current_cost;
	int		tmp_cost;
	int		tmp_index;
	t_stack	*target;
	int		i;
	int		j;

	current_cost = INT_MAX;
	target = malloc(sizeof(t_stack) * 2);
	if (!target)
		return (NULL);
	target[0].index = -1;
	target[1].index = -1;
	i = 0;
	while (i < pair->b_length)
	{
		tmp_index = get_place_before(pair->stack_a,
				pair->a_length, pair->stack_b[i].number).index;
		if (tmp_index == -1)
			break ;
		j = i;
		if (i > pair->b_length / 2)
			j = pair->b_length - i;
		tmp_cost = tmp_index + j;
		if (tmp_index > pair->a_length / 2)
			tmp_cost = pair->a_length - tmp_index + j;
		if (tmp_cost < current_cost)
		{
			current_cost = tmp_cost;
			target[0] = pair->stack_a[tmp_index];
			target[1] = pair->stack_b[i];
		}
		i++;
	}
	//printf("Cheapest a (n / i): %i %i, b (n / i): %i %i\n", target[0].number, target[0].index, target[1].number, target[1].index);
	return (target);
}

static void	sort_stack(t_stack_pair *pair, t_instructions *instructions)
{
	t_stack	*cheapest;

	while (pair->b_length)
	{
		cheapest = get_cheapest_b(pair);
		if (cheapest->index > -1)
			stack_ab_move_to_first(*pair, cheapest, instructions);
		free(cheapest);
		instructions->arr[instructions->index++] = stack_push_b_to_a(pair);
		if (pair->stack_a[0].number < pair->stack_a[1].number
			&& pair->stack_a[0].number
			< pair->stack_a[pair->a_length - 1].number)
			instructions->arr[instructions->index++] = stack_swap_a(*pair);
	}
}

void	chunk_sort(t_stack_pair *pair, t_instructions *instructions)
{
	t_stack	tmp;

	if (is_stack_sorted(pair->stack_a, pair->a_length))
		return ;
	push_chunks(pair, instructions);
	sort_stack(pair, instructions);
	tmp = get_smallest(pair->stack_a, pair->a_length);
	stack_a_move_to_first(*pair, tmp, instructions);
}
