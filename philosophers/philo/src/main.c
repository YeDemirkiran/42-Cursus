/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 15:19:39 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <structs/s_table.h>
#include <macros/status.h>

int				mails = 0;
pthread_mutex_t	mutex;

void	*test_threads()
{
	static int	id;

	pthread_mutex_lock(&mutex);
	for (size_t i = 0; i < 100000; i++)
	{
		printf("ID: %i, i: %lu\n", id, i);
		mails++;
	}
	id++;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

pthread_mutex_t	*init_mutexes(int count)
{
	pthread_mutex_t	*mutexes;

	mutexes = malloc(sizeof(*mutexes) * count);
	if (!mutexes)
		return (NULL);
	while (count-- >= 0)
		pthread_mutex_init(mutexes + count, NULL);
	return (mutexes);
}

void	destroy_mutexes(pthread_mutex_t *mutexes, int count)
{
	while (count-- >= 0)
		pthread_mutex_destroy(mutexes + count);
}

static int	init_table(t_table *table, int argc, char **argv)
{
	table->forks = init_mutexes(table->config.philo_count);
	if (!table->forks)
		return (FAILURE);
	return (SUCCESS);
}



static void	clear_table(t_table *table)
{
	free(table->philosophers);
	destroy_mutexes(table->forks, table->config.philo_count);
	free(table->forks);
}

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	threads[2];

	init_table(&table, argc, argv);
	clear_table(&table);
	return (EXIT_SUCCESS);
}
