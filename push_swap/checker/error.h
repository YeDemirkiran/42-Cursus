/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:06:39 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 16:07:35 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "t_stack_pair.h"
# include <stdlib.h>

int	err_print(char *str,
		void (*clear)(t_stack_pair *), t_stack_pair *pair);

#endif