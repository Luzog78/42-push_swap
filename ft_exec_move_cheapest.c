/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_move_cheapest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:58:30 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 01:28:10 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_move_cheapest(t_pos *pos)
{
	t_stack	*curr;
	t_stack	*cheapest;
	t_moves	*path;

	curr = pos->stack_a;
	cheapest = curr;
	while (curr->next)
	{
		curr = curr->next;
		if (curr->cost < cheapest->cost)
			cheapest = curr;
	}
	path = cheapest->path;
	while (path)
	{
		ft_exec_move(pos, path->type);
		path = path->next;
	}
}
