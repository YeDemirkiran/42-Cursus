/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:42 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 13:10:43 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	custom_sort(t_stack_pair *pair, t_byte *instructions, int size)
{
	int	inst_index;
	
	inst_index = 0;
	while (pair->b_length < pair->full_length / 2)
	{
		while (pair->stack_a[0].number < pair->stack_a[1].number)
			instructions[inst_index++] = stack_rotate_a(*pair);
		instructions[inst_index++] = stack_push_a_to_b(pair);
    	instructions[inst_index++] = stack_push_a_to_b(pair);
		while (pair->stack_a[0].number < pair->stack_a[1].number)
			instructions[inst_index++] = stack_rotate_a(*pair);
		if (pair->stack_b[0].number < pair->stack_b[1].number)
			if (pair->stack_a[0].number > pair->stack_a[1].number)
				instructions[inst_index++] = stack_swap_ab(*pair);
			else
				instructions[inst_index++] = stack_swap_b(*pair);
		else if (pair->stack_a[0].number > pair->stack_a[1].number)
			instructions[inst_index++] = stack_swap_b(*pair);
		// if (pair->stack_b[0].number < pair->stack_a[0].number && pair->stack_b[0].number > pair->stack_a[pair->a_length - 1].number)
		// 	instructions[inst_index++] = stack_push_b_to_a(pair);
	}
}
