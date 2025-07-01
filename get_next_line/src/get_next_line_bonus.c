/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:12:46 by yademirk          #+#    #+#             */
/*   Updated: 2025/07/01 17:00:53 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdio.h"

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
		if ((*buffer)[fd])
		{
			if ((*buffer)[fd][0] == -1)
			{
				free((*buffer)[fd]);
				free(*buffer);
				*buffer = NULL;
			}
			break ;
		}
		fd++;
	}
	return (NULL);
}

static int	buffer_init(int fd, char ***buffer)
{
	ssize_t	i;
	ssize_t	j;
	char	**new;

	i = 0;
	while (!((*buffer)[i] && (*buffer)[i][0] == -1))
		i++;
	// printf("BUFFER INIT FOR FD (%i)\n", fd);
	//printf("ii: %lu, fd: %i\n", i, fd);
	if (i < (ssize_t)fd + 1)
	{
		i++;
		// printf("EXTENDING BUFFER FOR FD (%i)\n", fd);
		if (!alloc_buffer(&new, fd))
			return (0);
		while (i-- > 0)
		{
			if (!(*buffer)[i])
				continue ;
			// if ((*buffer)[i][0] == -1)
			// {
			// 	printf("FOUND THE SENTINELLLL\n\n\n");
			// 	free((*buffer)[i]);
			// 	continue ;
			// }
			if ((*buffer)[i][0] != -1)
			{
				j = 0;
				while ((*buffer)[i][j] != -1)
					j++;
				new[i] = malloc(++j + 1);
				// printf("j: %lu\n", j);
				if (!new[i])
					return (0);
				ft_strlcpy(new[i], (*buffer)[i], j + 1);
			}
			free((*buffer)[i]);
		}
		free(*buffer);
		*buffer = new;
	}
	(*buffer)[fd] = malloc((size_t)BUFFER_SIZE + 2);
	if (!(*buffer)[fd])
		return (0);
	printf("ATTEMPTING TO READ FD (%i)\n", fd);
	i = read(fd, (*buffer)[fd], (size_t)BUFFER_SIZE);
	printf("RESULT: (%li)\n", i);
	if (i <= 0)
		return (0);
	(*buffer)[fd][i] = -1;
	(*buffer)[fd][i + 1] = 0;
	// printf("NEW BUFFER FOR FD (%i): (%s)\n", fd, (*buffer)[fd]);
	return (1);
}

static ssize_t	next_line_init(int fd, char ***buffer, size_t *start_pos)
{
	size_t	i;
	
	// printf("NEXT LINE INIT FOR FD (%i)\n", fd);
	if (!(*buffer) && !alloc_buffer(buffer, fd))
		return (0);
	i = 0;
	while (!((*buffer)[i] && (*buffer)[i][0] == -1))
		i++;
	*start_pos = 0;
	if ((i >= (size_t)fd + 1) && (*buffer)[fd])
	{
		while ((*buffer)[fd][*start_pos] > 0)
			(*start_pos)++;
		// printf("START POS FOR FD (%i): %lu\n", fd, *start_pos);
		if ((*buffer)[fd][*start_pos] == -1)
			return (0);
		(*buffer)[fd][(*start_pos)++] = '\n';
		//printf("s: %s\n", (*buffer)[fd]);
	}
	else
	{
		// printf("FD (%i) DOESN'T EXIST IN THE BUFFER\n", fd);
		if (!buffer_init(fd, buffer))
			return (0);
	}
	return (1);
}

static char	*at_no_newline(char **buffer, int fd, size_t start_pos)
{
	size_t	i;
	char	*tmp;
	char	*tmp_2;

	i = 0;
	// printf("NO NEWLINE FOUND FOR FD (%i)\n", fd);
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
	// printf("END OF FILE FOR FD (%i)\n", fd);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*str;
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
		{
			str = ft_substr((const char *)buffer[fd], start_pos,
					i - start_pos + 1);
			if (!str)
				return (NULL);
			buffer[fd][i] = 0;
			// printf("NEWLINE FOUND FOR FD (%i): (%s)\n", fd, str);
			return (str);
		}
		i++;
	}
	return (at_no_newline(buffer, fd, start_pos));
}
