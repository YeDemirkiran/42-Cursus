#include "push_swap.h"

int	*get_instructions(t_stack_pair pair, int size)
{
	int	*instructions;

	instructions = malloc(sizeof(int) * 1024);
	if (!instructions)
		return (NULL);
	
	// (void)stack;
	// (void)size;
	// Analyze the stack and choose an algorithm
	// Sort and fill the instructions
	bubble_sort_ps(pair.stack_a, size, instructions);
	return (instructions);
}

void	print_instructions(int *instructions)
{
	int	i;
	const char	*inst[] = {NULL, "sa", "sb", "ss", "pa", "pb",
				"ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (instructions[i])
	{
		if (instructions[i] == INST_NONE)
			continue ;
		ft_putstr((char *)inst[instructions[i]]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_pair	pair;
	int				*instructions;

	if (argc <= 2)
		return (EXIT_FAILURE);
	pair = init_stack_pair(argv + 1, argc - 1);
	if (!pair.stack_a || !pair.stack_b)
	{
		ft_putstr_fd("Error\n", 2);
		return(EXIT_FAILURE);
	}
	instructions = get_instructions(pair, argc - 1);
	if (!instructions)
	{
		ft_putstr_fd("Error\n", 2);
		return(EXIT_FAILURE);
	}
	print_instructions(instructions);
	free(instructions);
	free(pair.stack_a);
	free(pair.stack_b);
	return (EXIT_SUCCESS);
}
