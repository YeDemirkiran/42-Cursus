/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:37:02 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 23:03:15 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <structs/s_table.h>
#include <modules/philosophers.h>
#include <macros/status.h>

void	start_simulation(t_table *table)
{
	int	res;

	res = start_philosophers(table->philosophers, (int *)&(table->config.philo_count),
			philosopher_routine);
	if (res != SUCCESS)
		table->dinner_over = 1;
	join_philosophers(table->philosophers, table->config.philo_count);
}
