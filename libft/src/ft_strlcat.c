/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:09:04 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/02 13:09:05 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_smaller(size_t x, size_t y);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	total_len;

	dst_len = ft_strlen(dst);
	total_len = ft_smaller(size, dst_len) + ft_strlen(src);
	if (size <= dst_len)
		return (total_len);
	ft_strlcpy(dst + dst_len, src, size - dst_len);
	return (total_len);
}

static size_t	ft_smaller(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}
