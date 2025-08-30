/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:28:42 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:28:43 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair_utils.h"

void	clear_pair(t_stack_pair *pair)
{
	if ((*pair).stack_a)
		free((*pair).stack_a);
	if ((*pair).stack_b)
		free((*pair).stack_b);
}

t_stack_pair	duplicate_pair(t_stack_pair *pair)
{
	t_stack_pair	dup;

	dup.stack_a = duplicate_stack(pair->stack_a, pair->full_length);
	dup.stack_b = duplicate_stack(pair->stack_b, pair->full_length);
	dup.a_length = pair->a_length;
	dup.b_length = pair->b_length;
	dup.full_length = pair->full_length;
	return (dup);
}
