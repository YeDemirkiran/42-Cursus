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

char	*get_next_line(int fd)
{
	static t_line_info	line;
	char				*tmp;
	// size_t				buf_len;

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
			// if (line.str)
			// {
			// 	// tmp = malloc(ft_strlen(line.str) + line.index + 2);
			// 	// ft_strlcpy(tmp, line.str, ft_strlen(line.str) + 1);
			// 	// free(line.str);
			// 	// line.str = tmp;
			// }
			// else
			// {
				
			// }
			// printf("Size: %i\n", (line.index - line.start) + 2);
			// printf("Copy starts with: %c\n", line.buffer[line.start]);
			// printf("Copy ends with: %c\n", line.buffer[line.index + 1]);
			tmp = malloc((line.index - line.start) + 2);
			ft_strlcpy(tmp, line.buffer + line.start, (line.index - line.start) + 2);
			//printf("New line ends with: (%c), before (%c)", tmp[(line.index - line.start) + 1], tmp[(line.index - line.start)]);
			//printf("Line start: %i, Index: %i\n", line.start, line.index);
			line.start = ++(line.index);
			//printf("Line start: %i, Index: %i\n", line.start, line.index);
			return (tmp);
			// ft_strlcat(line.str, line.buffer[line.start],
			// 	ft_strlen(line.str) + line.index + 2);
			// line.start = ++(line.index);
			//return (line.str);
		}
		line.index++;
	}
	//return (get_next_line(fd));
	return (NULL);
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
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\nEnd of lines\n");
	return (0);
}
