#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# ifndef INSTRUCTONS_SIZE
#  define INSTRUCTIONS_SIZE 32768
# endif

# include <stdlib.h>

# include "t_instructions.h"

int		init_instructions(t_instructions *inst_arr, int length);
void	clear_instructions(t_instructions *inst_arr,
			int length, int preserve_index);

#endif