/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:26:48 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:12:48 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int	i;
	int	meals;

	data->run = 0;
	while (1)
	{
		i = -1;
		meals = 0;
		while (++i < data->time.pnb)
		{
			if (data->philo[i].times.meals == 0)
				meals++;
			if (get_time() - data->philo->lmeal > data->time.die)
			{
				data->run = 1;
				pthread_mutex_lock(&data->print);
				usleep(2000);
				return (printf("%ld  %d died\n", get_time()
						- data->start, data->philo->id), 1);
			}
			if (meals == data->time.pnb)
				return (pthread_mutex_lock(&data->print), 1);
		}
	}
	return (0);
}
