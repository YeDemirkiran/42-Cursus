/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:22:48 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 11:22:49 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_abs(int n)
{
	unsigned int	un;

	if (n < 0)
		un = (unsigned int)(-(long)(n));
	else
		un = (unsigned int)n;
	return (un);
}
