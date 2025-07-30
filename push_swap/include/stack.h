#ifndef STACK_H

# define STACK_H

typedef struct s_stack 
{
	int	number;
	int	index;
}			t_stack;

void	stack_rotate(t_stack *stack, int size);
void	stack_rotate_rev(t_stack *stack, int size);
void	stack_swap(t_stack *stack);

#endif