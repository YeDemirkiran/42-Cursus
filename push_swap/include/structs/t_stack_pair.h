/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_pair.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:28:03 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:28:04 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_PAIR_H
# define T_STACK_PAIR_H

# include "t_stack.h"

typedef struct s_stack_pair
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int		a_length;
	int		b_length;
	int		full_length;
}			t_stack_pair;

#endif
