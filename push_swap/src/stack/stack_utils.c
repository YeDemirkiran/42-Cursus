/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 12:11:54 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	is_stack_sorted(t_stack *stack, int size)
{
	int	i;

	if (size <= 1)
		return (1);
	i = 1;
	while (i < size)
	{
		if (stack[i].number < stack[i - 1].number)
			return (0);
		i++;
	}
	return (1);
}

t_stack	find_smallest_index(t_stack *stack, int size)
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

t_stack	*duplicate_stack(t_stack *stack, int full_length)
{
	t_stack	*dup;
	int		i;

	dup = malloc(sizeof(t_stack) * full_length);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < full_length)
	{
		dup[i].index = stack[i].index;
		dup[i].number = stack[i].number;
		dup[i].real_number = stack[i].real_number;
		i++;
	}
	return (dup);
}

int	index_stack(t_stack *stack_a, int length)
{
	t_stack	*sorted;
	int		i;
	int		j;

	sorted = duplicate_stack(stack_a, length);
	if (!sorted)
		return (0);
	insertion_sort(sorted, length);
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (sorted[j].real_number == stack_a[i].real_number)
			{
				stack_a[i].number = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
	return (1);
}
