/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:53:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 16:53:54 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_pos_equals(t_pos *pos1, t_pos *pos2)
{
	return (ft_stack_equals(pos1->stack_a, pos2->stack_a)
		&& ft_stack_equals(pos1->stack_b, pos2->stack_b));
}

void	ft_add_to_next_floor(t_data *data, t_pos *from)
{
	t_pos	*tmp;

	if ()
}

void	ft_next_floor(t_data *data)
{
	t_pos	*next_floor;
	
	
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	ft_init_data(&data);
	
	return (0);
}
