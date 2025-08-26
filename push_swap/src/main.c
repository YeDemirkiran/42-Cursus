/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:06 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/26 13:04:08 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_instructions	*get_instructions(t_stack_pair *pair)
{
	t_instructions	*instructions;

	instructions = malloc(sizeof(t_instructions));
	if (!instructions)
		return (NULL);
	instructions->arr = malloc(sizeof(t_byte) * 8192);
	if (!instructions->arr)
		return (NULL);
	instructions->index = 0;
	chunk_sort(pair, instructions);
	return (instructions);
}

static void	print_instructions(t_byte *instructions)
{
	int			i;
	const char	*inst[] = {NULL, "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (instructions[i] != (t_byte)INST_END)
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
	t_instructions	*instructions;

	if (argc <= 2)
		return (EXIT_FAILURE);
	pair = init_stack_pair(argv + 1, argc - 1);
	if (!pair.stack_a || !pair.stack_b)
		return (err_print(clear_pair, &pair));
	instructions = get_instructions(&pair);
	if (!instructions || !instructions->arr)
		return (err_print(clear_pair, &pair));
	print_instructions(instructions->arr);
	// int i = 0;
	// while (i < pair.full_length)
	// {
	// 	printf("%i ", pair.stack_a[i].number);
	// 	i++;
	// }
	// printf("\n");
	free(instructions->arr);
	free(instructions);
	clear_pair(&pair);
	return (EXIT_SUCCESS);
}
