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
	size_t	len;

	dst_len = ft_strlen(dst);
	dst += dst_len * sizeof(char);
	len = ft_smaller(size, dst_len) + ft_strlen(src);
	if (size < dst_len)
		size = 0;
	else
		size -= dst_len;
	while (size-- > 1 && *src)
		*(dst++) = *(src++);
	*dst = 0;
	return (len);
}

static size_t	ft_smaller(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}
