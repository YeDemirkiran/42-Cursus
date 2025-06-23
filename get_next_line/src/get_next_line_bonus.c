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

static int	alloc_buffer(char ***buffer)
{
	size_t	i;

	if (!buffer)
		return (0);
	i = 0;
	while ((*buffer)[i])
	{
		if (*(buffer[i]))
		{
			free(*(buffer[i]));
			*(buffer[i]) = NULL;
		}
		i++;
	}
	free(*buffer);
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!*buffer)
		return (0);
	i = 0;
	*buffer[BUFFER_SIZE] = NULL;
	while (*buffer[i])
		*buffer[i++] = NULL;
	return (1);
}

static int	next_line_init(int fd, char ***buffer, size_t *start_pos)
{
	size_t	read_size;

	if (!buffer)
		return (0);
	if (!*buffer)
	{
		if (!alloc_buffer(*buffer))
			return (0);
	}
	if (*buffer[fd])
	{
		*start_pos = ft_strlen(*buffer[fd]) + 1;
		*buffer[fd][*start_pos - 1] = '\n';
	}
	else
	{
		*buffer[fd] = malloc(BUFFER_SIZE + 1);
		if (!*buffer[fd])
			return (0);
		*buffer[fd][BUFFER_SIZE] = 0;
		read_size = read(fd, *buffer[fd], BUFFER_SIZE);
		if (read_size <= 0)
			return (0);
		*buffer[fd][read_size] = 0;
		*start_pos = 0;
	}
	// if (!line->index || line->index >= line->last_read_size)
	// {
	// 	line->last_read_size = read(fd, line->buffer, BUFFER_SIZE);
	// 	if (line->last_read_size > 0)
	// 		line->buffer[line->last_read_size] = 0;
	// 	line->index = 0;
	// 	line->start = 0;
	// }
	return (1);
}

static char	*on_find_newline(char *buffer, size_t start, size_t end)
{
	//size_t	s_tmp;
	char	*str;

	str = malloc((end - start) + 2);
	if (!str)
		return (NULL);
	buffer[end] = 0;
	ft_strlcpy(str, buffer + start, (end - start) + 2);
	//line->start = ++(line->index);
	// if (start)
	// {
	// 	s_tmp = str_addalloc(&(line->str), ft_strlen(str));
	// 	ft_strlcat(line->str, str, s_tmp);
	// 	free(str);
	// 	str = line->str;
	// 	line->str = NULL;
	// }
	return (str);
}

// static void	at_no_newline(t_line_info *line)
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
// 	if (line->buffer)
// 	{
// 		free(line->buffer);
// 		line->buffer = NULL;
// 	}
// }

// static char	*on_read_fail(t_line_info *line)
// {
// 	char	*str;

// 	if (line->buffer)
// 	{
// 		free(line->buffer);
// 		line->buffer = NULL;
// 	}
// 	if (line->last_read_size == 0)
// 	{
// 		str = line->str;
// 		line->str = NULL;
// 		return (str);
// 	}
// 	return (NULL);
// }

char	*get_next_line(int fd)
{
	static char	**buffer;
	size_t		start_pos;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!next_line_init(fd, &buffer, &start_pos))
		return (NULL);
	// if (line.last_read_size <= 0)
	// 	return (on_read_fail(&line));
	i = start_pos;
	while (buffer[fd][i])
	{
		if (buffer[fd][i] == '\n')
			return (on_find_newline(buffer[fd], start_pos, i));
		i++;
	}
	//at_no_newline(&line);
	return (NULL);
}
