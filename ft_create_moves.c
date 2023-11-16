/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:20:25 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:02:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*ft_create_moves(t_move_type move)
{
	t_moves	*new;

	new = malloc(sizeof(t_moves));
	if (!new)
		return (NULL);
	new->type = move;
	new->next = NULL;
	return (new);
}
