/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:12:46 by yademirk          #+#    #+#             */
/*   Updated: 2025/07/02 18:23:06 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clear_buffer(char ***buffer, int fd)
{
	if ((*buffer)[fd])
	{
		free((*buffer)[fd]);
		(*buffer)[fd] = NULL;
	}
	fd = 0;
	while (1)
	{
		if ((*buffer)[fd])
		{
			if (!(*buffer)[fd][0])
			{
				free((*buffer)[fd]);
				free(*buffer);
				*buffer = NULL;
			}
			break ;
		}
		fd++;
	}
}

static int	buffer_init(int fd, char ***buffer)
{
	ssize_t	i;

	i = 0;
	while (!((*buffer)[i] && (unsigned char)(*buffer)[i][0] == 0))
		i++;
	if (i < (ssize_t)fd + 1)
		if (!gnl_expand_buffer(fd, buffer, ++i))
			return (0);
	(*buffer)[fd] = malloc((size_t)BUFFER_SIZE_GNL + 1);
	if (!(*buffer)[fd])
		return (0);
	i = read(fd, (*buffer)[fd], (size_t)BUFFER_SIZE_GNL);
	if (i <= 0)
		return (0);
	(*buffer)[fd][i] = 0;
	return (1);
}

static ssize_t	next_line_init(int fd, char ***buffer, size_t *start_pos)
{
	size_t	i;

	if (!(*buffer) && !gnl_alloc_buffer(buffer, fd))
		return (0);
	i = 0;
	while (!((*buffer)[i] && (unsigned char)(*buffer)[i][0] == 0))
		i++;
	*start_pos = 0;
	if ((i >= (size_t)fd + 1) && (*buffer)[fd])
	{
		while ((*buffer)[fd][*start_pos] && (*buffer)[fd][*start_pos] != 30)
			(*start_pos)++;
		if (!(*buffer)[fd][*start_pos])
			return (0);
		(*buffer)[fd][(*start_pos)++] = '\n';
	}
	else
		if (!buffer_init(fd, buffer))
			return (0);
	return (1);
}

static int	find_line(char **buffer, char **str, int fd, size_t start_pos)
{
	size_t	i;

	i = start_pos;
	while ((unsigned char)buffer[fd][i])
	{
		if ((unsigned char)buffer[fd][i] == '\n')
		{
			*str = gnl_strjoin(*str, gnl_substr((const char *)buffer[fd],
						start_pos, i - start_pos + 1), 1, 1);
			if (!*str)
				return (-1);
			buffer[fd][i] = 30;
			return (1);
		}
		i++;
	}
	if (buffer[fd][start_pos])
		*str = gnl_strjoin(*str, buffer[fd] + start_pos, 1, 0);
	if (buffer[fd])
		free(buffer[fd]);
	buffer[fd] = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*str;
	size_t		start_pos;
	int			res;

	if (fd < 0 || BUFFER_SIZE_GNL <= 0)
		return (NULL);
	str = NULL;
	while (1)
	{
		if (!next_line_init(fd, &buffer, &start_pos))
		{
			clear_buffer(&buffer, fd);
			return (str);
		}
		res = find_line(buffer, &str, fd, start_pos);
		if (res == -1)
			return (NULL);
		else if (res == 1)
			return (str);
	}
}
