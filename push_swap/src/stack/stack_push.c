/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:57:29 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 15:10:53 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push_a_to_b(t_stack_pair *pair)
{
	if (pair->a_length <= 0)
		return (INST_NONE);
	stack_rotate_rev_b(*pair);
	pair->stack_b->number = pair->stack_a->number;
	stack_rotate_a(*pair);
	pair->a_length -= 1;
	pair->b_length += 1;
	return (INST_PUSH_B);
}

int	stack_push_b_to_a(t_stack_pair *pair)
{
	if (pair->b_length <= 0)
		return (INST_NONE);
	stack_rotate_rev_a(*pair);
	pair->stack_a->number = pair->stack_b->number;
	stack_rotate_b(*pair);
	pair->a_length += 1;
	pair->b_length -= 1;
	return (INST_PUSH_A);
}