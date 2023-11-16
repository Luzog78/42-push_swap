/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:07:38 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:02:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_pos(t_pos **pos)
{
	t_pos	*curr;

	while (*pos)
	{
		curr = *pos;
		*pos = (*pos)->next;
		ft_free_stack(&curr->stack_a);
		ft_free_stack(&curr->stack_b);
		ft_free_moves(&curr->moves);
		free(curr);
	}
}
