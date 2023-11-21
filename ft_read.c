/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:54:42 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/21 05:42:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_search(t_pos *pos, char *mov, int *i);
static t_move_type	ft_get_mov(char *mov, int *i);

int	ft_read(t_pos *pos)
{
	char	c;
	int		ret;
	char	mov[5];
	int		i;

	i = 0;
	while (i < 4)
	{
		ret = read(0, &c, 1);
		if (ret <= 0)
			break ;
		if (c == '\n')
		{
			if (i == 0)
				i = -1;
			else if (ft_search(pos, mov, &i))
				continue ;
			break ;
		}
		mov[i] = c;
		mov[i + 1] = 0;
		i++;
	}
	return (!i);
}

static int	ft_search(t_pos *pos, char *mov, int *i)
{
	t_move_type	m;

	m = ft_get_mov(mov, i);
	if (m == NONE)
		return (0);
	ft_exec_move(pos, m);
	*i = 0;
	return (1);
}

static t_move_type	ft_get_mov(char *mov, int *i)
{
	if (*i == 3 && mov[0] == 'r' && mov[1] == 'r' && mov[2] == 'r')
		return (RRR);
	else if (*i == 3 && mov[0] == 'r' && mov[1] == 'r' && mov[2] == 'a')
		return (RRA);
	else if (*i == 3 && mov[0] == 'r' && mov[1] == 'r' && mov[2] == 'b')
		return (RRB);
	else if (*i == 2 && mov[0] == 'r' && mov[1] == 'r')
		return (RR);
	else if (*i == 2 && mov[0] == 'r' && mov[1] == 'a')
		return (RA);
	else if (*i == 2 && mov[0] == 'r' && mov[1] == 'b')
		return (RB);
	else if (*i == 2 && mov[0] == 's' && mov[1] == 's')
		return (SS);
	else if (*i == 2 && mov[0] == 's' && mov[1] == 'a')
		return (SA);
	else if (*i == 2 && mov[0] == 's' && mov[1] == 'b')
		return (SB);
	else if (*i == 2 && mov[0] == 'p' && mov[1] == 'a')
		return (PA);
	else if (*i == 2 && mov[0] == 'p' && mov[1] == 'b')
		return (PB);
	return (NONE);
}
