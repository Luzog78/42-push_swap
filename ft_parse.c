/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:52:18 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/20 14:46:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_has_duplicates(t_stack *stack, t_ll value);
static void	ft_add_to_stack_a(t_pos *pos, char **split, int *is_valid);
static int	ft_is_valid_arg(char *arg);
static t_ll	ft_custom_atoi(char *str);

int	ft_parse(t_pos *pos, int argc, char **argv)
{
	int		i;
	int		is_valid;

	i = 0;
	is_valid = 1;
	while (i < argc)
	{
		ft_add_to_stack_a(pos,
			ft_custom_split(argv[i], " \t\n\v\r\f"), &is_valid);
		if (!is_valid)
			break ;
		i++;
	}
	if (!is_valid)
	{
		ft_free_pos(pos);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static void	ft_add_to_stack_a(t_pos *pos, char **split, int *is_valid)
{
	int		j;
	t_ll	elem;

	j = 0;
	while (split[j])
	{
		if (!ft_is_valid_arg(split[j]))
		{
			*is_valid = 0;
			break ;
		}
		elem = ft_custom_atoi(split[j]);
		if (elem == LLONG_MIN_ALMOST || ft_has_duplicates(pos->stack_a, elem))
		{
			*is_valid = 0;
			break ;
		}
		ft_stack_add_back(&pos->stack_a, ft_create_stack(elem));
		j++;
	}
	if (!j)
		*is_valid = 0;
	ft_free_split(split);
}

static int	ft_has_duplicates(t_stack *stack, t_ll value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	ft_is_valid_arg(char *arg)
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

static t_ll	ft_custom_atoi(char *str)
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
		return (LLONG_MIN_ALMOST);
	return (res);
}
