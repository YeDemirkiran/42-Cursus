/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 17:46:56 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <pthread.h>
#include <stdlib.h>

#include <structs/s_philosopher.h>
#include <macros/status.h>

int	start_philosophers(t_philosopher *philos, int *count,
	void *(*philo_routine)(void *))
{
	int	i;
	int	res;

	if (!philos)
		return (FAILURE);
	i = 0;
	while (i < count)
	{
		res = pthread_create(&(philos[*count].thread_id), NULL,
				philo_routine, philos + *count);
		if (res != SUCCESS)
		{
			*count = i;
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

void	join_philosophers(t_philosopher *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
}

void	philosopher_routine(t_philosopher *philo, int *end_signal)
{
	while (!philo->is_dead && *end_signal != 1)
	{

	}
}
