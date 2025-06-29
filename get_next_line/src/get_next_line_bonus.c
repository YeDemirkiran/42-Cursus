/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:12:46 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 18:13:57 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdio.h"

static int	alloc_buffer(char ***buffer, int fd)
{
	size_t	i;

	if (!buffer)
		return (0);
	*buffer = malloc(((size_t)fd + 2) * sizeof(char *));
	if (!*buffer)
		return (0);
	i = 0;
	while (i < (size_t)fd + 1)
		(*buffer)[i++] = NULL;
	(*buffer)[i] = malloc(1);
	(*buffer)[i][0] = -1;
	return (1);
}

static char	*on_read_fail(char ***buffer, int fd)
{
	if ((*buffer)[fd])
	{
		free((*buffer)[fd]);
		(*buffer)[fd] = NULL;
	}
	fd = 0;
	while (1)
	{
		if ((*buffer)[fd] && (*buffer)[fd][0] == -1)
		{
			free((*buffer)[fd]);
			free(*buffer);
			*buffer = NULL;
			break;
		}
		fd++;
	}
	return (NULL);
}

static ssize_t	next_line_init(int fd, char ***buffer, size_t *start_pos)
{
	ssize_t	read_size;

	if (!buffer)
		return (0);
	if (!(*buffer) && !alloc_buffer(buffer, fd))
		return (0);
	if ((*buffer)[fd])
	{
		*start_pos = 0;
		while ((*buffer)[fd][*start_pos] > 0)
			(*start_pos)++;
		if ((*buffer)[fd][*start_pos] == -1)
			return (0);
		(*buffer)[fd][(*start_pos)++] = '\n';
	}
	else
	{
		(*buffer)[fd] = malloc(BUFFER_SIZE + 2);
		if (!(*buffer)[fd])
			return (0);
		read_size = read(fd, (*buffer)[fd], BUFFER_SIZE);
		if (read_size <= 0)
			return (0);
		(*buffer)[fd][read_size] = -1;
		(*buffer)[fd][read_size + 1] = 0;
		*start_pos = 0;
	}
	return (1);
}

static char	*on_find_newline(char *buffer, size_t start, size_t end)
{
	char	*str;

	str = ft_substr((const char *)buffer, start, end - start + 1);
	if (!str)
		return (NULL);
	buffer[end] = 0;
	return (str);
}

static char	*at_no_newline(char **buffer, int fd, size_t start_pos)
{
	size_t	i;
	char	*tmp;
	char	*tmp_2;

	i = 0;
	while ((buffer[fd] + start_pos)[i])
		i++;
	tmp = malloc(i);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, buffer[fd] + start_pos, i);
	free(buffer[fd]);
	buffer[fd] = NULL;
	tmp_2 = get_next_line(fd);
	if (tmp_2)
		return (ft_strjoin(tmp, tmp_2, 1, 1));
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	**buffer;
	size_t		start_pos;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!next_line_init(fd, &buffer, &start_pos))
		return (on_read_fail(&buffer, fd));
	i = start_pos;
	while (buffer[fd][i] > 0)
	{
		if (buffer[fd][i] == '\n')
			return (on_find_newline(buffer[fd], start_pos, i));
		i++;
	}	
	return (at_no_newline(buffer, fd, start_pos));
}
