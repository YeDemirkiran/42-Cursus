/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:23 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 15:03:51 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "dependencies.h"
# include "stack.h"
# include "array.h"

int		*bubble_sort(const int *arr, size_t len);
void	bubble_sort_ps(t_stack *stack, int size, t_byte *instructions);

void	selection_sort(t_stack_pair *pair, t_byte *instructions, int size);
void	chunk_sort(t_stack_pair *pair, t_byte *instructions, int size);

#endif