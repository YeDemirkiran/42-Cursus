/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:19 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 11:04:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_object(t_object *buffer, int index)
{
	int	i;

	i = index;
	buffer[i].sprite = NULL;
	while (buffer[i + 1].sprite)
	{
		buffer[i] = buffer[i + 1];
		i++;
	}
	buffer[i].sprite = NULL;
}
