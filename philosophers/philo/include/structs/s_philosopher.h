/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philosopher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:56:29 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 14:00:28 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef S_PHILOSOPHER_H
# define S_PHILOSOPHER_H

# include "types/t_byte.h"

typedef struct s_philosopher
{
	int		id;
	void	*left_fork;
	void	*right_fork;
	char	is_dead;
}	t_philosopher;

#endif
