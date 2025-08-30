/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:57:29 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 11:34:33 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_push.h"

int	stack_push_a_to_b(t_stack_pair *pair)
{
	if (pair->a_length <= 0)
		return (INST_NONE);
	pair->stack_b[pair->b_length].number = pair->stack_a[0].number;
	pair->stack_a[0].number = 0;
	pair->b_length += 1;
	stack_rotate_rev_b(*pair);
	stack_rotate_a(*pair);
	pair->a_length -= 1;
	return (INST_PUSH_B);
}

int	stack_push_b_to_a(t_stack_pair *pair)
{
	if (pair->b_length <= 0)
		return (INST_NONE);
	pair->stack_a[pair->a_length].number = pair->stack_b[0].number;
	pair->stack_b[0].number = 0;
	pair->a_length += 1;
	stack_rotate_rev_a(*pair);
	stack_rotate_b(*pair);
	pair->b_length -= 1;
	return (INST_PUSH_A);
}
