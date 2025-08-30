/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:27:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:27:09 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_UTILS_H
# define PAIR_UTILS_H

# include <stdlib.h>

# include "t_stack_pair.h"
# include "stack.h"

void			clear_pair(t_stack_pair *pair);
t_stack_pair	duplicate_pair(t_stack_pair *pair);

#endif