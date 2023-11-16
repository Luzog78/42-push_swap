/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 23:06:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_equals(t_pos *pos1, t_pos *pos2)
{
	return (ft_stack_equals(pos1->stack_a, pos2->stack_a)
		&& ft_stack_equals(pos1->stack_b, pos2->stack_b));
}
