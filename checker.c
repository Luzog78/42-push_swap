/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:27 by luzog             #+#    #+#             */
/*   Updated: 2023/11/16 08:59:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_type	ft_read(void);

void	ft_check_solution(t_pos *pos)
{
	int	is_valid;

	is_valid = !pos->stack_b;
	while (pos->stack_a && pos->stack_a->next)
	{
		if (pos->stack_a->value > pos->stack_a->next->value)
		{
			is_valid = 0;
			break ;
		}
		pos->stack_a = pos->stack_a->next;
	}
	if (is_valid)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_pos		*pos;
	t_move_type	type;

	argc--;
	argv++;
	if (!argc)
		return (0);
	pos = ft_create_pos();
	if (!ft_parse(pos, argc, argv))
		return (0);
	type = ft_read();
	while (type != NONE)
	{
		ft_exec_move(pos, type);
		type = ft_read();
	}
	ft_check_solution(pos);
	ft_free_pos(pos);
	return (0);
}