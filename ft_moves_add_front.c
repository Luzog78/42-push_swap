/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 04:24:35 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 04:24:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves_add_front(t_moves **moves, t_moves *new)
{
	if (!moves || !new)
		return ;
	new->next = *moves;
	*moves = new;
}
