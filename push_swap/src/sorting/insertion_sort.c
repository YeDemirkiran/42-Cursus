/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:28:54 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:28:55 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertion_sort.h"

static void	insert_number(t_stack *stack, int start_index, int target_index)
{
	int		i;
	t_stack	tmp;

	tmp = stack[start_index];
	i = start_index;
	while (i > target_index)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}

void	insertion_sort(t_stack *stack, int length)
{
	int	i;
	int	j;

	if (length < 2)
		return ;
	i = 1;
	while (i < length)
	{
		if (stack[i].real_number < stack[i - 1].real_number)
		{
			j = 0;
			while (j < i)
			{
				if (stack[j].real_number > stack[i].real_number)
				{
					insert_number(stack, i, j);
					break ;
				}
				j++;
			}
		}
		i++;
	}
}
