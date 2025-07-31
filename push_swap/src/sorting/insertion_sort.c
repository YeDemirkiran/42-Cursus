#include "sorting.h"

int	*insertion_sort_ps(t_stack *stack, int size, int *instructions)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp_2;

	i = 1;
	j = 0;
	if (stack[i].number < stack[i - 1].number)
	{
		stack_swap(stack);
		instructions[j++] = INST_SWAP_A;
	}
	while (i < size)
	{
		if (stack[i].number < stack[i - 1].number)
		{
			tmp = stack[i - 1].index;
			tmp_2 = tmp;
			while (tmp-- > 0)
			{	
				stack_rotate(stack, size);
				instructions[j++] = INST_ROT_A;
			}	
			stack_swap(stack);
			instructions[j++] = INST_SWAP_A;
			while (tmp_2-- > 0)
			{	
				stack_rotate_rev(stack, size);
				instructions[j++] = INST_RROT_A;
			}
			i = 0;
		}
		i++;
	}
	instructions[j] = INST_END;
}