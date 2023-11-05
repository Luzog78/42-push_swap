/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:53:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 09:01:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pos
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_pos;


#endif
