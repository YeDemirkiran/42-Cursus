/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 16:27:25 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <pthread.h>
#include <stdlib.h>

#include <structs/s_philosopher.h>
#include <macros/status.h>

int	start_philosophers(t_philosopher *philos, int count)
{
	int	i;
	int	res;

	if (!philos)
		return (FAILURE);
	i = 0;
	while (i < count)
	{
		res = pthread_create(&(philos[count].thread_id), NULL,
				NULL, philos + count);
		if (res != SUCCESS)
		{
			destroy_philosophers(philos, i);
			return (FAILURE);
		}
		i++;
	}
}

int	join_philosophers(t_philosopher *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	free(philos);
}
