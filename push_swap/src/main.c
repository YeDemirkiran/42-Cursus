#include "push_swap.h"

int	*get_instructions(t_stack *stack, int size)
{
	int	*instructions;

	instructions = malloc(sizeof(int) * 1024);
	if (!instructions)
		return (NULL);
	
	// (void)stack;
	// (void)size;
	// Analyze the stack and choose an algorithm
	// Sort and fill the instructions
	bubble_sort_ps(stack, size, instructions);
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
		ft_putstr((char *)inst[instructions[i]]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		*instructions;

	if (argc <= 2)
		return (EXIT_FAILURE);
	stack = init_stack(argv + 1, argc - 1);
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return(EXIT_FAILURE);
	}
	instructions = get_instructions(stack, argc - 1);
	if (!instructions)
	{
		ft_putstr_fd("Error\n", 2);
		return(EXIT_FAILURE);
	}
	print_instructions(instructions);
	free(instructions);
	free(stack);
	return (EXIT_SUCCESS);
}
