/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:12:46 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 16:22:29 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "stdio.h"
#include "fcntl.h"

// static void		buffer_clear(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (i < BUFFER_SIZE)
// 		str[i++] = 0;
// }

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static size_t	ft_smaller(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
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

// static ssize_t	index_of_char(char *str, char c)
// {
// 	ssize_t	index;

// 	index = 0;
// 	while (str[index])
// 	{
// 		if (str[index] == c)
// 			return (index);
// 		index++;
// 	}
// 	// Check '\0'
// 	if (str[index] == c)
// 		return (index);
// 	return (-1);
// }

static size_t	str_addalloc(char **p, size_t add)
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

char	*get_next_line(int fd)
{
	static t_line_info	line;
	char				*tmp;
	size_t				s_tmp;

	if (fd < 0)
		return (NULL);
	if (!line.index || line.index >= line.last_read_size)
	{
		line.last_read_size = read(fd, line.buffer, BUFFER_SIZE);
		line.index = 0;
		line.start = 0;
	}	
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
	if (line.str)
	{
		s_tmp = str_addalloc(&(line.str), ft_strlen(line.buffer));
		ft_strlcat(line.str, line.buffer, s_tmp);
	}
	else
	{
		line.str = malloc((line.index - line.start) + 1);
		ft_strlcpy(line.str, line.buffer + line.start, (line.index - line.start) + 1);
		line.start = ++(line.index);
	}
	return (get_next_line(fd));
}

int main(void)
{
	int	fd;
	int	fd_1;
	int	fd_2;
	int	i;
	char	*line;

	fd_1 = open("./test.txt", O_RDONLY);
	fd_2 = open("./test_2.txt", O_RDONLY);
	fd = fd_1;

	printf("Target FD: %i\n\n", fd);
	line = get_next_line(fd);

	i = 0;
	while (line)
	{
		printf("%s", line);
		free(line);
		if (i && i % 3 == 0)
		{
			if (fd == fd_1)
				fd = fd_2;
			else if (fd == fd_2)
				fd = fd_1;
		}
		line = get_next_line(fd);
		i++;
	}
	printf("\nEnd of lines\n");
	close(fd_1);
	close(fd_2);
	return (0);
}
