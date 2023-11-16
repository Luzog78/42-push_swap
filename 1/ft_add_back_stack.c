/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:59:32 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 23:00:39 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back_stack(t_stack **stack, t_stack *new)
{
	t_stack	*curr;

	if (!*stack)
		*stack = new;
	else
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
