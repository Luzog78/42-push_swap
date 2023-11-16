/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:02:06 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 16:51:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_pos *pos)
{
	t_stack	*stack_a;
	t_ll	max;

	stack_a = pos->stack_a;
	max = ft_stack_max(stack_a);
	if (stack_a->value == max)
		ft_exec_move(pos, RA);
	else if (stack_a->next->value == max)
		ft_exec_move(pos, RRA);
	if (stack_a->value > stack_a->next->value)
		ft_exec_move(pos, SA);
}
