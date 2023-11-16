/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:52:18 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/16 07:14:35 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_has_duplicates(t_stack *stack, t_ll value);
int		ft_is_valid_arg(char *arg);
t_ll	ft_custom_atoi(char *str);
void	ft_free_split(char **split);

int	ft_parse(t_pos *pos, int argc, char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	int		is_valid;
	t_ll	elem;

	i = 0;
	is_valid = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], " \t\n\v\r\f");
		j = 0;
		while (tmp[j])
		{
			if (!ft_is_valid_arg(tmp[j]))
			{
				is_valid = 0;
				break ;
			}
			elem = ft_custom_atoi(tmp[j]);
			if (elem == LLONG_MIN || ft_has_duplicates(pos->stack_a, elem))
			{
				is_valid = 0;
				break ;
			}
			ft_stack_add_back(&pos->stack_a, ft_create_stack(elem));
			j++;
		}
		ft_free_split(tmp);
		if (!is_valid)
			break ;
		i++;
	}
	if (!is_valid)
	{
		ft_free_stack(pos->stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
}

int	ft_has_duplicates(t_stack *stack, t_ll value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_is_valid_arg(char *arg)
{
	int	i;
	
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i] && i <= 11)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	if (arg[i])
		return (0);
	return (1);
}

t_ll	ft_custom_atoi(char *str)
{
	t_ll	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str)
	{
		res = res * 10 + *str - '0';
		str++;
	}
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
		return (LLONG_MIN);
	return (res);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
