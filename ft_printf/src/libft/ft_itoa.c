/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:48:44 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/12 17:48:45 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(int n);
static unsigned int	ft_abs(int n);

char	*ft_itoa(int n)
{
	unsigned int	un;
	char			*str;
	size_t			digits;
	int				negative;

	digits = ft_intlen(n);
	str = malloc((digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digits--] = 0;
	negative = 0;
	if (n < 0)
		negative = 1;
	un = ft_abs(n);
	while (digits > 0)
	{
		str[digits--] = (un % 10) + 48;
		un /= 10;
	}
	if (negative)
		str[0] = '-';
	else
		str[0] = (un % 10) + 48;
	return (str);
}

static size_t	ft_intlen(int n)
{
	unsigned int	un;
	size_t			len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	un = ft_abs(n);
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	un;

	if (n < 0)
		un = (unsigned int)(-(long)(n));
	else
		un = (unsigned int)n;
	return (un);
}
