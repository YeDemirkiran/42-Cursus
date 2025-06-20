#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// typedef struct s_int2
// {
// 	int	x;
// 	int	y;
// }			t_int2;

typedef struct s_line_info 
{
	char	*str;
	char	buffer[BUFFER_SIZE];
	ssize_t	last_read_size;
	int		start;
	int		index;
}			t_line_info;

#endif