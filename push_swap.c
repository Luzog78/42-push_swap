/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:27 by luzog             #+#    #+#             */
/*   Updated: 2023/11/16 08:53:33 by ysabik           ###   ########.fr       */
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
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
		if (pos->stack_a->value > pos->stack_a->next->next->value)
			ft_exec_move(pos, RRA);
		else if (pos->stack_a->next->value > pos->stack_a->next->next->value)
			ft_exec_move(pos, RA);
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
	}
}

int	main(int argc, char **argv)
{
	t_pos	*pos;

	argc--;
	argv++;
	if (!argc)
		return (0);
	pos = ft_create_pos();
	if (!ft_parse(pos, argc, argv))
		return (0);
	if (ft_stack_size(pos->stack_a) <= 3)
		ft_tiny_sort_algo(pos);
	else
		ft_custom_times_algo(pos);
	ft_print_solution(pos);
	ft_free_pos(pos);
	return (0);
}
