/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:56:41 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 17:59:23 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_smaller(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (src_len);
}

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

size_t	str_addalloc(char **p, size_t add)
{
	char	*tmp;
	size_t	size;

	if (!p || !*p || !add)
		return (0);
	size = ft_strlen(*p) + 1 + add;
	tmp = malloc(size);
	ft_strlcpy(tmp, (const char *)*p, size);
	free(*p);
	*p = tmp;
	return (size);
}
