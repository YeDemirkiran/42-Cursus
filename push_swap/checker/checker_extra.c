/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:25:33 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 17:29:49 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_empty(char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
}

static void	apply_functions(t_stack_pair *pair,
	t_instructions *instructions, int i)
{
	if (instructions->arr[i] == INST_PUSH_A)
		stack_push_b_to_a(pair);
	else if (instructions->arr[i] == INST_PUSH_B)
		stack_push_a_to_b(pair);
	else if (instructions->arr[i] == INST_ROT_A)
		stack_rotate_a(*pair);
	else if (instructions->arr[i] == INST_ROT_B)
		stack_rotate_b(*pair);
	else if (instructions->arr[i] == INST_ROT_AB)
		stack_rotate_ab(*pair);
	else if (instructions->arr[i] == INST_RROT_A)
		stack_rotate_rev_a(*pair);
	else if (instructions->arr[i] == INST_RROT_B)
		stack_rotate_rev_b(*pair);
	if (instructions->arr[i] == INST_SWAP_A)
		stack_swap_a(*pair);
	else if (instructions->arr[i] == INST_SWAP_B)
		stack_swap_b(*pair);
	else if (instructions->arr[i] == INST_SWAP_AB)
		stack_swap_ab(*pair);
}

void	apply_instructions(t_stack_pair *pair,
	t_instructions *instructions)
{
	int	i;

	i = 0;
	while (instructions->arr[i] != INST_END)
	{
		apply_functions(pair, instructions, i);
		i++;
	}
}
