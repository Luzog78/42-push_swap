/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:41:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 08:54:05 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print(t_move_type type);
static void	ft_putstr(char *str);

void	ft_print_solution(t_pos *pos)
{
	int		i;
	t_moves	*curr;

	i = 0;
	curr = pos->moves;
	while (curr)
	{
		ft_print(curr->type);
		curr = curr->next;
		i++;
	}
}

static void	ft_print(t_move_type type)
{
	if (type == SA)
		ft_putstr("sa\n");
	else if (type == SB)
		ft_putstr("sb\n");
	else if (type == SS)
		ft_putstr("ss\n");
	else if (type == PA)
		ft_putstr("pa\n");
	else if (type == PB)
		ft_putstr("pb\n");
	else if (type == RA)
		ft_putstr("ra\n");
	else if (type == RB)
		ft_putstr("rb\n");
	else if (type == RR)
		ft_putstr("rr\n");
	else if (type == RRA)
		ft_putstr("rra\n");
	else if (type == RRB)
		ft_putstr("rrb\n");
	else if (type == RRR)
		ft_putstr("rrr\n");
}

static void	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}
