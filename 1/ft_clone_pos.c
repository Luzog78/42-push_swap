/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:03:35 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:02:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pos	*ft_clone_pos(t_pos *pos)
{
	t_pos	*new;

	new = malloc(sizeof(t_pos));
	new->stack_a = ft_clone_stack(pos->stack_a);
	new->stack_b = ft_clone_stack(pos->stack_b);
	new->moves = ft_clone_moves(pos->moves);
	new->next = NULL;
	return (new);
}
