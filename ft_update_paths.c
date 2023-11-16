/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:53:32 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 03:50:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reset_path(t_stack *curr);

void	ft_update_paths(t_pos *pos)
{
	t_path_calc	path_calc;
	t_stack		*curr;

	path_calc.curr_i = 0;
	path_calc.stack_a_size = ft_stack_size(pos->stack_a);
	path_calc.stack_b_size = ft_stack_size(pos->stack_b);
	curr = pos->stack_a;
	while (curr)
	{
		ft_reset_path(curr);
		path_calc.target_i = ft_stack_index_of(pos->stack_b, curr->target);
		ft_calc_path(path_calc, curr);
		curr = curr->next;
		path_calc.curr_i++;
	}
}

static void	ft_reset_path(t_stack *curr)
{
	if (curr->path)
	{
		ft_free_moves(curr->path);
		curr->path = NULL;
	}
	curr->cost = INT_MAX;
}
