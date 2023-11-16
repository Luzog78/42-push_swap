/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_targets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:19:52 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 07:39:26 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief	Updates the target of each element in `stack_a`.
 * 			The target is the value of the greatest smaller
 * 			element in `stack_b` of the current element.
 * 			If there is no smaller element, the target is LLONG_MIN_ALMOST.
 * 			Example: stack_a = [5, 3, 0], stack_b = [4, 2, 1]
 * 				5.target = 4
 * 				3.target = 2
 * 				0.target = LLONG_MAX
 * 
 * @note	PRECAUTION: `stack_b` must not be empty.
 * @note	PRECAUTION: There must not be any duplicate in the stacks.
 * @note	OBJECTIVE: Sort `stack_b` in descending order. (greates to smallest)
 * 
 * @param pos	Current position
*/
void	ft_update_targets(t_pos *pos)
{
	t_stack	*curr;
	t_stack	*tmp;
	t_ll	max;

	curr = pos->stack_a;
	while (curr)
	{
		tmp = pos->stack_b;
		curr->target = LLONG_MIN_ALMOST;
		max = LLONG_MIN_ALMOST;
		while (tmp)
		{
			if (tmp->value < curr->value && tmp->value > curr->target)
				curr->target = tmp->value;
			if (tmp->value > max)
				max = tmp->value;
			tmp = tmp->next;
		}
		if (curr->target == LLONG_MIN_ALMOST)
			curr->target = max;
		curr = curr->next;
	}
}
