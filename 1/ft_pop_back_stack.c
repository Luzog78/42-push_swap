/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_back_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:00:06 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 23:00:16 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pop_back_stack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!stack)
		return (NULL);
	if (!stack->next)
	{
		curr = stack;
		stack = NULL;
		return (curr);
	}
	curr = stack;
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	return (curr);
}
