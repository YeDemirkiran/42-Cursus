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

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return ;
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = 0;
}

void	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	if (size <= dst_len)
		return ;
	ft_strlcpy(dst + dst_len, src, size - dst_len);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	i;

	size = len + 1;
	substr = malloc(size);
	if (!substr)
		return (NULL);
	if (size == 1)
		*substr = 0;
	else
	{
		i = 0;
		while (i < size - 1)
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = 0;
	}
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2, int free_1, int free_2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	str = malloc((s1_len + s2_len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, (s1_len + s2_len + 1));
	if (free_1)
		free(s1);
	if (free_2)
		free(s2);
	return (str);
}
