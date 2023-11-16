/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:53:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 17:05:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pos	*ft_create_pos(void)
{
	t_pos	*new;

	new = ft_malloc(sizeof(t_pos));
	if (!new)
		return (NULL);
	new->stack_a = NULL;
	new->stack_b = NULL;
	new->moves = NULL;
	new->next = NULL;
	return (new);
}
