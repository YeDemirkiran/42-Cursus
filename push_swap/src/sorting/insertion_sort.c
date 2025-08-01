#include "sorting.h"

void	move_between(t_stack_pair pair, t_stack target, t_stack min, t_stack max, int *instructions)
{
	int	min_num;
	int	max_num;
	int	target_num;
	int	index;

	min_num = min.number;
	max_num = max.number;
	target_num = target.number;
	index = (min.index + max.index) / 2;
	while (pair.stack_a[0].number != target_num)
	{
		if (pair.a_length - target.index < target.index) // Rotate right
		{
			stack_rotate_rev_a(pair);
		}	
			
		else  												// Rotate left
			stack_rotate_a(pair);
	}	
}

int	*insertion_sort_ps(t_stack_pair pair, int *instructions)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp_2;

	i = 1;
	j = 0;
	i++;
	while (i < pair.stack_a)
	{
		if (pair.stack_a[i].number < pair.stack_a[i - 1].number)
		{
			
		}
		i++;
	}
	instructions[j] = INST_END;
}