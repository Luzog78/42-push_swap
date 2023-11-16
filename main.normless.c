/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.normless.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:27 by luzog             #+#    #+#             */
/*   Updated: 2023/11/16 06:55:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

void	ft_print_solution(t_pos *pos)
{
	int	i;
	t_moves	*curr;

	i = 0;
	curr = pos->moves;
	while (curr)
	{
		if (curr->type == SA)
			ft_putstr("sa\n");
		else if (curr->type == SB)
			ft_putstr("sb\n");
		else if (curr->type == SS)
			ft_putstr("ss\n");
		else if (curr->type == PA)
			ft_putstr("pa\n");
		else if (curr->type == PB)
			ft_putstr("pb\n");
		else if (curr->type == RA)
			ft_putstr("ra\n");
		else if (curr->type == RB)
			ft_putstr("rb\n");
		else if (curr->type == RR)
			ft_putstr("rr\n");
		else if (curr->type == RRA)
			ft_putstr("rra\n");
		else if (curr->type == RRB)
			ft_putstr("rrb\n");
		else if (curr->type == RRR)
			ft_putstr("rrr\n");
		curr = curr->next;
		i++;
	}
}

t_pos *shuffle(size_t n, unsigned int seed)
{
	size_t i;
	int array[n];
	for (i = 0; i < n; i++)
		array[i] = i + 1;
	if (n > 1)
	{
		srand(seed);
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
	/*for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");*/
	t_pos *pos = ft_create_pos();
	for (i = 0; i < n; i++)
		ft_stack_add_back(&pos->stack_a, ft_create_stack(array[i]));
	return (pos);
}

void	ft_custom_times_algo(t_pos *pos)
{
	ft_exec_move(pos, PB);
	ft_exec_move(pos, PB);
	if (pos->stack_b->value < pos->stack_b->next->value)
		ft_exec_move(pos, SB);
	while (pos->stack_a)
	{
		ft_update_targets(pos);
		ft_update_paths(pos);
		ft_exec_move_cheapest(pos);
	}
	ft_complete_stack_a_moves(pos);
}

void	ft_tiny_sort_algo(t_pos *pos)
{
	if (ft_stack_size(pos->stack_a) == 2)
	{
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
	}
	else if (ft_stack_size(pos->stack_a) == 3)
	{
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
		if (pos->stack_a->value > pos->stack_a->next->next->value)
			ft_exec_move(pos, RRA);
		else if (pos->stack_a->next->value > pos->stack_a->next->next->value)
			ft_exec_move(pos, RA);
		if (pos->stack_a->value > pos->stack_a->next->value)
			ft_exec_move(pos, SA);
	}
}

int	main(int argc, char **argv)
{
	t_pos	*pos;
	int		result;

	argc--;
	argv++;
	if (!argc)
		return (0);
	pos = ft_create_pos();
	if (!ft_parse(pos, argc, argv))
		return (0);
	if (ft_stack_size(pos->stack_a) <= 3)
		ft_tiny_sort_algo(pos);
	else
		ft_custom_times_algo(pos);
	ft_print_solution(pos);
	ft_free_pos(pos);
	return (0);
}
