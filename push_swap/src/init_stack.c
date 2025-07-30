#include "push_swap.h"

static int is_duplicate(int num, t_stack *stack, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < i)
		{
			if (stack[j].number == stack[i].number)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_stack	*init_stack(char **arr, int argc)
{
	int			i;
	t_stack		*stack;
	long long	num;
	
	i = 0;
	stack = malloc(sizeof(t_stack) * argc);
	if (!stack)
		return (NULL);
	while (i < argc)
	{
		if (!is_number(arr[i]))
		{
			free(arr);
			return (NULL);
		}
		num = ft_atol(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(arr);
			return (NULL);
		}
		stack[i].index = i;
		stack[i].number = (int)num;
		if (!is_duplicate((int)num, stack, argc))
		{
			free(arr);
			return (NULL);
		}
	}
	return (stack);
}