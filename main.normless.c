/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.normless.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:27 by luzog             #+#    #+#             */
/*   Updated: 2023/11/16 04:58:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

unsigned long long	g_alloc = 0;
unsigned long long	g_talloc = 0;

void *ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(1);
	g_alloc += 1;
	g_talloc += 1;
	return (ptr);
}

void ft_free(void *ptr)
{
	free(ptr);
	g_alloc -= 1;
}

/*
t_move_type	ft_get_next_move_type(t_move_type move)
{
	if (move == SA)
		return (SB);
	if (move == SB)
		return (SS);
	if (move == SS)
		return (PA);
	if (move == PA)
		return (PB);
	if (move == PB)
		return (RA);
	if (move == RA)
		return (RB);
	if (move == RB)
		return (RR);
	if (move == RR)
		return (RRA);
	if (move == RRA)
		return (RRB);
	if (move == RRB)
		return (RRR);
	if (move == RRR)
		return (NONE);
	return (SA);
}

int	ft_next_floor(t_data *data)
{
	t_pos		*next_floor;
	t_pos		*curr;
	t_pos		*new;
	t_move_type	move;

	next_floor = NULL;
	curr = data->current_floor;
	while (curr)
	{
		move = SA;
		while (move != NONE)
		{
			new = ft_apply_move_without_history(curr, move);
			if (!ft_pos_equals(new, curr)
				&& !ft_pos_exists(data->history, new))
			{
				new->moves = ft_clone_moves(curr->moves);
				ft_add_back_move(&new->moves, ft_create_move(move));
				ft_add_front_pos(&data->history, ft_clone_pos(new));
				if (ft_check_solution(new))
				{
					ft_free_pos(&new);
					ft_free_pos(&next_floor);
					return (1);
				}
				ft_add_front_pos(&next_floor, ft_clone_pos(new));
			}
			ft_free_pos(&new);
			move = ft_get_next_move_type(move);
		}
		curr = curr->next;
	}
	ft_free_pos(&data->current_floor);
	data->current_floor = next_floor;
	return (0);
}
*/

void	ft_print_solution(t_pos *pos)
{
	int	i;
	t_moves	*curr;

	i = 0;
	curr = pos->moves;
	while (curr)
	{
		if (curr->type == SA)
			printf("sa\n");
		else if (curr->type == SB)
			printf("sb\n");
		else if (curr->type == SS)
			printf("ss\n");
		else if (curr->type == PA)
			printf("pa\n");
		else if (curr->type == PB)
			printf("pb\n");
		else if (curr->type == RA)
			printf("ra\n");
		else if (curr->type == RB)
			printf("rb\n");
		else if (curr->type == RR)
			printf("rr\n");
		else if (curr->type == RRA)
			printf("rra\n");
		else if (curr->type == RRB)
			printf("rrb\n");
		else if (curr->type == RRR)
			printf("rrr\n");
		curr = curr->next;
		i++;
	}
	printf("Number of moves: %d\n", i);
	t_stack *tmp = pos->stack_b;
	for (; tmp; tmp = tmp->next)
		printf("%d ", tmp->value);
	printf("\n");
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
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	t_pos *pos = ft_create_pos();
	for (i = 0; i < n; i++)
		ft_stack_add_back(&pos->stack_a, ft_create_stack(array[i]));
	return (pos);
}

int	main(int argc, char **argv)
{
	t_pos	*pos;
	int		result;

	pos = shuffle(128, 400);
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
	ft_print_solution(pos);
	ft_free_pos(pos);
	return (0);
}
