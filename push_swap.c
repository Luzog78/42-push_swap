/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:27 by luzog             #+#    #+#             */
/*   Updated: 2023/11/20 21:40:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_custom_times_algo(t_pos *pos)
{
	ft_exec_move(pos, PB);
	ft_exec_move(pos, PB);
	if (pos->stack_b->value < pos->stack_b->next->value)
		ft_exec_move(pos, SB);
	while (pos->stack_a)
	{
		ft_update_targets(pos);
		ft_update_paths(pos);
		ft_exec_move_cheapest(pos);
	}
	ft_complete_stack_a_moves(pos);
}

void	ft_tiny_sort_algo(t_pos *pos)
{
	if (ft_stack_size(pos->stack_a) == 2)
	{
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
	}
	else if (ft_stack_size(pos->stack_a) == 3)
	{
		if (pos->stack_a->value > pos->stack_a->next->value
			&& pos->stack_a->value > pos->stack_a->next->next->value)
			ft_exec_move(pos, RA);
		else if (pos->stack_a->next->value > pos->stack_a->value
			&& pos->stack_a->next->value > pos->stack_a->next->next->value)
			ft_exec_move(pos, RRA);
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
	}
}

int	main(int argc, char **argv)
{
	t_pos	*pos;
	int		size;

	argc--;
	argv++;
	if (!argc)
		return (0);
	pos = ft_create_pos();
	if (!ft_parse(pos, argc, argv))
		return (0);
	if (ft_check_solution(pos))
	{
		ft_free_pos(pos);
		return (0);
	}
	size = ft_stack_size(pos->stack_a);
	if (size <= 3)
		ft_tiny_sort_algo(pos);
	else if (size <= 5)
		ft_small_sort_algo(pos, size == 5);
	else
		ft_custom_times_algo(pos);
	ft_print_solution(pos);
	ft_free_pos(pos);
	return (0);
}
