/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_equals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:04:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 22:59:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_equals(t_stack *stack1, t_stack *stack2)
{
	while (stack1 && stack2)
	{
		if (stack1->value != stack2->value)
			return (0);
		stack1 = stack1->next;
		stack2 = stack2->next;
	}
	if (stack1 || stack2)
		return (0);
	return (1);
}
