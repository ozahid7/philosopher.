/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_function_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:40:46 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/08 19:54:15 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_parce(t_data *ptr, int ac, char **av)
{
	int		i;
	int		e;

	i = 1;
	if (check_empty(av))
		return (1);
	if (ac <= 6 && ac >= 5)
	{
		ptr->time.pnb = ft_atoi(av[1], &e);
		if (ptr->time.pnb == 0)
			return (1);
		ptr->time.die = ft_atoi(av[2], &e);
		ptr->time.eat = ft_atoi(av[3], &e);
		ptr->time.sleep = ft_atoi(av[4], &e);
		if (e == 1)
			return (1);
		if (ac == 5)
			ptr->time.meals = -1;
		else
			ptr->time.meals = ft_atoi(av[5], &e);
	}
	else
		return (1);
	return (0);
}

int	check_args_int(char ch, int *sig)
{
	if ((ch > 47 && ch < 58))
		return (0);
	else if ((ch == '+') && *sig == 0)
	{
		*sig = 1;
		return (0);
	}
	return (1);
}

int	check_empty(char **av)
{
	int		i;
	int		j;
	int		s;
	int		sig;

	i = 0;
	while (av[++i])
	{
		s = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				sig = 0;
				s++;
			}
			else if (check_args_int(av[i][j], &sig))
				return (1);
			j++;
		}
		if (s == ft_strlen(av[i]))
			return (1);
	}
	return (0);
}
