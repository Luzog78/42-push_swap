/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_to_desc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:33:50 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 04:53:31 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*ft_rotate_stack_b(t_pos *pos);
static t_moves	*ft_get_rotation_moves(int max_index, int size);
static t_moves	*ft_get_push_a_moves(t_pos *pos);

void	ft_complete_stack_a_moves(t_pos *pos)
{
	t_moves	*moves_rot_b;
	t_moves	*moves_push_a;

	moves_rot_b = ft_rotate_stack_b(pos);
	moves_push_a = ft_get_push_a_moves(pos);
	ft_moves_get_last(moves_rot_b)->next = moves_push_a;
	ft_moves_get_last(pos->moves)->next = moves_rot_b;
}

static t_moves	*ft_rotate_stack_b(t_pos *pos)
{
	t_stack	*curr;
	t_stack	*prev;
	int		index;
	t_ll	max;
	int		max_index;

	curr = pos->stack_b;
	prev = NULL;
	index = 1;
	max_index = 0;
	max = curr->value;
	while (curr->next)
	{
		if (curr->next->value > max)
		{
			max = curr->next->value;
			max_index = index;
			prev = curr;
		}
		index++;
		curr = curr->next;
	}
	return (ft_get_rotation_moves(max_index, index));
}

static t_moves	*ft_get_rotation_moves(int max_index, int size)
{
	int		i;
	t_moves	*moves;

	i = 0;
	moves = NULL;
	if (max_index < size / 2)
	{
		while (max_index > 0)
		{
			ft_moves_add_front(&moves, ft_create_moves(RB));
			max_index--;
		}
	}
	else
	{
		while (max_index % size != 0)
		{
			ft_moves_add_front(&moves, ft_create_moves(RRB));
			max_index++;
		}
	}
	return (moves);
}

static t_moves	*ft_get_push_a_moves(t_pos *pos)
{
	t_moves	*moves;
	int		size;

	moves = NULL;
	size = ft_stack_size(pos->stack_b);
	while (size > 0)
	{
		ft_moves_add_front(&moves, ft_create_moves(PA));
		size--;
	}
	return (moves);
}
