#ifndef STACK_H

# define STACK_H

typedef struct s_stack 
{
	int	number;
	int	index;
}			t_stack;

enum e_instructions 
{
	INST_END = 0,
	INST_SWAP_A = 1,
	INST_SWAP_B = 2,
	INST_SWAP_AB = 3,
	INST_PUSH_A = 4,
	INST_PUSH_B = 5,
	INST_ROT_A = 6,
	INST_ROT_B = 7,
	INST_ROT_AB = 8,
	INST_RROT_A = 9,
	INST_RROT_B = 10,
	INST_RROT_AB = 11,
};

void	stack_rotate(t_stack *stack, int size);
void	stack_rotate_rev(t_stack *stack, int size);
void	stack_swap(t_stack *stack);

t_stack	*init_stack(char **arr, int argc);

#endif