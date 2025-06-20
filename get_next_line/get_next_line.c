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

#include "get_next_line.h"

#include "stdio.h"
#include "fcntl.h"

static void	next_line_init(int fd, t_line_info *line)
{
	if (!line->index || line->index >= line->last_read_size)
	{
		line->last_read_size = read(fd, line->buffer, BUFFER_SIZE);
		line->index = 0;
		line->start = 0;
	}
}

static void	at_no_newline(t_line_info *line)
{
	size_t				s_tmp;

	if (line->str)
	{
		s_tmp = str_addalloc(&(line->str), ft_strlen(line->buffer));
		ft_strlcat(line->str, line->buffer, s_tmp);
	}
	else
	{
		line->str = malloc((line->index - line->start) + 1);
		ft_strlcpy(line->str, line->buffer + line->start,
			(line->index - line->start) + 1);
		line->start = ++(line->index);
	}
}

char	*get_next_line(int fd)
{
	static t_line_info	line;
	char				*tmp;

	if (fd < 0)
		return (NULL);
	next_line_init(fd, &line);
	if (!line.last_read_size)
	{
		tmp = line.str;
		line.str = NULL;
		return (tmp);
	}
	else if (line.last_read_size < 0)
		return (NULL);
	while (line.index < line.last_read_size)
	{
		if (line.buffer[line.index] == '\n')
		{
			tmp = malloc((line.index - line.start) + 2);
			ft_strlcpy(tmp, line.buffer + line.start,
				(line.index - line.start) + 2);
			line.start = ++(line.index);
			if (line.str)
			{
				s_tmp = str_addalloc(&(line.str), ft_strlen(tmp));
				ft_strlcat(line.str, tmp, s_tmp);
				free(tmp);
				tmp = line.str;
				line.str = NULL;
			}
			return (tmp);
		}
		line.index++;
	}
	at_no_newline(&line);
	return (get_next_line(fd));
}

int main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("./get_next_line.c", O_RDONLY);

	printf("Target FD: %i\n\n", fd);
	line = get_next_line(fd);

	i = 0;
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("\nEnd of lines\n");
	close(fd);
	return (0);
}
