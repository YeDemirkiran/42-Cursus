/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:49 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 13:10:50 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_a_move_to_first(t_stack_pair pair, t_stack target,
	t_instructions *instructions)
{
	int	i;

	i = 0;
	while (i < pair.a_length)
	{
		if (pair.stack_a[i].number == target.number)
			break ;
		i++;
	}
	if (i == pair.a_length)
		return ;
	i = 0;
	while (pair.stack_a[0].number != target.number)
	{
		if (pair.a_length - target.index > target.index)
			instructions->arr[instructions->index++] = stack_rotate_a(pair);
		else
			instructions->arr[instructions->index++] = stack_rotate_rev_a(pair);
		i++;
	}
}

void	stack_b_move_to_first(t_stack_pair pair, t_stack target,
	t_instructions *instructions)
{
	int	i;

	i = 0;
	while (i < pair.b_length)
	{
		if (pair.stack_b[i].number == target.number)
			break ;
		i++;
	}
	if (i == pair.b_length)
		return ;
	i = 0;
	while (pair.stack_b[0].number != target.number)
	{
		if (pair.b_length - target.index > target.index)
			instructions->arr[instructions->index++] = stack_rotate_b(pair);
		else
			instructions->arr[instructions->index++] = stack_rotate_rev_b(pair);
		i++;
	}

