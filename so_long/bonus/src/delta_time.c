/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:39:41 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 12:39:42 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "delta_time.h"

float	get_delta_time(void)
{
	static double	time;
	double			current_time;
	float			delta_time;
	struct timeval	tv;

	delta_time = 0;
	gettimeofday(&tv, NULL);
	current_time = (double)tv.tv_sec + (double)tv.tv_usec / 1e6;
	if (current_time > time)
	{
		delta_time = (float)(current_time - time);
		time = current_time;
	}
	return (delta_time);
}
