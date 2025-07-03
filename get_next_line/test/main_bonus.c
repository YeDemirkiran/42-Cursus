#ifndef BONUS
	#include "get_next_line.h"
#else
	#include "get_next_line_bonus.h"
#endif
#include "stdio.h"
#include "fcntl.h"


int main(int argc, char **args)
{
	int	fd[1024];
	char	*line;
	int		j;
	int		done;

	setbuf(stdout, NULL);
	printf("BUFFER_SIZE: %lu\n", (size_t)BUFFER_SIZE);
	
	if (argc >= 2)
	{
		j = 1;
		while (j < argc)
		{
			fd[j - 1] = open(args[j], O_RDONLY);
			j++;
		}
		done = 1;
		while (done > 0)
		{
			done = 0;
			j = 1;
			while (j < argc)
			{
				if (fd[j - 1] == -1)
				{
					//done = 0;
					j++;
					//printf("File completed, continue\n");
					continue ;
				}
				line = get_next_line(fd[j - 1]);
				if (line)
				{
					printf("(%s): %s", args[j], line);
					free(line);
				}
				else
				{
					printf("End of (%s)\n", args[j]);
					fd[j - 1] = -1;
				}
				j++;
				done++;
			}
		}
		
		return (0);
	}

	// line = get_next_line(0);
	// while (line)
	// {
	// 	printf("STDIN, Line %i: %s", line);
	// 	free(line);
	// 	line = get_next_line(0);
	// }	
	return (0);
}