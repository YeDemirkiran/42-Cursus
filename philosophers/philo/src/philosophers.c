/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 18:33:54 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include <structs/s_table.h>
#include <structs/s_philo_data.h>
#include <macros/status.h>
#include <enums/e_routine.h>

int	start_philosophers(t_table *table, int *count,
	void *(*philo_routine)(void *))
{
	int				i;
	int				res;
	t_philosopher	*philos;

	philos = table->philosophers;
	if (!philos)
		return (FAILURE);
	i = 0;
	while (i < count)
	{
		res = pthread_create(&(philos[*count].thread_id), NULL, philo_routine,
				&(t_philo_data)
			{.philosopher = philos + *count, .signal = &(table->dinner_over),
				.signal_mutex = &(table->over_mutex)});
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

static void	take_fork(t_philosopher *philo)
{

}

void	philosopher_eat(t_philosopher *philo)
{

}

void	philosopher_sleep(t_philosopher *philo)
{

}

void	philosopher_think(t_philosopher *philo)
{

}

void	*philosopher_routine(t_philo_data *data)
{
	t_philosopher	*philo;
	t_byte			*routine;

	philo = data->philosopher;
	routine = &(philo->current_routine);
	*routine = (t_byte)PHILO_EAT;
	while (!philo->is_dead && *(data->signal) != 1)
	{
		if (*routine == (t_byte)PHILO_EAT)
			philosopher_eat(philo);
		else if (*routine == (t_byte)PHILO_SLEEP)
			philosopher_sleep(philo);
		else if (*routine == (t_byte)PHILO_THINK)
			philosopher_think(philo);
		philo->current_routine++;
		philo->current_routine %= 3;
	}
	if (philo->is_dead)
	{
		pthread_mutex_lock(data->signal_mutex);
		*(data->signal) = 1;
		printf("%i died\n", philo->id);
		pthread_mutex_unlock(data->signal_mutex);
	}
	return (NULL);
}
