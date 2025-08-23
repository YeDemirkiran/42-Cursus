/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:33 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 13:34:26 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_destroy_notify(void *mlx_addr)
{
	ft_putstr("Closing the game by request... (Close button pressed)\n");
	mlx_loop_end(mlx_addr);
	return (0);
}
