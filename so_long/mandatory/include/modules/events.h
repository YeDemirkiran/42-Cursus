/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:06:13 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:06:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "macro.h"
# include "e_keys.h"
# include "t_frame.h"

# include "mlx.h"
# include "ft_write.h"

// events.c
int	on_key_down(int keycode, t_frame *frame);
int	on_key_up(int keycode, t_frame *frame);

// events_extra.c
int	on_destroy_notify(void *mlx_addr);

#endif
