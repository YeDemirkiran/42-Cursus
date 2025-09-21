/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/21 12:30:02 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include <structs/s_table.h>
#include <structs/s_philo_data.h>
#include <macros/status.h>

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

/**
 * @brief Sleep for ms, then return the time difference since the beginning.
 *
 * The first call returns always 0. To get the current timestamp without
 * sleeping, make ms 0.
 */
long	time_philosopher(long ms)
{
	static long				start_time;
	//static pthread_mutex_t	mutex;
	long					current_time;
	long					timestamp;
	struct timeval			tv;

	//pthread_mutex_init(&mutex, NULL);
	if (ms > 0)
		usleep(ms * 1000);
	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	//pthread_mutex_lock(&mutex);
	if (start_time == 0)
		start_time = current_time;
	timestamp = current_time - start_time;
	//pthread_mutex_unlock(&mutex);
	return (timestamp);
}

static t_byte read_signal_mutex(t_byte *signal, pthread_mutex_t *mutex)
{
	t_byte	res;

	pthread_mutex_lock(mutex);
	res = *signal;
	pthread_mutex_unlock(mutex);
	return (res);
}

static void	take_forks(t_philo_data *data)
{
	long	time;

	//printf("(%i waiting for left fork %p)\n", *data->philosopher->id, data->philosopher->left_fork);
	pthread_mutex_lock(data->philosopher->left_fork);
	time = time_philosopher(0);
	//pthread_mutex_lock(data->print_mutex);
	printf("%li %i has taken a fork\n", time, *data->philosopher->id);
	//pthread_mutex_unlock(data->print_mutex);
	//printf("(%i waiting for right fork %p)\n", *data->philosopher->id, data->philosopher->right_fork);
	pthread_mutex_lock(data->philosopher->right_fork);
	time = time_philosopher(0);
	//pthread_mutex_lock(data->print_mutex);
	printf("%li %i has taken a fork\n", time, *data->philosopher->id);
	//pthread_mutex_unlock(data->print_mutex);
}

void	philosopher_die(t_philo_data *data)
{
	long	time;

	pthread_mutex_lock(data->signal_mutex);
	*(data->signal) = 1;
	pthread_mutex_unlock(data->signal_mutex);
	time = time_philosopher(0);
	printf("%li %i died\n", time, *(data->philosopher->id));
}

void	philosopher_eat(t_philo_data *data)
{
	long	time;

	time = time_philosopher(0);
	printf("%li %i is thinking\n", time, *data->philosopher->id);
	take_forks(data);
	time = time_philosopher(0);
	printf("%li %i is eating\n", time, *data->philosopher->id);
	time_philosopher(data->config->eat_time);
	pthread_mutex_unlock(data->philosopher->left_fork);
	pthread_mutex_unlock(data->philosopher->right_fork);
}

void	philosopher_sleep(t_philo_data *data)
{
	long	time;
	long	diff;

	time = time_philosopher(0);
	//pthread_mutex_lock(data->print_mutex);
	printf("%li %i is sleeping\n", time, *data->philosopher->id);
	//pthread_mutex_unlock(data->print_mutex);
	diff = data->config->starve_time - data->config->sleep_time;
	if (diff <= 0)
	{
		time_philosopher(data->config->starve_time);
		philosopher_die(data);
	}
	else
		time_philosopher(data->config->sleep_time);
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
