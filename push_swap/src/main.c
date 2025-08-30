/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:06 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 14:28:31 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_instructions	get_instructions(t_stack_pair *pair)
{
	t_instructions	instructions;

	instructions.arr = NULL;
	chunk_sort(pair, &instructions);
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
	t_instructions	instructions;

	if (argc <= 1)
		return (EXIT_FAILURE);
	pair = init_stack_pair(argv + 1, argc - 1);
	if (!pair.stack_a || !pair.stack_b)
		return (err_print(clear_pair, &pair));
	if (is_stack_sorted(pair.stack_a, pair.a_length))
	{
		clear_pair(&pair);
		return (0);
	}
	instructions = get_instructions(&pair);
	if (!instructions.arr)
		return (err_print(clear_pair, &pair));
	print_instructions(instructions.arr);
	free(instructions.arr);
	clear_pair(&pair);
	return (EXIT_SUCCESS);
}
