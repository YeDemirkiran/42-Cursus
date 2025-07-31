#include "sorting.h"
#include "stack.h"
#include "array.h"

int	*bubble_sort(const int *arr, size_t len)
{
	int		*new_arr;
	int		tmp;
	size_t	i;

	new_arr = dup_int_array(arr, len);
	i = 1;
	while (i < len)
	{
		if (new_arr[i] < new_arr[i - 1])
		{
			tmp = new_arr[i];
			new_arr[i] = new_arr[i - 1];
			new_arr[i - 1] = tmp;
			i = 1;
			continue;
		}
		i++;
	}
	return (new_arr);
}

#include "stdio.h"

void bubble_sort_ps(t_stack *stack, int size, int *instructions)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp_2;

	i = 1;
	j = 0;
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
