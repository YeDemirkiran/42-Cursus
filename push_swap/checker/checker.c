/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:41:37 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 16:31:15 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_valid_move(char *str)
{
	const char	*inst[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	if (!str)
		return (-1);
	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(str, inst[i], ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

t_instructions	parse_instructions(void)
{
	t_instructions	instructions;
	char			*line;
	int				index;

	instructions.arr = malloc(sizeof(t_byte) * INSTRUCTIONS_SIZE);
	if (!instructions.arr)
		return (instructions);
	init_instruction_empty(&instructions, INSTRUCTIONS_SIZE);
	line = get_next_line(0);
	while (line)
	{
		index = is_valid_move(line);
		if (index == -1)
		{
			free(line);
			free(instructions.arr);
			break ;
		}
		instructions.arr[instructions.index++] = (index + 1);
		free(line);
		line = get_next_line(0);
	}
	return (instructions);
}

void	apply_instructions(t_stack_pair *pair, t_instructions *instructions)
{
	int	i;

	i = 0;
	while (instructions->arr[i] != INST_END)
	{
		if (instructions->arr[i] == INST_PUSH_A)
			stack_push_a_to_b(pair);
		else if (instructions->arr[i] == INST_PUSH_B)
			stack_push_b_to_a(pair);
		else if (instructions->arr[i] == INST_ROT_A)
			stack_rotate_a(*pair);
		else if (instructions->arr[i] == INST_ROT_B)
			stack_rotate_b(*pair);
		else if (instructions->arr[i] == INST_ROT_AB)
			stack_rotate_ab(*pair);
		else if (instructions->arr[i] == INST_RROT_A)
			stack_rotate_rev_a(*pair);
		else if (instructions->arr[i] == INST_RROT_B)
			stack_rotate_rev_b(*pair);
		else if (instructions->arr[i] == INST_RROT_AB)
			stack_rotate_rev_ab(*pair);
		else if (instructions->arr[i] == INST_SWAP_A)
			stack_swap_a(*pair);
		else if (instructions->arr[i] == INST_SWAP_B)
			stack_swap_b(*pair);
		else if (instructions->arr[i] == INST_SWAP_AB)
			stack_swap_ab(*pair);
		i++;
	}
}

int	verify_instructions(t_stack_pair *pair, t_instructions *instructions)
{
	apply_instructions(pair, instructions);
	free(instructions->arr);
	if (pair->a_length != pair->full_length || pair->b_length > 0
		|| !is_stack_sorted(pair->stack_a, pair->a_length))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_pair	pair;
	t_instructions	instructions;

	if (argc <= 1)
		return (EXIT_FAILURE);
	pair = init_stack_pair(argv + 1, argc - 1);
	if (!pair.stack_a || !pair.stack_b)
		return (err_print("Error\n", clear_pair, &pair));
	if (is_stack_sorted(pair.stack_a, pair.a_length))
	{
		clear_pair(&pair);
		return (EXIT_SUCCESS);
	}
	instructions = parse_instructions();
	if (!instructions.arr)
		return (err_print("Error\n", clear_pair, &pair));
	else if (!verify_instructions(&pair, &instructions))
		return (err_print("KO\n", clear_pair, &pair));
	ft_putstr_fd("OK\n", 1);
	clear_pair(&pair);
	return (EXIT_SUCCESS);
}
