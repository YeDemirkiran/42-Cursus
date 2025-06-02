/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:17:24 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/02 13:01:11 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	c_size;

	c_size = nmemb * size;
	if (c_size == 0)
	{
		arr = malloc(1);
		if (!arr)
			return (NULL);
		return (arr);
	}
	else if (c_size < nmemb || c_size < size)
		return (NULL);
	arr = malloc(c_size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, c_size);
	return (arr);
}
