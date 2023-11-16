/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:54:42 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 09:01:30 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move_type	ft_read_s(void);
static t_move_type	ft_read_p(void);
static t_move_type	ft_read_r(void);
static t_move_type	ft_read_rr(void);

t_move_type	ft_read(void)
{
	int			ret;
	char		c;

	ret = read(0, &c, 1);
	if (ret == 1)
	{
		if (c == 's')
			return (ft_read_s());
		else if (c == 'p')
			return (ft_read_p());
		else if (c == 'r')
			return (ft_read_r());
	}
	return (NONE);
}

static t_move_type	ft_read_s(void)
{
	int			ret;
	char		c;
	t_move_type	type;

	type = NONE;
	ret = read(0, &c, 1);
	if (ret == 1)
	{
		if (c == 'a')
			type = SA;
		else if (c == 'b')
			type = SB;
		else if (c == 's')
			type = SS;
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			return (type);
	}
	return (NONE);
}

static t_move_type	ft_read_p(void)
{
	int			ret;
	char		c;
	t_move_type	type;

	type = NONE;
	ret = read(0, &c, 1);
	if (ret == 1)
	{
		if (c == 'a')
			type = PA;
		else if (c == 'b')
			type = PB;
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			return (type);
	}
	return (NONE);
}

static t_move_type	ft_read_r(void)
{
	int			ret;
	char		c;
	t_move_type	type;

	type = NONE;
	ret = read(0, &c, 1);
	if (ret == 1)
	{
		if (c == 'a')
			type = RA;
		else if (c == 'b')
			type = RB;
		else if (c == 'r')
			return (ft_read_rr());
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			return (type);
	}
	return (NONE);
}

static t_move_type	ft_read_rr(void)
{
	int			ret;
	char		c;
	t_move_type	type;

	type = NONE;
	ret = read(0, &c, 1);
	if (ret <= 0 || c == '\n')
		return (RR);
	if (ret == 1)
	{
		if (c == 'a')
			type = RRA;
		else if (c == 'b')
			type = RRB;
		else if (c == 'r')
			type = RRR;
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			return (type);
	}
	return (NONE);
}
