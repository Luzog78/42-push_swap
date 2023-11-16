/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_get_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 04:25:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 04:25:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*ft_moves_get_last(t_moves *moves)
{
	if (!moves)
		return (NULL);
	while (moves->next)
		moves = moves->next;
	return (moves);
}
