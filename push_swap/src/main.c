#include "push_swap.h"

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
	// instructions = get_instructions(stack, argc - 1);
	// if (!instructions)
	// 		fail
	// print_instructions(instructions);
	// free(instructions);
	(void)stack;
	(void)instructions;
	free(stack);
	ft_putstr_fd("pa\n", 1);
	return (EXIT_SUCCESS);
}
