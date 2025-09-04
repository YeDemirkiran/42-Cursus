/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:22:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 15:23:56 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

#include <structs/s_table.h>
#include <macros/status.h>
#include <modules/mutex.h>

int	init_table(t_table *table, int argc, char **argv)
{
	table->forks = init_mutexes(table->config.philo_count);
	if (!table->forks)
		return (FAILURE);
	return (SUCCESS);
}

void	clear_table(t_table *table)
{
	free(table->philosophers);
	destroy_mutexes(table->forks, table->config.philo_count);
	free(table->forks);
}
