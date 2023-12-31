/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:10:27 by luzog             #+#    #+#             */
/*   Updated: 2023/11/21 05:33:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_type	ft_read(t_pos *pos);

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
	result = ft_read(pos);
	if (!result)
		write(1, "Error\n", 6);
	else if (ft_check_solution(pos))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_pos(pos);
	return (0);
}
