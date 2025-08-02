/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:52:21 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 15:34:15 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "write.h"
#include "stdio.h"

static t_stack	find_smallest_index(t_stack *stack, int size)
{
	int		i;
	t_stack	smallest;

	i = 1;
	smallest = *stack;
	while (i < size)
	{
		if (stack[i].number < smallest.number)
			smallest = stack[i];
		i++;
	}
	return (smallest);
}

void	push_sort(t_stack_pair *pair, t_byte *instructions, int size)
{
	int		inst_index;
	t_stack	smallest;

	inst_index = 0;
	while (pair->a_length)
	{
		smallest = find_smallest_index(pair->stack_a, size);
		while (pair->stack_a[0].number != smallest.number)
		{
			if (size - smallest.index > smallest.index)
				instructions[inst_index++] = stack_rotate_a(*pair);
			else
				instructions[inst_index++] = stack_rotate_rev_a(*pair);
		}		
		instructions[inst_index++] = stack_push_a_to_b(pair);
		size--;
	}
	while (pair->b_length)
		instructions[inst_index++] = stack_push_b_to_a(pair);
}
