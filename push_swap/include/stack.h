/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:26 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 13:09:35 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "dependencies.h"
# include "t_instructions.h"

typedef struct s_stack
{
	int	number;
	int	real_number;
	int	index;
}			t_stack;

typedef struct s_stack_pair
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int		a_length;
	int		b_length;
	int		full_length;
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

// stack_swap.c
void			stack_swap(t_stack *stack);
int				stack_swap_a(t_stack_pair pair);
int				stack_swap_b(t_stack_pair pair);
int				stack_swap_ab(t_stack_pair pair);

// stack_rotate.c
void			stack_rotate(t_stack *stack, int size);
int				stack_rotate_a(t_stack_pair pair);
int				stack_rotate_b(t_stack_pair pair);
int				stack_rotate_ab(t_stack_pair pair);

// stack_rotate_rev.c
void			stack_rotate_rev(t_stack *stack, int size);
int				stack_rotate_rev_a(t_stack_pair pair);
int				stack_rotate_rev_b(t_stack_pair pair);
int				stack_rotate_rev_ab(t_stack_pair pair);

// stack_push.c
int				stack_push_a_to_b(t_stack_pair *pair);
int				stack_push_b_to_a(t_stack_pair *pair);

// stack_operations.c
t_stack			find_smallest_index(t_stack *stack, int size);
void			stack_a_move_to_first(t_stack_pair pair, t_stack target,
					t_instructions *instructions);
void			stack_b_move_to_first(t_stack_pair pair, t_stack target,
					t_instructions *instructions);
void			stack_ab_move_to_first(t_stack_pair pair, t_stack *targets,
					t_instructions *instructions);
int				is_stack_sorted(t_stack *stack, int size);

// init_stack.c
t_stack_pair	init_stack_pair(char **arr, int argc);

// stack_predicate.c
int				is_biggest(t_stack *stack, int size, int number);
int				is_smallest(t_stack *stack, int size, int number);

// stack_get.c
t_stack			get_biggest(t_stack *stack, int size);
t_stack			get_smallest(t_stack *stack, int size);
t_stack			get_place_before(t_stack *stack, int size, int target_num);
t_stack			get_between(t_stack *stack, int size, int min, int max);

#endif
