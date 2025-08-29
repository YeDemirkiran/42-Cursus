/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:10:39 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/26 13:12:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	push_chunks(t_stack_pair *pair, t_instructions *instructions, int chunk_size)
{
	int		chunk_border;
	int		current_border;
	int		i;
	t_stack	tmp;

	chunk_border = pair->full_length / chunk_size;
	current_border = 0;
	while (current_border <= chunk_size)
	{
		i = 0;
		while (i < chunk_border)
		{
			if (current_border == chunk_size
				&& i >= pair->a_length % chunk_size)
				break ;
			tmp = get_between(pair->stack_a, pair->a_length,
					chunk_border * current_border,
					chunk_border * (current_border + 1));
			stack_a_move_to_first(*pair, tmp, instructions);
			instructions->arr[instructions->index++] = stack_push_a_to_b(pair);
			i++;
		}
		current_border++;
	}
}

// while (!is_stack_sorted(pair->stack_a, pair->a_length))
// {
// 	if (pair->stack_a[0].number > pair->stack_a[1].number
//&& pair->stack_a[0].number > pair->stack_a[2].number)
// 		instructions->arr[instructions->index++] = stack_swap_a(*pair);
// 	else if (pair->stack_a[0].number > pair->stack_a[1].number)
// 		instructions->arr[instructions->index++] = stack_rotate_a(*pair);
// 	else
// 		instructions->arr[instructions->index++] = stack_rotate_rev_a(*pair);
// }

static int	calculate_cost(t_stack_pair *pair, int i, int *tmp_index)
{
	int	cost;
	int	j;

	*tmp_index = get_place_before(pair->stack_a,
			pair->a_length, pair->stack_b[i].number).index;
	if (*tmp_index < 0)
		return (-1);
	j = i;
	if (i > pair->b_length / 2)
		j = pair->b_length - i;
	cost = *tmp_index + j;
	if (*tmp_index > pair->a_length / 2)
		cost = pair->a_length - *tmp_index + j;
	return (cost);
}

static void	get_cheapest_b(t_stack_pair *pair, t_stack arr[2])
{
	int		current_cost;
	int		tmp_cost;
	int		tmp_index;
	int		i;

	current_cost = INT_MAX;
	arr[0].index = -1;
	arr[1].index = -1;
	i = 0;
	while (i < pair->b_length)
	{
		tmp_cost = calculate_cost(pair, i, &tmp_index);
		if (tmp_cost < 0)
			break ;
		if (tmp_cost < current_cost)
		{
			current_cost = tmp_cost;
			arr[0] = pair->stack_a[tmp_index];
			arr[1] = pair->stack_b[i];
		}
		i++;
	}
}

static void	sort_stack(t_stack_pair *pair, t_instructions *instructions)
{
	t_stack	cheapest[2];

	while (pair->b_length)
	{
		get_cheapest_b(pair, cheapest);
		if (cheapest->index > -1)
			stack_ab_move_to_first(*pair, cheapest, instructions);
		instructions->arr[instructions->index++] = stack_push_b_to_a(pair);
		if (pair->stack_a[0].number < pair->stack_a[1].number
			&& pair->stack_a[0].number
			< pair->stack_a[pair->a_length - 1].number)
			instructions->arr[instructions->index++] = stack_swap_a(*pair);
	}
}

static int	init_instructions(t_instructions *inst_arr, int length)
{
	int	i;
	int	clear;

	i = 0;
	clear = 0;
	while (i < length)
	{
		inst_arr[i].arr = malloc(sizeof(t_byte) * INSTRUCTIONS_SIZE);
		if (!inst_arr[i].arr)
		{
			clear = 1;
			i--;
			break ;
		}
		inst_arr[i].index = 0;
		i++;
	}
	if (clear)
	{
		while (i >= 0)
			free (inst_arr[i--].arr);
		return (0);
	}
	return (1);
}

void	clear_instructions(t_instructions *inst_arr, int length, int preserve_index)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		if (i == preserve_index)
			continue ;
		free(inst_arr[i].arr);
	}
}

void	chunk_sort(t_stack_pair *pair, t_instructions *instructions)
{
	t_stack			tmp;
	t_stack_pair	tmp_pair;
	t_instructions	tmp_insts[MAX_CHUNK_SIZE];
	int				i;
	int				inst_len;
	int				chosen_inst_index;

	if (is_stack_sorted(pair->stack_a, pair->a_length))
		return ;
	if (!init_instructions(tmp_insts, MAX_CHUNK_SIZE))
		return ;
	i = 0;
	inst_len = INT_MAX;
	while (i + 1 <= MAX_CHUNK_SIZE)
	{
		// printf("LET'S START %i\n", i);
		// fflush(stdout);
		tmp_pair = duplicate_pair(pair);
		push_chunks(&tmp_pair, tmp_insts + i, i + 1);
		// printf("Pushed chunks\n");
		// fflush(stdout);
		sort_stack(&tmp_pair, tmp_insts + i);
		// printf("Sorted chunks\n");
		// fflush(stdout);
		tmp = get_smallest(tmp_pair.stack_a, tmp_pair.a_length);
		stack_a_move_to_first(tmp_pair, tmp, tmp_insts + i);
		// printf("Moved chunks\n");
		// fflush(stdout);
		if (tmp_insts[i].index < inst_len)
		{
			inst_len = tmp_insts[i].index;
			chosen_inst_index = i;
		}
		clear_pair(&tmp_pair);
		// printf("Cleared pair\n");
		// fflush(stdout);
		i++;
	}
	*instructions = tmp_insts[chosen_inst_index];
	clear_instructions(tmp_insts, MAX_CHUNK_SIZE, chosen_inst_index);
}
