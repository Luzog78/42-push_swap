/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzog <luzog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:53:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 12:37:40 by luzog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static unsigned long long	g_alloc = 0;

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(1);
	g_alloc += 1;
	return (ptr);
}

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		g_alloc -= 1;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*curr;

	while (stack)
	{
		curr = stack;
		stack = stack->next;
		ft_free(curr);
	}
}

void	ft_free_moves(t_moves *moves)
{
	t_moves	*curr;

	while (moves)
	{
		curr = moves;
		moves = moves->next;
		ft_free(curr);
	}
}

void	ft_free_pos(t_pos *pos)
{
	if (pos)
	{
		ft_free_stack(pos->stack_a);
		ft_free_stack(pos->stack_b);
		ft_free_moves(pos->moves);
		ft_free(pos);
	}
}

void	ft_free_data(t_data *data)
{
	ft_free_pos(data->current_floor);
	ft_free_pos(data->history);
}

void	ft_init_data(t_data *data)
{
	data->current_floor = NULL;
	data->history = NULL;
}

void	ft_add_front_pos(t_pos **pos, t_pos *new)
{
	if (!*pos)
		*pos = new;
	else
	{
		new->next = *pos;
		*pos = new;
	}
}

t_stack	*ft_create_stack(int value)
{
	t_stack	*new;

	new = ft_malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_add_front_stack(t_stack **stack, t_stack *new)
{
	if (!*stack)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_add_back_stack(t_stack **stack, t_stack *new)
{
	t_stack	*curr;

	if (!*stack)
		*stack = new;
	else
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

t_stack	*ft_pop_back_stack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!stack)
		return (NULL);
	if (!stack->next)
	{
		curr = stack;
		stack = NULL;
		return (curr);
	}
	curr = stack;
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	return (curr);
}

void	ft_add_back_move(t_moves **moves, t_moves *new)
{
	t_moves	*curr;

	if (!*moves)
		*moves = new;
	else
	{
		curr = *moves;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

int	ft_stack_equals(t_stack *stack1, t_stack *stack2)
{
	while (stack1 && stack2)
	{
		if (stack1->value != stack2->value)
			return (0);
		stack1 = stack1->next;
		stack2 = stack2->next;
	}
	if (stack1 || stack2)
		return (0);
	return (1);
}

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

t_stack	*ft_clone_stack(t_stack *stack)
{
	t_stack	*new;
	t_stack	*curr;

	new = NULL;
	if (stack)
	{
		curr = ft_malloc(sizeof(t_stack));
		curr->value = stack->value;
		curr->next = NULL;
		new = curr;
		stack = stack->next;
	}
	while (stack)
	{
		curr->next = ft_malloc(sizeof(t_stack));
		curr = curr->next;
		curr->value = stack->value;
		curr->next = NULL;
		stack = stack->next;
	}
	return (new);
}

t_moves	*ft_clone_moves(t_moves *moves)
{
	t_moves	*new;
	t_moves	*curr;
	
	new = NULL;
	if (moves)
	{
		curr = ft_malloc(sizeof(t_moves));
		curr->type = moves->type;
		curr->next = NULL;
		new = curr;
		moves = moves->next;
	}
	while (moves)
	{
		curr->next = ft_malloc(sizeof(t_moves));
		curr = curr->next;
		curr->type = moves->type;
		curr->next = NULL;
		moves = moves->next;
	}
	return (new);
}

t_pos	*ft_clone_pos(t_pos *pos)
{
	t_pos	*new;

	new = ft_malloc(sizeof(t_pos));
	new->stack_a = ft_clone_stack(pos->stack_a);
	new->stack_b = ft_clone_stack(pos->stack_b);
	new->moves = ft_clone_moves(pos->moves);
	return (new);
}

t_moves	*ft_create_move(t_move_type move)
{
	t_moves	*new;

	new = ft_malloc(sizeof(t_moves));
	new->type = move;
	new->next = NULL;
	return (new);
}

void	ft_sx(t_pos *pos, t_move_type move)
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

void	ft_px(t_pos *pos, t_move_type move)
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

void	ft_rx(t_pos *pos, t_move_type move)
{
	t_stack	*tmp;

	if (move == RA && pos->stack_a && pos->stack_a->next)
	{
		tmp = pos->stack_a;
		pos->stack_a = pos->stack_a->next;
		tmp->next = NULL;
		ft_add_back_stack(&pos->stack_a, tmp);
	}
	else if (move == RB && pos->stack_b && pos->stack_b->next)
	{
		tmp = pos->stack_b;
		pos->stack_b = pos->stack_b->next;
		tmp->next = NULL;
		ft_add_back_stack(&pos->stack_b, tmp);
	}
	else if (move == RR)
	{
		ft_rx(pos, RA);
		ft_rx(pos, RB);
	}
}

void	ft_rrx(t_pos *pos, t_move_type move)
{
	if (move == RRA && pos->stack_a && pos->stack_a->next)
	{
		ft_add_front_stack(&pos->stack_a, ft_pop_back_stack(pos->stack_a));
	}
	else if (move == RRB && pos->stack_b && pos->stack_b->next)
	{
		ft_add_front_stack(&pos->stack_b, ft_pop_back_stack(pos->stack_b));
	}
	else if (move == RRR)
	{
		ft_rrx(pos, RRA);
		ft_rrx(pos, RRB);
	}
}

t_pos	*ft_apply_move_without_history(t_pos *pos, t_move_type move)
{
	t_pos	*new;

	new = ft_malloc(sizeof(t_pos));
	new->stack_a = ft_clone_stack(pos->stack_a);
	new->stack_b = ft_clone_stack(pos->stack_b);
	new->moves = NULL;
	if (move == SA || move == SB || move == SS)
		ft_sx(new, move);
	else if (move == PA || move == PB)
		ft_px(new, move);
	else if (move == RA || move == RB || move == RR)
		ft_rx(new, move);
	else if (move == RRA || move == RRB || move == RRR)
		ft_rrx(new, move);
	return (new);
}

int	ft_pos_equals(t_pos *pos1, t_pos *pos2)
{
	return (ft_stack_equals(pos1->stack_a, pos2->stack_a)
		&& ft_stack_equals(pos1->stack_b, pos2->stack_b));
}

int	ft_check_solution(t_pos *pos)
{
	t_stack	*curr;

	if (pos->stack_b)
		return (0);
	curr = pos->stack_a;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	curr = pos->stack_b;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

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

void	ft_next_floor(t_data *data)
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
			if (!ft_pos_equals(new, curr))
			{
				new->moves = ft_clone_moves(curr->moves);
				ft_add_back_move(&new->moves, ft_create_move(move));
				if (ft_pos_exists(data->history, new))
					continue ;
				ft_add_front_pos(&next_floor, ft_clone_pos(new));
				if (ft_check_solution(new))
					return ;
				ft_add_front_pos(&data->history, ft_clone_pos(new));
			}
			ft_free_pos(new);
			move = ft_get_next_move_type(move);
		}
		curr = curr->next;
	}
	ft_free_pos(data->current_floor);
	data->current_floor = next_floor;
	ft_next_floor(data);
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
}

int	main(int argc, char **argv)
{
	t_data	data;

	/*if (argc < 2)
		return (0);*/
	ft_init_data(&data);

	data.current_floor = ft_malloc(sizeof(t_pos));
	data.current_floor->stack_a = NULL;
	data.current_floor->stack_b = NULL;
	data.current_floor->moves = NULL;
	ft_add_back_stack(&data.current_floor->stack_a, ft_create_stack(5));
	ft_add_back_stack(&data.current_floor->stack_a, ft_create_stack(4));
	ft_add_back_stack(&data.current_floor->stack_a, ft_create_stack(3));
	ft_add_back_stack(&data.current_floor->stack_a, ft_create_stack(2));
	ft_add_back_stack(&data.current_floor->stack_a, ft_create_stack(1));
	ft_add_back_stack(&data.current_floor->stack_a, ft_create_stack(0));

	ft_next_floor(&data);
	ft_print_solution(data.current_floor);
	ft_free_data(&data);
	return (0);
}
