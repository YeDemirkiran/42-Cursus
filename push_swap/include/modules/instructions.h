/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:27:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 13:27:56 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# ifndef INSTRUCTONS_SIZE
#  define INSTRUCTIONS_SIZE 32768
# endif

# include <stdlib.h>

# include "t_instructions.h"

int		init_instructions(t_instructions *inst_arr, int length);
void	clear_instructions(t_instructions *inst_arr,
			int length, int preserve_index);

#endif