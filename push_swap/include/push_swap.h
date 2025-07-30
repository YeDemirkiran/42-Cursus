#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "dependencies.h"

# include "predicate.h"
# include "converter.h"
# include "sorting.h"
# include "write.h"
# include "ft_string.h"

typedef struct s_stack 
{
	int	number;
	int	index;
}			t_stack;

t_stack	*init_stack(char **arr, int argc);

#endif