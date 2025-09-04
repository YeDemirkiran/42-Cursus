/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 23:34:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include <structs/s_table.h>
#include <structs/s_philo_data.h>
#include <macros/status.h>
#include <enums/e_routine.h>

void	init_philosophers(t_philosopher *philos, pthread_mutex_t *forks,
	int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		philos[i].left_fork = forks + i;
		philos[i].right_fork = forks + ((i + 1) % philo_count);
		i++;
	}
}

int	start_philosophers(t_table *table, int *count,
	void *(*philo_routine)(void *))
{
	int				i;
	int				res;
	t_philosopher	*philos;

	philos = table->philosophers;
	if (!philos)
		return (FAILURE);
	init_philosophers(table->philosophers,
		table->forks, table->config.philo_count);
	i = 0;
	while (i < *count)
	{
		res = pthread_create(&(philos[*count].thread_id), NULL, philo_routine,
				&(t_philo_data)
			{.philosopher = philos + *count, .signal = &(table->dinner_over),
				.signal_mutex = &(table->over_mutex), .config = &(table->config)});
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

static void	take_forks(t_philo_data *data)
{
	pthread_mutex_lock(data->philosopher->left_fork);
	printf("%i has taken a fork\n", data->philosopher->id);
	pthread_mutex_lock(data->philosopher->right_fork);
	printf("%i has taken a fork\n", data->philosopher->id);
}

void	philosopher_eat(t_philo_data *data)
{
	printf("%i is thinking\n", data->philosopher->id);
	take_forks(data);
	printf("%i is eating\n", data->philosopher->id);
	usleep(data->config->eat_time * 1000);
}

void	philosopher_sleep(t_philo_data *data)
{
	printf("%i is sleeping\n", data->philosopher->id);
	usleep(data->config->sleep_time * 1000);
}

void	*philosopher_routine(void *data)
{
	t_philo_data	*philo_data;
	t_philosopher	*philo;
	t_byte			*routine;

	philo_data = (t_philo_data *)data;
	philo = philo_data->philosopher;
	routine = &(philo->current_routine);
	*routine = (t_byte)PHILO_EAT;
	while (!philo->is_dead && *(philo_data->signal) != 1)
	{
		if (*routine == (t_byte)PHILO_EAT)
			philosopher_eat(data);
		else if (*routine == (t_byte)PHILO_SLEEP)
			philosopher_sleep(data);
		philo->current_routine++;
		philo->current_routine %= 2;
	}
	if (philo->is_dead)
	{
		pthread_mutex_lock(philo_data->signal_mutex);
		*(philo_data->signal) = 1;
		printf("%i died\n", philo->id);
		pthread_mutex_unlock(philo_data->signal_mutex);
	}
	return (NULL);
}
