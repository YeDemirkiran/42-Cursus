#ifndef T_STACK_PAIR_H
# define T_STACK_PAIR_H

# include "t_stack.h"

typedef struct s_stack_pair
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int		a_length;
	int		b_length;
	int		full_length;
}			t_stack_pair;

#endif
