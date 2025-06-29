#ifndef BONUS
	#include "get_next_line.h"
#else
	#include "get_next_line_bonus.h"
#endif
#include "stdio.h"
#include "fcntl.h"


int main(int argc, char **args)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	printf("BUFFER_SIZE: %lu\n", (size_t)BUFFER_SIZE);
	
	if (argc >= 2)
	{
		j = 1;
		while (j < argc)
		{
			printf("File: %s\n", args[j]);
			fd = open(args[j++], O_RDONLY);

			i = 1;
			line = get_next_line(fd);
			while (line)
			{
				printf("Line %i: %s", i++, line);
				free(line);
				line = get_next_line(fd);
			}
			printf("\n");
			close(fd);
		}
		return (0);
	}

	i = 1;
	line = get_next_line(0);
	while (line)
	{
		printf("Line %i: %s", i++, line);
		free(line);
		line = get_next_line(0);
	}	
	return (0);
}