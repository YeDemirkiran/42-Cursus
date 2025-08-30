/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:21:02 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 17:30:00 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>

# include "t_stack_pair.h"
# include "t_instructions.h"
# include "e_instructions.h"

# include "pair_utils.h"
# include "ft_string.h"
# include "get_next_line.h"
# include "instructions.h"
# include "error.h"
# include "ft_write.h"

void	read_empty(char *line);
void	apply_instructions(t_stack_pair *pair,
			t_instructions *instructions);

#endif