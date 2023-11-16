/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:46:30 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:02:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_clone_stack(t_stack *stack)
{
	t_stack	*new;
	t_stack	*curr;

	new = NULL;
	if (stack)
	{
		curr = malloc(sizeof(t_stack));
		curr->value = stack->value;
		curr->next = NULL;
		new = curr;
		stack = stack->next;
	}
	while (stack)
	{
		curr->next = malloc(sizeof(t_stack));
		curr = curr->next;
		curr->value = stack->value;
		curr->next = NULL;
		stack = stack->next;
	}
	return (new);
}
