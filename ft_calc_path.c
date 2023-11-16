/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:56:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:17:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*ft_calc_path(t_path_calc path_calc, t_stack *curr)
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
	min_cost = INT_MAX;
	i = -1;
	while (++i < 4)
	{
		tmp = ft_calc_path_func[i](path_calc, &min_cost);
		if (i == 0 || tmp)
		{
			if (i != 0 && path)
				ft_free_moves(path);
			path = tmp;
		}
	}
	curr->path = path;
	curr->cost = min_cost;
	return (path);
}

int	ft_incr_and_check_min(t_moves *path, int *i, int *min_cost)
{
	(*i)++;
	if (*i >= *min_cost)
	{
		ft_free_moves(path);
		return (0);
	}
	return (1);
}
