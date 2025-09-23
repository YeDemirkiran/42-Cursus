/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/23 20:54:50 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include <macros/status.h>
#include <structs/s_table.h>
#include <structs/s_philo_data.h>

#include <modules/philosophers/philosophers_routine.h>
#include <modules/philosophers/philosophers_utils.h>

/**
 * @brief Sleep for ms, then return the time difference since the beginning.
 *
 * The first call returns always 0. To get the current timestamp without
 * sleeping, make ms 0.
 */
long	time_philosopher(long ms)
{
	static long		start_time;
	long			current_time;
	long			timestamp;
	struct timeval	tv;

	if (ms > 0)
		usleep(ms * 1000);
	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (start_time == 0)
		start_time = current_time;
	timestamp = current_time - start_time;
	return (timestamp);
}

t_byte	read_signal_mutex(t_byte *signal, pthread_mutex_t *mutex)
{
	t_byte	res;

	pthread_mutex_lock(mutex);
	res = *signal;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	*philosopher_routine(void *data)
{
	t_philo_data	*philo_data;
	t_byte			*dinner_over;

	philo_data = (t_philo_data *)data;
	dinner_over = philo_data->signal;
	while (1)
	{
		if (read_signal_mutex(dinner_over, philo_data->signal_mutex))
			break ;
		philosopher_eat(data);
		if (read_signal_mutex(dinner_over, philo_data->signal_mutex))
			break ;
		philosopher_sleep(data);
		if (read_signal_mutex(dinner_over, philo_data->signal_mutex))
			break ;
	}
	free(data);
	return (NULL);
}

int	start_philosophers(t_table *table, int count,
	void *(*philo_routine)(void *))
{
	int				i;
	int				res;
	t_philosopher	*philos;
	t_philo_data	*data;

	philos = table->philosophers;
	if (!philos)
		return (0);
	init_philosophers(philos, table->forks, table->config.philo_count);
	i = 0;
	while (i < count)
	{
		data = malloc(sizeof(t_philo_data));
		if (!data)
			return (0);
		data->philosopher = philos + i;
		data->signal = &(table->dinner_over);
		data->signal_mutex = &(table->over_mutex);
		data->print_mutex = &(table->print_mutex);
		data->config = &(table->config);
		res = pthread_create(&(philos[i].thread_id), NULL, philo_routine, data);
		if (res != SUCCESS)
		{
			free(data);
			return (0);
		}
		i++;
	}
	return (i);
}
