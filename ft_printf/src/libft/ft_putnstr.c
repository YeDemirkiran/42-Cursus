/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:23:16 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 11:23:17 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *s, size_t n)
{
	size_t	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	write(1, s, len);
}
