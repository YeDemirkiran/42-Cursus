/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:31:44 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/22 23:33:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

#include <structs/s_table.h>
#include <structs/s_philo_data.h>
#include <macros/status.h>

static void	init_philosophers(t_philosopher *philos, pthread_mutex_t *forks,
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
