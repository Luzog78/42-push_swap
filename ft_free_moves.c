/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:18:47 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 17:05:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_moves(t_moves *moves)
{
	t_moves	*curr;

	while (moves)
	{
		curr = moves;
		moves = moves->next;
		ft_free(curr);
	}
}
