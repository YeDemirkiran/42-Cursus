/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:22:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 16:27:07 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

#include <structs/s_table.h>
#include <macros/status.h>
#include <modules/mutex.h>
#include <modules/utils/convert.h>
#include <modules/philosophers.h>

static int	validate_config(t_config *config)
{
	if (config->philo_count < 0 || config->starve_time < 0
		|| config->eat_time < 0 || config->sleep_time < 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	init_config(t_config *config, int argc, char **argv)
{
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (FAILURE);
	config->philo_count = ft_atol(argv[1]);
	config->starve_time = ft_atol(argv[2]);
	config->eat_time = ft_atol(argv[3]);
	config->sleep_time = ft_atol(argv[4]);
	if (argc > 5 && argv[5])
		config->eat_count = ft_atol(argv[5]);
	else
		config->eat_count = -1;
	return (validate_config(config));
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (init_config(&(table->config), argc, argv) == FAILURE)
		return (FAILURE);
	if (init_mutexes(table->forks, table->config.philo_count) == FAILURE)
		return (FAILURE);
	table->philosophers = malloc(sizeof(t_philosopher)
			* table->config.philo_count);
	if (!table->philosophers)
	{
		destroy_mutexes(table->forks, table->config.philo_count);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	clear_table(t_table *table)
{
	destroy_philosophers();
	destroy_mutexes(table->forks, table->config.philo_count);
	free(table->forks);
}
