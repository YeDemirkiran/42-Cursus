/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:56:41 by yademirk          #+#    #+#             */
/*   Updated: 2025/07/02 18:24:59 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return ;
	while (size-- > 1)
		*dst++ = *src++;
	*dst = 0;
}

char	*gnl_substr(char const *s, size_t start, size_t len)
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

char	*gnl_strjoin(char *s1, char *s2, int free_1, int free_2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2 && s2[s2_len])
		s2_len++;
	str = malloc((s1_len + s2_len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	if (s1)
		gnl_strlcpy(str, s1, s1_len + 1);
	if (s2)
		gnl_strlcpy(str + s1_len, s2, (s2_len + 1));
	if (free_1 && s1)
		free(s1);
	if (free_2 && s2)
		free(s2);
	return (str);
}

int	gnl_alloc_buffer(char ***buffer, int fd)
{
	size_t	i;

	*buffer = malloc(((size_t)fd + 2) * sizeof(char *));
	if (!*buffer)
		return (0);
	i = 0;
	while (i < (size_t)fd + 1)
		(*buffer)[i++] = NULL;
	(*buffer)[i] = malloc(1);
	(*buffer)[i][0] = 0;
	return (1);
}

int	gnl_expand_buffer(int fd, char ***buffer, ssize_t i)
{
	ssize_t	j;
	char	**new_buffer;

	if (!gnl_alloc_buffer(&new_buffer, fd))
		return (0);
	while (i-- > 0)
	{
		if (!(*buffer)[i])
			continue ;
		if ((unsigned char)(*buffer)[i][0])
		{
			j = 0;
			while ((unsigned char)(*buffer)[i][j])
				j++;
			new_buffer[i] = malloc(j + 1);
			if (!new_buffer[i])
				return (0);
			gnl_strlcpy(new_buffer[i], (*buffer)[i], j + 1);
		}
		free((*buffer)[i]);
	}
	free(*buffer);
	*buffer = new_buffer;
	return (1);
}
