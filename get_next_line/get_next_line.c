#include "get_next_line.h"

#include "stdio.h"
#include "fcntl.h"

static void		buffer_clear(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		str[i++] = 0;
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

static ssize_t	index_of_char(char *str, char c)
{
	ssize_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	// Check '\0'
	if (str[index] == c)
		return (index);
	return (-1);
}

static char	*copy_line(char buffer[BUFFER_SIZE], int start, int end)
{
	char	*str;
	// int		i;
	// int		j;
	// int		k;
	// ssize_t	target;

	// str = malloc((size_t)((ssize_t)buffer_amount * last_read_size) + 1);
	// if (!str)
	// 	return (NULL);
	// i = 0;
	// k = 0;
	// while (i < buffer_amount)
	// {
	// 	j = 0;
	// 	target = BUFFER_SIZE;
	// 	if (i == buffer_amount - 1)
	// 		target = last_read_size;
	// 	while (j < target)
	// 	{
	// 		str[k] = buffer[i][j];
	// 		j++;
	// 		k++;
	// 	}
	// 	i++;
	// }
	// str[k] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static t_line_info	line;
	char				*tmp;
	size_t				buf_len;

	if (fd < 0)
		return (NULL);
	if (!line.index || line.index >= line.last_read_size)
	{
		line.last_read_size = read(fd, line.buffer, BUFFER_SIZE);
		line.index = 0;
		line.start = 0;
	}	
	if (!line.last_read_size)
		return (NULL);
	while (line.index < line.last_read_size)
	{
		if (line.buffer[line.index] == '\n')
		{
			if (line.str)
			{
				tmp = malloc(ft_strlen(line.str) + line.index + 2);
				ft_strlcpy(tmp, line.str, ft_strlen(line.str) + 1);
				free(line.str);
				line.str = tmp;
			}
			ft_strlcat(line.str, line.buffer[line.start],
				ft_strlen(line.str) + line.index + 2);
			line.start = ++(line.index);
			return (line.str);
		}
		line.index++;
	}
	
	return (get_next_line(fd));
}

int main(void)
{
	int	fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	printf("Target FD: %i\n\n", fd);
	line = get_next_line(fd);
	while (line)
	{
		printf("Line 1: %s", line);
		line = get_next_line(fd);
	}
	printf("\nEnd of lines\n");
	return (0);
}
