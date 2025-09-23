/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:46:31 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/23 20:49:08 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_UTILS_H
# define PHILOSOPHERS_UTILS_H

# include <pthread.h>
# include <structs/s_philosopher.h>

void	init_philosophers(t_philosopher *philos, pthread_mutex_t *forks,
			int philo_count);
void	join_philosophers(t_philosopher *philos, int count);
void	free_philosophers(t_philosopher *philos, int count);

#endif
