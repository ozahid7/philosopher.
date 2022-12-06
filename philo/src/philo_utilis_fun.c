/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilis_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:39:02 by ozahid-           #+#    #+#             */
/*   Updated: 2022/11/19 23:38:55 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_atoi(char *str, int *e)
{
	long long int	i;
	int				s;
	long long int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if ((r > 2147483647 && s == 1))
			*e = 1;
		i++;
	}
	return (r * s);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

int	is_double(int id)
{
	if (id % 2 == 0)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
