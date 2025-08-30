/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_predicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:29:07 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:29:08 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_predicate.h"

int	is_biggest(t_stack *stack, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (number < stack[i].number)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_smallest(t_stack *stack, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (number > stack[i].number)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
