/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:48:18 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 07:39:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(t_ll value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->target = LLONG_MIN_ALMOST;
	new->path = NULL;
	new->cost = INT_MAX;
	new->next = NULL;
	return (new);
}
