/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_exists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:04:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 23:04:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_exists(t_pos *history, t_pos *pos)
{
	t_pos	*curr;

	curr = history;
	while (curr)
	{
		if (ft_pos_equals(curr, pos))
			return (1);
		curr = curr->next;
	}
	return (0);
}
