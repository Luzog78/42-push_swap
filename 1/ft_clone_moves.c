/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:26:13 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 17:05:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*ft_clone_moves(t_moves *moves)
{
	t_moves	*new;
	t_moves	*curr;

	new = NULL;
	if (moves)
	{
		curr = ft_malloc(sizeof(t_moves));
		curr->type = moves->type;
		curr->next = NULL;
		new = curr;
		moves = moves->next;
	}
	while (moves)
	{
		curr->next = ft_malloc(sizeof(t_moves));
		curr = curr->next;
		curr->type = moves->type;
		curr->next = NULL;
		moves = moves->next;
	}
	return (new);
}
