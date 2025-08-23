/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:06 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:08:07 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "macro.h"
# include "t_frame.h"

# include "ft_write.h"
# include "overlap.h"
# include "render.h"
# include "delta_time.h"
# include "animation.h"

int		update_frame(t_frame *frame);

#endif
