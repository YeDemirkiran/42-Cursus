/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:16:51 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 23:04:23 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <structs/s_philosopher.h>
# include <structs/s_philo_data.h>

int		start_philosophers(t_philosopher *philos, int *count,
			void *(*philo_routine)(void *));
void	join_philosophers(t_philosopher *philos, int count);
void	*philosopher_routine(void *data);

#endif
