#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"


int main(int argc, char **args)
{
	int		fd;
	char	*line;

	//printf("BUFFER_SIZE: %lu\n", BUFFER_SIZE);
	
	if (argc >= 2)
		fd = open(args[1], O_RDONLY);
	else
		fd = 0;

	printf("Target FD: %i\n\n", fd);

	int i = 1;

	// line = get_next_line(fd);
	// printf("Line %i: '%s'", i++, line);
	// free(line);
	line = get_next_line(fd);
	printf("Line %i: '%s'", i++, line);
	free(line);
	line = get_next_line(-1);
	printf("Line %i: '%s'", i++, line);
	free(line);
	// line = get_next_line(-1);
	// printf("\nLine %i: '%s'", i++, line);
	// free(line);
	// line = get_next_line(-1);
	// printf("\nLine %i: '%s'", i++, line);
	// free(line);

	close(fd);
	if (argc >= 2)
		fd = open(args[1], O_RDONLY);
	else
		fd = 0;
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("Line %i: '%s'", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n\nEnd of lines\n");
	close(fd);
	return (0);
}