#ifndef CHUNK_SORT_H
# define CHUNK_SORT_H

# ifndef MAX_CHUNK_SIZE
#  define MAX_CHUNK_SIZE 10
# endif

# ifndef INSTRUCTONS_SIZE
#  define INSTRUCTIONS_SIZE 32768
# endif

# include <limits.h>
# include <stdlib.h>

# include "stack.h"
# include "e_instructions.h"

# include "pair_utils.h"

void	chunk_sort(t_stack_pair *pair, t_instructions *instructions);

#endif