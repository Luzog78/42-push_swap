/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:53:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 16:41:08 by ysabik           ###   ########.fr       */
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
	RRR
}	t_move_type;

typedef struct s_move
{
	t_move_type		type;
	struct s_move	*next;
}	t_move;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pos
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_move			*moves;
	struct s_pos	*next;
}	t_pos;

typedef struct s_data
{
	t_pos	*current_floor;
	t_pos	*history;
}	t_data;

#endif
