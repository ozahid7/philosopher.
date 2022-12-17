/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:34:58 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 10:58:20 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_detach(t_data *data, int i)
{
	while (i < data->time.pnb)
	{
		if (pthread_detach(data->philo[i].thread))
			return (1);
		i++;
	}
	return (0);
}

int	data_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->time.pnb);
	if (data->philo == NULL)
		return (1);
	init_mutex(data);
	while (i < data->time.pnb)
	{
		philo = &data->philo[i];
		philo->id = i + 1;
		philo->times = data->time;
		philo->data = data;
		philo->lmeal = get_time();
		if (pthread_create(&data->philo[i].thread, NULL, &philo_do, philo))
			return (1);
		i++;
	}
	check_death(data);
	i = 0;
	ft_detach(data, i);
	return (0);
}
