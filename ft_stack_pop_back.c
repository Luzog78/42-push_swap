/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:43:15 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 16:43:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_pop_back(t_stack *stack)
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
