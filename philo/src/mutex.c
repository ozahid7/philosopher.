/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:30:10 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 04:47:33 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_it(char *str, t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld  %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

int	init_mutex(t_data *data)
{
	int	i;
	t_philo	*philo;

	philo = data->philo;
	i = 0;
	pthread_mutex_init(&data->print, NULL);
	while (i < data->time.pnb)
	{
		pthread_mutex_init(&philo[i].myfork, NULL);
		philo[i].next_fork = &philo[(i + 1) % data->time.pnb].myfork;
		i++;
	}
	return (0);
}
