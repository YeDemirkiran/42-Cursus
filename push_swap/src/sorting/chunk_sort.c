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
	int		chunk_border;
	int		current_border;
	int		i;
	t_stack	tmp;

	chunk_border = pair->full_length / CHUNK_SIZE;
	current_border = 0;
	while (current_border <= CHUNK_SIZE)
	{
		i = 0;
		while (i < chunk_border)
		{
			if (current_border == CHUNK_SIZE
				&& i >= pair->a_length % CHUNK_SIZE)
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
}

// while (!is_stack_sorted(pair->stack_a, pair->a_length))
// {
// 	if (pair->stack_a[0].number > pair->stack_a[1].number
//&& pair->stack_a[0].number > pair->stack_a[2].number)
// 		instructions->arr[instructions->index++] = stack_swap_a(*pair);
// 	else if (pair->stack_a[0].number > pair->stack_a[1].number)
// 		instructions->arr[instructions->index++] = stack_rotate_a(*pair);
// 	else
// 		instructions->arr[instructions->index++] = stack_rotate_rev_a(*pair);
// }

// static int	calculate_cost(t_stack_pair *pair, int i, int *cheapest_index)
// {
// 	int	cost;
// 	int	j;

// 	*cheapest_index = get_place_before(pair->stack_a,
// 			pair->a_length, pair->stack_b[i].number).index;
// 	if (*cheapest_index < 0)
// 		return (*cheapest_index);
// 	j = i;
// 	if (i > pair->b_length / 2)
// 		j = pair->b_length - i;
// 	cost = *cheapest_index + j;
// 	if (cost - j > pair->a_length / 2)
// 		cost = pair->a_length - cost;
// 	return (cost);
//}

static int	calculate_cost(t_stack_pair *pair, int i, int *tmp_index)
{
	int	cost;
	int	j;

	*tmp_index = get_place_before(pair->stack_a,
			pair->a_length, pair->stack_b[i].number).index;
	if (*tmp_index < 0)
		return (-1);
	j = i;
	if (i > pair->b_length / 2)
		j = pair->b_length - i;
	cost = *tmp_index + j;
	if (*tmp_index > pair->a_length / 2)
		cost = pair->a_length - *tmp_index + j;
	return (cost);
}

static void	get_cheapest_b(t_stack_pair *pair, t_stack arr[2])
{
	int		current_cost;
	int		tmp_cost;
	int		tmp_index;
	int		i;

	current_cost = INT_MAX;
	arr[0].index = -1;
	arr[1].index = -1;
	i = 0;
	while (i < pair->b_length)
	{
		tmp_cost = calculate_cost(pair, i, &tmp_index);
		if (tmp_cost < 0)
			break ;
		if (tmp_cost < current_cost)
		{
			current_cost = tmp_cost;
			arr[0] = pair->stack_a[tmp_index];
			arr[1] = pair->stack_b[i];
		}
		i++;
	}
}

static void	sort_stack(t_stack_pair *pair, t_instructions *instructions)
{
	t_stack	cheapest[2];

	while (pair->b_length)
	{
		get_cheapest_b(pair, cheapest);
		if (cheapest->index > -1)
			stack_ab_move_to_first(*pair, cheapest, instructions);
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
