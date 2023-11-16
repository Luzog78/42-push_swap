/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:22:48 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/15 16:46:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sx(t_pos *pos, t_move_type move);
static void	ft_px(t_pos *pos, t_move_type move);
static void	ft_rx(t_pos *pos, t_move_type move);
static void	ft_rrx(t_pos *pos, t_move_type move);

void	ft_exec_move(t_pos *pos, t_move_type move)
{
	if (move == SA || move == SB || move == SS)
		ft_sx(pos, move);
	else if (move == PA || move == PB)
		ft_px(pos, move);
	else if (move == RA || move == RB || move == RR)
		ft_rx(pos, move);
	else if (move == RRA || move == RRB || move == RRR)
		ft_rrx(pos, move);
	else
		return ;
	ft_moves_add_back(&pos->moves, ft_create_moves(move));
}

static void	ft_sx(t_pos *pos, t_move_type move)
{
	t_stack	*tmp;

	if (move == SA && pos->stack_a && pos->stack_a->next)
	{
		tmp = pos->stack_a;
		pos->stack_a = pos->stack_a->next;
		tmp->next = pos->stack_a->next;
		pos->stack_a->next = tmp;
	}
	else if (move == SB && pos->stack_b && pos->stack_b->next)
	{
		tmp = pos->stack_b;
		pos->stack_b = pos->stack_b->next;
		tmp->next = pos->stack_b->next;
		pos->stack_b->next = tmp;
	}
	else if (move == SS)
	{
		ft_sx(pos, SA);
		ft_sx(pos, SB);
	}
}

static void	ft_px(t_pos *pos, t_move_type move)
{
	t_stack	*tmp;

	if (move == PA && pos->stack_b)
	{
		tmp = pos->stack_b;
		pos->stack_b = pos->stack_b->next;
		tmp->next = pos->stack_a;
		pos->stack_a = tmp;
	}
	else if (move == PB && pos->stack_a)
	{
		tmp = pos->stack_a;
		pos->stack_a = pos->stack_a->next;
		tmp->next = pos->stack_b;
		pos->stack_b = tmp;
	}
}

static void	ft_rx(t_pos *pos, t_move_type move)
{
	t_stack	*tmp;

	if (move == RA && pos->stack_a && pos->stack_a->next)
	{
		tmp = pos->stack_a;
		pos->stack_a = pos->stack_a->next;
		tmp->next = NULL;
		ft_stack_add_back(&pos->stack_a, tmp);
	}
	else if (move == RB && pos->stack_b && pos->stack_b->next)
	{
		tmp = pos->stack_b;
		pos->stack_b = pos->stack_b->next;
		tmp->next = NULL;
		ft_stack_add_back(&pos->stack_b, tmp);
	}
	else if (move == RR)
	{
		ft_rx(pos, RA);
		ft_rx(pos, RB);
	}
}

static void	ft_rrx(t_pos *pos, t_move_type move)
{
	if (move == RRA && pos->stack_a && pos->stack_a->next)
	{
		ft_stack_add_front(&pos->stack_a, ft_stack_pop_back(pos->stack_a));
	}
	else if (move == RRB && pos->stack_b && pos->stack_b->next)
	{
		ft_stack_add_front(&pos->stack_b, ft_stack_pop_back(pos->stack_b));
	}
	else if (move == RRR)
	{
		ft_rrx(pos, RRA);
		ft_rrx(pos, RRB);
	}
}
