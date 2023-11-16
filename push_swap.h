/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:53:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 07:46:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LLONG_MAX 9223372036854775807LL
# define LLONG_MIN_ALMOST -9223372036854775807LL

typedef long long	t_ll;

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

/**
 * @brief	Stack element
 * 
 * @param	value		Value of the element
 * @param	target		Value of the target element,
 * 							used to calculate the cost of the move,
 * 							max element is pointed if the element has no target
 * @param	path		Moves required to get the element to its target,
 * 							just above the target element,
 * 							NULL if the element has no target
 * @param	cost		Length of the path,
 * 							INT_MAX if the element has no target
 * @param	next		Next element in the stack,
 * 							NULL if the element is the last
*/
typedef struct s_stack
{
	t_ll			value;
	t_ll			target;
	t_moves			*path;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pos
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_moves			*moves;
	struct s_pos	*next;
}	t_pos;

typedef struct s_path_calc
{
	int		curr_i;
	int		stack_a_size;
	int		target_i;
	int		stack_b_size;
}	t_path_calc;

/* ************** */
/* ***  Move  *** */
/* ************** */

t_moves		*ft_create_moves(t_move_type type);
int			ft_moves_size(t_moves *moves);
void		ft_moves_add_front(t_moves **moves, t_moves *new);
void		ft_moves_add_back(t_moves **moves, t_moves *new);
t_moves		*ft_moves_get_last(t_moves *moves);
void		ft_free_moves(t_moves *moves);

/* *************** */
/* ***  Stack  *** */
/* *************** */

t_stack		*ft_create_stack(t_ll value);
int			ft_stack_size(t_stack *stack);
void		ft_stack_add_front(t_stack **stack, t_stack *new);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack		*ft_stack_pop_back(t_stack *stack);
int			ft_stack_index_of(t_stack *stack, t_ll value);
t_ll		ft_stack_max(t_stack *stack);
t_stack		*ft_stack_get_last(t_stack *stack);
void		ft_free_stack(t_stack *stack);

/* ************* */
/* ***  Pos  *** */
/* ************* */

t_pos		*ft_create_pos(void);
void		ft_free_pos(t_pos *pos);

/* ******************* */
/* ***  Calc Path  *** */
/* ******************* */

t_moves		*ft_calc_path(t_path_calc path_calc, t_stack *curr);
int			ft_incr_and_check_min(t_moves *path, int *i, int *min_cost);
t_moves		*ft_calc_path_rr(t_path_calc path_calc, int *min_cost);
t_moves		*ft_calc_path_rrr(t_path_calc path_calc, int *min_cost);
t_moves		*ft_calc_path_ra_rrb(t_path_calc path_calc, int *min_cost);
t_moves		*ft_calc_path_rra_rb(t_path_calc path_calc, int *min_cost);

/* ***************** */
/* ***  Parsing  *** */
/* ***************** */

int			ft_parse(t_pos *pos, int argc, char **argv);

/* ************** */
/* ***  Main  *** */
/* ************** */

void		ft_exec_move(t_pos *pos, t_move_type move);
void		ft_update_targets(t_pos *pos);
void		ft_update_paths(t_pos *pos);
void		ft_exec_move_cheapest(t_pos *pos);
void		ft_complete_stack_a_moves(t_pos *pos);
void		ft_print_solution(t_pos *pos);

char		**ft_split(char *str, char *charset);
void		ft_free_split(char **split);
void		ft_putstr(char *str);

#endif
