/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:01 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 12:32:15 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "stdio.h"

static int	is_duplicate(t_stack *stack, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < index)
	{
		j = 0;
		while (j < i)
		{
			if (stack[j].number == stack[i].number)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_stack_pair	free_stack(t_stack *stack)
{
	t_stack_pair	empty;

	empty.stack_a = NULL;
	empty.stack_b = NULL;
	empty.a_length = 0;
	empty.b_length = 0;
	if (stack)
		free(stack);
	return (empty);
}

static void	init_stack_empty(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i].number = 0;
		stack[i].index = i;
		i++;
	}
}

t_stack_pair	init_stack_pair(char **arr, int argc)
{
	int				i;
	t_stack_pair	pair;
	long long		num;

	i = 0;
	pair.stack_a = malloc(sizeof(t_stack) * argc);
	if (!pair.stack_a)
		return (pair);
	while (i < argc)
	{
		if (!ft_isnumber(arr[i]))
			return (free_stack(pair.stack_a));
		num = ft_atol(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_stack(pair.stack_a));
		pair.stack_a[i].index = i;
		pair.stack_a[i].number = (int)num;
		if (!is_duplicate(pair.stack_a, i))
			return (free_stack(pair.stack_a));
		i++;
	}
	pair.stack_b = malloc(sizeof(t_stack) * argc);
	if (!pair.stack_b)
		return (free_stack(pair.stack_a));
	init_stack_empty(pair.stack_b, argc);
	pair.a_length = argc;
	pair.b_length = 0;
	return (pair);
}