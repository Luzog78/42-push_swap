/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:07:28 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:02:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*curr;

	while (stack)
	{
		curr = stack;
		stack = stack->next;
		ft_free_moves(curr->path);
		free(curr);
	}
}
