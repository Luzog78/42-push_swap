/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:37:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 16:38:16 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_moves_size(t_moves *moves)
{
	int		size;

	size = 0;
	while (moves)
	{
		size++;
		moves = moves->next;
	}
	return (size);
}
