/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:31:44 by yademirk          #+#    #+#             */
/*   Updated: 2025/10/03 21:09:23 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

#include <macros/status.h>
#include <structs/s_philosopher.h>

void	init_philosophers(t_philosopher *philos, pthread_mutex_t *forks,
	int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		philos[i].id = malloc(sizeof(int));
		*(philos[i].id) = i;
		philos[i].left_fork = forks + i;
		philos[i].right_fork = forks + ((i + 1) % philo_count);
		i++;
	}
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

void	free_philosophers(t_philosopher *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(philos[i].id);
		i++;
	}
	free(philos);
}
