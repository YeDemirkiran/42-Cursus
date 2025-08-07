/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:57:37 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 12:51:08 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stdio.h"

void	stack_rotate(t_stack *stack, int size)
{
	int	i;
	int	tmp;

	// if (size <= 1)
	// 	return ;
	tmp = stack[0].number;
	i = 1;
	while (i < size)
	{
		// printf("Copying: %i\n", stack[i].number);
		stack[i - 1].number = stack[i].number;
		// printf("Copied.\n");
		i++;
	}
	// printf("Copying: %i\n", tmp);
	stack[i - 1].number = tmp;
	// printf("Copied.\n");
}

int	stack_rotate_a(t_stack_pair pair)
{
	stack_rotate(pair.stack_a, pair.a_length);
	return (INST_ROT_A);
}

int	stack_rotate_b(t_stack_pair pair)
{
	stack_rotate(pair.stack_b, pair.b_length);
	return (INST_ROT_B);
}

int	stack_rotate_ab(t_stack_pair pair)
{
	stack_rotate(pair.stack_a, pair.a_length);
	stack_rotate(pair.stack_b, pair.b_length);
	return (INST_ROT_AB);
}
