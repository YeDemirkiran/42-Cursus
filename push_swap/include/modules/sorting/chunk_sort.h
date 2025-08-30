/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:27:12 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:27:13 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_SORT_H
# define CHUNK_SORT_H

# ifndef MAX_CHUNK_SIZE
#  define MAX_CHUNK_SIZE 10
# endif

# include <limits.h>
# include <stdlib.h>

# include "stack.h"
# include "e_instructions.h"

# include "pair_utils.h"
# include "instructions.h"

void	get_cheapest_b(t_stack_pair *pair, t_stack arr[2]);
void	chunk_sort(t_stack_pair *pair, t_instructions *instructions);

#endif