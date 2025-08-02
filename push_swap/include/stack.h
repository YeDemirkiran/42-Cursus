/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:26 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 11:56:27 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

typedef struct s_stack
{
	int	number;
	int	index;
}			t_stack;

typedef struct s_stack_pair
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int		a_length;
	int		b_length;
}			t_stack_pair;

enum e_instructions 
{
	INST_NONE = -1,
	INST_END = 0,
	INST_SWAP_A = 1,
	INST_SWAP_B = 2,
	INST_SWAP_AB = 3,
	INST_PUSH_A = 4,
	INST_PUSH_B = 5,
	INST_ROT_A = 6,
	INST_ROT_B = 7,
	INST_ROT_AB = 8,
	INST_RROT_A = 9,
	INST_RROT_B = 10,
	INST_RROT_AB = 11,
};

void			stack_swap(t_stack *stack);
int				stack_swap_a(t_stack_pair pair);
int				stack_swap_b(t_stack_pair pair);

void			stack_rotate(t_stack *stack, int size);
int				stack_rotate_a(t_stack_pair pair);
int				stack_rotate_b(t_stack_pair pair);

void			stack_rotate_rev(t_stack *stack, int size);
int				stack_rotate_rev_a(t_stack_pair pair);
int				stack_rotate_rev_b(t_stack_pair pair);

t_stack_pair	init_stack_pair(char **arr, int argc);

#endif