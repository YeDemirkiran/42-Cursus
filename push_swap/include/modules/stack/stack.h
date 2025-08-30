/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:26 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 11:09:11 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "t_instructions.h"
# include "t_stack_pair.h"

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

// stack_utils.c
void			clear_pair(t_stack_pair *pair);
int				is_stack_sorted(t_stack *stack, int size);
t_stack			find_smallest_index(t_stack *stack, int size);
t_stack			*duplicate_stack(t_stack *stack, int length);
t_stack_pair	duplicate_pair(t_stack_pair *pair);
int				index_stack(t_stack *stack_a, int length);

// stack_move.c
void			stack_a_move_to_first(t_stack_pair pair, t_stack target,
					t_instructions *instructions);
void			stack_b_move_to_first(t_stack_pair pair, t_stack target,
					t_instructions *instructions);
void			stack_ab_move_to_first(t_stack_pair pair, t_stack *targets,
					t_instructions *instructions);

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
