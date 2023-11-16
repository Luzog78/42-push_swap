/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:00:52 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 23:48:04 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves_add_back(t_moves **moves, t_moves *new)
{
	t_moves	*curr;

	if (!*moves)
		*moves = new;
	else
	{
		curr = *moves;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
