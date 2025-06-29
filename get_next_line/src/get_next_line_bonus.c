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
	// printf("\nfd: %i\n", fd);
	if (!(*buffer))
		if (!alloc_buffer(buffer, fd))
			return (0);
	// printf("\nbl: %lu\n", sizeof(*buffer));
	// printf("\na: %i, b: %i\n", buff_len(*buffer) > (size_t)fd, (*buffer)[fd] != NULL);
	// printf("UU");
	if ((*buffer)[fd])
	{
		// printf("1");
		*start_pos = 0;
		while ((*buffer)[fd][*start_pos] > 0)
			(*start_pos)++;
		if ((*buffer)[fd][*start_pos] == -1)
			return (0);
		(*buffer)[fd][(*start_pos)++] = '\n';
		//printf("\nstart pos: %lu, char: %c", *start_pos, (*buffer)[fd][*start_pos - 1]);
	}
	else
	{
		//printf("2");
		(*buffer)[fd] = malloc(BUFFER_SIZE + 2);
		if (!(*buffer)[fd])
			return (0);
		read_size = read(fd, (*buffer)[fd], BUFFER_SIZE);
		if (read_size <= 0)
			return (0);
		//printf("read size: %li", read_size);
		(*buffer)[fd][read_size] = -1;
		(*buffer)[fd][read_size + 1] = 0;
		*start_pos = 0;
	}
	return (1);
}

#include "stdio.h"

static char	*on_find_newline(char *buffer, size_t start, size_t end)
{
	char	*str;

	str = ft_substr((const char *)buffer, start, end - start + 1);
	if (!str)
		return (NULL);
	buffer[end] = 0;
	return (str);
}

// static void	at_no_newline(char **buffer)
// {
// 	size_t	s_tmp;

// 	if (line->str)
// 	{
// 		s_tmp = str_addalloc(&(line->str), ft_strlen(line->buffer));
// 		ft_strlcat(line->str, line->buffer, s_tmp);
// 	}
// 	else
// 	{
// 		line->str = malloc((line->index - line->start) + 1);
// 		ft_strlcpy(line->str, line->buffer + line->start,
// 			(line->index - line->start) + 1);
// 		line->start = ++(line->index);
// 	}
// 	if (*buffer)
// 	{
// 		free(*buffer);
// 		*buffer = NULL;
// 	}
// }

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*tmp;
	char		*tmp_2;
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
	i = ft_strlen(buffer[fd] + start_pos);
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
