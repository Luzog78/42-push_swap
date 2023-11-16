/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_path_ra_rrb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:13:07 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 05:16:01 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*ft_calc_path_ra_rrb(t_path_calc path_calc, int *min_cost)
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
