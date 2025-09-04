/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_table.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:53:44 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 17:42:04 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef S_TABLE_H
# define S_TABLE_H

# include <structs/s_philosopher.h>
# include <structs/s_config.h>

typedef struct s_table
{
	t_config		config;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	t_byte			dinner_over;
}	t_table;

#endif
