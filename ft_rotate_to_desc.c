/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_to_desc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:33:50 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 16:51:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_desc(t_pos *pos)
{
	t_ll	max;
	int		index;

	max = ft_stack_max(pos->stack_b);
	index = ft_stack_index_of(pos->stack_b, max);
	if (index < ft_stack_size(pos->stack_b) / 2)
		while (pos->stack_b->value != max)
			ft_exec_move(pos, RB);
	else
		while (pos->stack_b->value != max)
			ft_exec_move(pos, RRB);
}
