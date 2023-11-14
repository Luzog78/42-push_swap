/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzog <luzog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:53:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/14 11:32:34 by luzog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef enum e_move_type
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NONE
}	t_move_type;

typedef struct s_moves
{
	t_move_type		type;
	struct s_moves	*next;
}	t_moves;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pos
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_moves			*moves;
	struct s_pos	*next;
}	t_pos;

typedef struct s_data
{
	t_pos	*current_floor;
	t_pos	*history;
}	t_data;

#endif
