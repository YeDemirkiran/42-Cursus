/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:57:33 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 12:51:22 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stdio.h"

void	stack_rotate_rev(t_stack *stack, int size)
{
	int	i;
	int	tmp;

	// if (size <= 1)
	// 	return ;
	tmp = stack[size - 1].number;
	i = size - 2;
	while (i >= 0)
	{
		//printf("Copying: %i\n", stack[i].number);
		stack[i + 1].number = stack[i].number;
		i--;
	}
	stack[i + 1].number = tmp;
}

int	stack_rotate_rev_a(t_stack_pair pair)
{
	stack_rotate_rev(pair.stack_a, pair.a_length);
	return (INST_RROT_A);
}

int	stack_rotate_rev_b(t_stack_pair pair)
{
	stack_rotate_rev(pair.stack_b, pair.b_length);
	return (INST_RROT_B);
}

int	stack_rotate_rev_ab(t_stack_pair pair)
{
	stack_rotate_rev(pair.stack_a, pair.a_length);
	stack_rotate_rev(pair.stack_b, pair.b_length);
	return (INST_RROT_AB);
}
