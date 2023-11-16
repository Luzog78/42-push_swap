/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:56:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 02:53:54 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*ft_calc_path_rr(t_path_calc path_calc);
static t_moves	*ft_calc_path_rrr(t_path_calc path_calc);
static t_moves	*ft_calc_path_ra_rrb(t_path_calc path_calc);
static t_moves	*ft_calc_path_rra_rb(t_path_calc path_calc);

t_moves	*ft_calc_path(t_path_calc path_calc)
{
	t_moves	*path;
	t_moves	*tmp;
	int		len_path;
	int		i;
	t_moves	*(*ft_calc_path_func[4])(t_path_calc);

	ft_calc_path_func[0] = ft_calc_path_rr;
	ft_calc_path_func[1] = ft_calc_path_rrr;
	ft_calc_path_func[2] = ft_calc_path_ra_rrb;
	ft_calc_path_func[3] = ft_calc_path_rra_rb;
	i = 0;
	while (i < 4)
	{
		tmp = ft_calc_path_func[i](path_calc);
		if (i == 0 || (tmp != NULL && ft_moves_size(tmp) < ft_moves_size(path)))
		{
			if (i != 0)
				ft_free_moves(path);
			path = tmp;
		}
		else
			ft_free_moves(tmp);
		i++;
	}
	return (path);
}

static t_moves	*ft_calc_path_rr(t_path_calc path_calc)
{
	t_moves	*path;

	path = NULL;
	while (path_calc.curr_i > 0 && path_calc.target_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RR));
		path_calc.curr_i--;
		path_calc.target_i--;
	}
	while (path_calc.curr_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RA));
		path_calc.curr_i--;
	}
	while (path_calc.target_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RB));
		path_calc.target_i--;
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	return (path);
}

static t_moves	*ft_calc_path_rrr(t_path_calc path_calc)
{
	t_moves	*path;

	path = NULL;
	while (path_calc.curr_i % path_calc.stack_a_size != 0 && path_calc.target_i % path_calc.stack_b_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRR));
		path_calc.curr_i++;
		path_calc.target_i++;
	}
	while (path_calc.curr_i % path_calc.stack_a_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRA));
		path_calc.curr_i++;
	}
	while (path_calc.target_i % path_calc.stack_b_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRB));
		path_calc.target_i++;
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	return (path);
}

static t_moves	*ft_calc_path_ra_rrb(t_path_calc path_calc)
{
	t_moves	*path;

	path = NULL;
	while (path_calc.curr_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RA));
		path_calc.curr_i--;
	}
	while (path_calc.target_i % path_calc.stack_b_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRB));
		path_calc.target_i++;
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	return (path);
}

static t_moves	*ft_calc_path_rra_rb(t_path_calc path_calc)
{
	t_moves	*path;

	path = NULL;
	while (path_calc.curr_i % path_calc.stack_a_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRA));
		path_calc.curr_i++;
	}
	while (path_calc.target_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RB));
		path_calc.target_i--;
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	return (path);
}
