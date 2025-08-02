/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:06 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 12:17:03 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_byte	*get_instructions(t_stack_pair pair, int size)
{
	t_byte	*instructions;

	instructions = malloc(sizeof(*instructions) * 1024);
	if (!instructions)
		return (NULL);
	bubble_sort_ps(pair.stack_a, size, instructions);
	return (instructions);
}

void	print_instructions(t_byte *instructions)
{
	int			i;
	const char	*inst[] = {NULL, "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (instructions[i])
	{
		if (instructions[i] == (t_byte)INST_NONE)
			continue ;
		ft_putstr((char *)inst[(int)instructions[i]]);
		ft_putchar('\n');
		i++;
	}
}

static void	clear_pair(t_stack_pair *pair)
{
	if ((*pair).stack_a)
		free((*pair).stack_a);
	if ((*pair).stack_b)
		free((*pair).stack_b);
}

static int	err_print(void (*clear)(t_stack_pair *), t_stack_pair *pair)
{
	if (clear && pair)
		clear(pair);
	ft_putstr_fd("Error\n", 2);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack_pair	pair;
	t_byte			*instructions;

	if (argc <= 2)
		return (EXIT_FAILURE);
	pair = init_stack_pair(argv + 1, argc - 1);
	if (!pair.stack_a || !pair.stack_b)
		return (err_print(clear_pair, &pair));
	instructions = get_instructions(pair, argc - 1);
	if (!instructions)
		return (err_print(clear_pair, &pair));
	print_instructions(instructions);
	free(instructions);
	clear_pair(&pair);
	return (EXIT_SUCCESS);
}
