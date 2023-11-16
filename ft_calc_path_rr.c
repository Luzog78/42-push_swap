/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_path_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:13:12 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:46:45 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_calc_path_ra_rb(t_path_calc path_calc, int *min_cost,
				t_moves **path, int *i);

t_moves	*ft_calc_path_rr(t_path_calc path_calc, int *min_cost)
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
	if (!ft_calc_path_ra_rb(path_calc, min_cost, &path, &i))
		return (NULL);
	ft_moves_add_back(&path, ft_create_moves(PB));
	if (!ft_incr_and_check_min(path, &i, min_cost))
		return (NULL);
	if (i < *min_cost)
		*min_cost = i;
	return (path);
}

static int	ft_calc_path_ra_rb(t_path_calc path_calc, int *min_cost,
				t_moves **path, int *i)
{
	while (path_calc.curr_i > 0)
	{
		ft_moves_add_back(path, ft_create_moves(RA));
		path_calc.curr_i--;
		if (!ft_incr_and_check_min(*path, i, min_cost))
			return (0);
	}
	while (path_calc.target_i > 0)
	{
		ft_moves_add_back(path, ft_create_moves(RB));
		path_calc.target_i--;
		if (!ft_incr_and_check_min(*path, i, min_cost))
			return (0);
	}
	return (1);
}
