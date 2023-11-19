/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:23:17 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/19 22:35:47 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ll	ft_get_target(t_stack *stack, t_ll val);
static void	ft_custom_tiny_sort(t_pos *pos, int big_size);
static void	ft_push_first(t_pos *pos);
static void	ft_push_second(t_pos *pos, int big_size);

void	ft_small_sort_algo(t_pos *pos, int big_size)
{
	t_ll	target;

	ft_exec_move(pos, PB);
	if (big_size)
		ft_exec_move(pos, PB);
	ft_custom_tiny_sort(pos, big_size);
	ft_push_first(pos);
	ft_push_second(pos, big_size);
	target = ft_stack_min(pos->stack_a);
	while (ft_stack_index_of(pos->stack_a, target)
		> ft_stack_size(pos->stack_a) / 2 && pos->stack_a->value != target)
		ft_exec_move(pos, RRA);
	while (ft_stack_index_of(pos->stack_a, target)
		<= ft_stack_size(pos->stack_a) / 2 && pos->stack_a->value != target)
		ft_exec_move(pos, RA);
}

static t_ll	ft_get_target(t_stack *stack, t_ll val)
{
	t_stack	*curr;
	t_ll	target;

	target = LLONG_MAX;
	curr = stack;
	while (curr)
	{
		if (curr->value < target && curr->value > val)
			target = curr->value;
		curr = curr->next;
	}
	return (target);
}

static void	ft_custom_tiny_sort(t_pos *pos, int big_size)
{
	int	both_modifier;

	both_modifier = 0;
	if (big_size && pos->stack_b->value < pos->stack_b->next->value)
		both_modifier = 2;
	if (pos->stack_a->value > pos->stack_a->next->value
		&& pos->stack_a->value > pos->stack_a->next->next->value)
		ft_exec_move(pos, RA + both_modifier);
	else if (pos->stack_a->next->value > pos->stack_a->value
		&& pos->stack_a->next->value > pos->stack_a->next->next->value)
		ft_exec_move(pos, RRA + both_modifier);
	if (pos->stack_a->value > pos->stack_a->next->value)
		ft_exec_move(pos, SA + both_modifier);
	if (big_size && pos->stack_b->value < pos->stack_b->next->value)
		ft_exec_move(pos, SB);
}

static void	ft_push_first(t_pos *pos)
{
	t_ll	target;

	target = ft_get_target(pos->stack_a, pos->stack_b->value);
	if (target == LLONG_MAX)
	{
		ft_exec_move(pos, PA);
		ft_exec_move(pos, RA);
	}
	else
	{
		while (pos->stack_a->value != target)
			ft_exec_move(pos, RA);
		ft_exec_move(pos, PA);
	}
}

static void	ft_push_second(t_pos *pos, int big_size)
{
	t_ll	target;

	if (big_size)
	{
		target = ft_get_target(pos->stack_a, pos->stack_b->value);
		if (target == LLONG_MAX)
		{
			ft_exec_move(pos, PA);
			ft_exec_move(pos, RA);
		}
		else
		{
			while (ft_stack_index_of(pos->stack_a, target)
				> ft_stack_size(pos->stack_a) / 2
				&& pos->stack_a->value != target)
				ft_exec_move(pos, RRA);
			while (ft_stack_index_of(pos->stack_a, target)
				<= ft_stack_size(pos->stack_a) / 2
				&& pos->stack_a->value != target)
				ft_exec_move(pos, RA);
			ft_exec_move(pos, PA);
		}
	}
}
