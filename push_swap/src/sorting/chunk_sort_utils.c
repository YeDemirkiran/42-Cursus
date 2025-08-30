/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:28:49 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:28:50 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_sort.h"

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

void	get_cheapest_b(t_stack_pair *pair, t_stack arr[2])
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
