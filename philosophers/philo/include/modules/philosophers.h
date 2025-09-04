/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:16:51 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 16:17:34 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <structs/s_philosopher.h>

int	init_philosophers(t_philosopher *philos, int count);
int	destroy_philosophers(t_philosopher *philos, int count);

#endif
