/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:07:57 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 14:29:41 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERLAP_H
# define OVERLAP_H

# include <math.h>

# include "t_frame.h"

# include "mlx.h"
# include "utils.h"
# include "ft_write.h"

void	check_walls(t_frame *frame);
void	check_collectibles(t_frame *frame);
void	check_exit(t_frame *frame);

#endif
