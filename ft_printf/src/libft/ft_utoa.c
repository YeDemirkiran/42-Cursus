/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:23:54 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 11:23:55 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	size_t			digits;

	digits = ft_uintlen(n);
	str = malloc((digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digits] = 0;
	while (digits-- > 0)
	{
		str[digits] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
