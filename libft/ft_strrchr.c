/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:09:21 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/02 13:09:21 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*last;

	last = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			last = str;
		str++;
	}
	if (*str == c)
		last = str;
	return (last);
}
