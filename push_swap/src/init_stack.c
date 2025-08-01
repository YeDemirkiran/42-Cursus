#include "push_swap.h"
//#include "stdio.h"

static int is_duplicate(t_stack *stack, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < index)
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

t_stack_pair	init_stack_pair(char **arr, int argc)
{
	int				i;
	t_stack_pair	pair;
	long long		num;
	
	i = 0;
	pair.stack_a = malloc(sizeof(t_stack) * argc);
	if (!pair.stack_a)
		return (pair);
	while (i < argc)
	{
		if (!ft_isnumber(arr[i]))
		{
			free(pair.stack_a);
			return (pair);
		}
		num = ft_atol(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(pair.stack_a);
			return (pair);
		}
		pair.stack_a[i].index = i;
		pair.stack_a[i].number = (int)num;
		if (!is_duplicate(pair.stack_a, i))
		{
			free(pair.stack_a);
			return (pair);
		}
		i++;
	}
	pair.stack_b = malloc(sizeof(t_stack) * argc);
	if (!pair.stack_b)
	{
		free(pair.stack_a);
		return (pair);
	}
	i = 0;
	while (i < argc)
	{
		pair.stack_b[i].number = 0;
		pair.stack_b[i].index = i;
		i++;
	}
	pair.a_length = argc;
	pair.b_length = 0;
	return (pair);
}