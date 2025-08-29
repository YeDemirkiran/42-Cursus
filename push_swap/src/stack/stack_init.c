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
			if (stack[j].real_number == stack[i].real_number)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_stack_pair	free_stack(t_stack_pair *pair)
{
	if (pair->stack_a)
		free(pair->stack_a);
	if (pair->stack_b)
		free(pair->stack_a);
	pair->stack_a = NULL;
	pair->stack_b = NULL;
	pair->a_length = 0;
	pair->b_length = 0;
	return (*pair);
}

static void	init_stack_empty(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i].number = 0;
		stack[i].real_number = 0;
		stack[i].index = i;
		i++;
	}
}

static int	parse_numbers(char **arr, int argc, t_stack *stack_a)
{
	int			i;
	long long	num;
	char		*num_str;

	i = 0;
	while (i < argc)
	{
		num_str = arr[i];
		if (!ft_isnumber(num_str))
			return (0);
		num = ft_atol(num_str);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		stack_a[i].index = i;
		stack_a[i].real_number = (int)num;
		if (!is_duplicate(stack_a, i))
			return (0);
		i++;
	}
	return (1);
}

t_stack_pair	init_stack_pair(char **arr, int argc)
{
	t_stack_pair	pair;

	pair.stack_a = malloc(sizeof(t_stack) * argc);
	if (!pair.stack_a)
		return (pair);
	if (!parse_numbers(arr, argc, pair.stack_a))
		return (free_stack(&pair));
	if (!index_stack(pair.stack_a, argc))
		return (free_stack(&pair));
	pair.stack_b = malloc(sizeof(t_stack) * argc);
	if (!pair.stack_b)
		return (free_stack(&pair));
	init_stack_empty(pair.stack_b, argc);
	pair.full_length = argc;
	pair.a_length = argc;
	pair.b_length = 0;
	return (pair);
}
