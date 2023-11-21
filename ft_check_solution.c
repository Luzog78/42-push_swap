/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:38:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/20 21:39:02 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_solution(t_pos *pos)
{
	t_stack	*tmp;
	int		is_valid;

	tmp = pos->stack_a;
	is_valid = !pos->stack_b;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			is_valid = 0;
			break ;
		}
		tmp = tmp->next;
	}
	return (is_valid);
}
