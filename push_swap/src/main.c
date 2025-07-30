#include "push_swap.h"

int	*get_instructions(t_stack *stack, int size)
{
	int	*instructions;

	instructions = malloc(sizeof(int) * 1024);
	(void)stack;
	(void)size;
	// Analyze and sort the stack
	// Fill the instructions
	instructions[0] = INST_SWAP_A;
	instructions[1] = INST_SWAP_B;
	instructions[2] = INST_SWAP_AB;
	instructions[3] = INST_PUSH_A;
	instructions[4] = INST_PUSH_B;
	instructions[5] = INST_ROT_A;
	instructions[6] = INST_ROT_B;
	instructions[7] = INST_ROT_AB;
	instructions[8] = INST_RROT_A;
	instructions[9] = INST_RROT_B;
	instructions[10] = INST_RROT_AB;
	instructions[11] = INST_END;
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
