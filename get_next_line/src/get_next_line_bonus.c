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
	// i = 0;
	// while (*buffer && (*buffer)[i])
	// {
	// 	free((*buffer)[i]);
	// 	(*buffer)[i] = NULL;
	// 	i++;
	// }
	*buffer = malloc((fd + 2) * sizeof(char *));
	if (!*buffer)
		return (0);
	i = ((size_t)fd) + 2;
	while (i > 0)
		(*buffer)[--i] = NULL;
	return (1);
}

// static size_t	buff_len(char **buffer)
// {
// 	size_t	len;

// 	len = 0;
// 	if (!buffer)
// 		return (len);
// 	while (buffer[len])
// 		len++;
// 	return (len);
// }

static int	next_line_init(int fd, char ***buffer, size_t *start_pos)
{
	size_t	read_size;

	//printf("\nfd: %i\n", fd);
	if (!(*buffer))
		if (!alloc_buffer(buffer, fd))
			return (0);
	// printf("\nbl: %lu\n", sizeof(*buffer));
	// printf("\na: %i, b: %i\n", buff_len(*buffer) > (size_t)fd, (*buffer)[fd] != NULL);
	if ((*buffer)[fd])
	{
		//printf("1");
		*start_pos = ft_strlen((*buffer)[fd]) + 1;
		(*buffer)[fd][*start_pos - 1] = '\n';
		//printf("\nstart pos: %lu, char: %c", *start_pos, (*buffer)[fd][*start_pos - 1]);
	}
	else
	{
		//printf("2");
		(*buffer)[fd] = malloc(BUFFER_SIZE + 1);
		if (!(*buffer)[fd])
			return (0);
		read_size = read(fd, (*buffer)[fd], BUFFER_SIZE);
		if (read_size <= 0)
			return (0);
		(*buffer)[fd][read_size] = 0;
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
	i = start_pos;
	while (buffer[fd][i])
	{
		if (buffer[fd][i] == '\n')
			return (on_find_newline(buffer[fd], start_pos, i));
		i++;
	}
	//at_no_newline(&buffer);
	return (NULL);
}
