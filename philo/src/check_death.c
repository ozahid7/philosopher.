/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:26:48 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/12 05:29:35 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int	i;
	int	meals;

	while (1)
	{
		i = 0;
		meals = 0;
		while (i < data->time.pnb)
		{
			if (data->philo[i].times.meals == 0)
				meals++;
			if (get_time() - data->philo->lmeal > data->time.die)
			{
				print_it("is died", data->philo);
				return (1);
			}
			if (meals == data->time.pnb)
				return (0);
			i++;
		}
	}
	return (0);
}
