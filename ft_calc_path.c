/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:56:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 03:51:51 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*ft_calc_path_rr(t_path_calc path_calc, int *min_cost);
static t_moves	*ft_calc_path_rrr(t_path_calc path_calc, int *min_cost);
static t_moves	*ft_calc_path_ra_rrb(t_path_calc path_calc, int *min_cost);
static t_moves	*ft_calc_path_rra_rb(t_path_calc path_calc, int *min_cost);

t_moves	*ft_calc_path(t_path_calc path_calc, t_stack* curr)
{
	t_moves	*path;
	t_moves	*tmp;
	int		i;
	int		min_cost;
	t_moves	*(*ft_calc_path_func[4])(t_path_calc, int *);

	ft_calc_path_func[0] = ft_calc_path_rr;
	ft_calc_path_func[1] = ft_calc_path_rrr;
	ft_calc_path_func[2] = ft_calc_path_ra_rrb;
	ft_calc_path_func[3] = ft_calc_path_rra_rb;
	i = 0;
	min_cost = INT_MAX;
	while (i < 4)
	{
		tmp = ft_calc_path_func[i](path_calc, &min_cost);
		if (i == 0 || tmp)
		{
			if (i != 0 && path)
				ft_free_moves(path);
			path = tmp;
		}
		i++;
	}
	curr->path = path;
	curr->cost = min_cost;
	return (path);
}

static int	ft_incr_and_check_min(t_moves *path, int *i, int *min_cost)
{
	(*i)++;
	if (*i >= *min_cost)
	{
		ft_free_moves(path);
		return (0);
	}
	return (1);
}

static t_moves	*ft_calc_path_rr(t_path_calc path_calc, int *min_cost)
{
	t_moves	*path;
	int		i;

	path = NULL;
	i = 0;
	while (path_calc.curr_i > 0 && path_calc.target_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RR));
		path_calc.curr_i--;
		path_calc.target_i--;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	while (path_calc.curr_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RA));
		path_calc.curr_i--;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	while (path_calc.target_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RB));
		path_calc.target_i--;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	if (i < *min_cost)
		*min_cost = i;
	return (path);
}

static t_moves	*ft_calc_path_rrr(t_path_calc path_calc, int *min_cost)
{
	t_moves	*path;
	int		i;

	path = NULL;
	i = 0;
	while (path_calc.curr_i % path_calc.stack_a_size != 0
		&& path_calc.target_i % path_calc.stack_b_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRR));
		path_calc.curr_i++;
		path_calc.target_i++;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	while (path_calc.curr_i % path_calc.stack_a_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRA));
		path_calc.curr_i++;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	while (path_calc.target_i % path_calc.stack_b_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRB));
		path_calc.target_i++;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	if (!ft_incr_and_check_min(path, &i, min_cost))
		return (NULL);
	if (i < *min_cost)
		*min_cost = i;
	return (path);
}

static t_moves	*ft_calc_path_ra_rrb(t_path_calc path_calc, int *min_cost)
{
	t_moves	*path;
	int		i;

	path = NULL;
	i = 0;
	while (path_calc.curr_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RA));
		path_calc.curr_i--;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	while (path_calc.target_i % path_calc.stack_b_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRB));
		path_calc.target_i++;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	if (!ft_incr_and_check_min(path, &i, min_cost))
		return (NULL);
	if (i < *min_cost)
		*min_cost = i;
	return (path);
}

static t_moves	*ft_calc_path_rra_rb(t_path_calc path_calc, int *min_cost)
{
	t_moves	*path;
	int		i;

	path = NULL;
	i = 0;
	while (path_calc.curr_i % path_calc.stack_a_size != 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RRA));
		path_calc.curr_i++;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	while (path_calc.target_i > 0)
	{
		ft_moves_add_back(&path, ft_create_moves(RB));
		path_calc.target_i--;
		if (!ft_incr_and_check_min(path, &i, min_cost))
			return (NULL);
	}
	ft_moves_add_back(&path, ft_create_moves(PB));
	if (!ft_incr_and_check_min(path, &i, min_cost))
		return (NULL);
	if (i < *min_cost)
		*min_cost = i;
	return (path);
}
