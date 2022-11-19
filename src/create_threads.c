/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:34:58 by ozahid-           #+#    #+#             */
/*   Updated: 2022/11/18 03:35:27 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_data *ptr)
{
	int		i;
	t_philo	*philo;

	i = 0;
	ptr->philo = (t_philo *) malloc(sizeof(t_philo) * ptr->time.pnb);
	if (ptr->philo == NULL)
		return (1);
	init_mutex(ptr->philo, ptr->time.pnb);
	while (i < ptr->time.pnb)
	{
		philo = &ptr->philo[i];
		philo->id = i + 1;
		philo->times = ptr->time;
		if (pthread_create(&ptr->philo[i].thread, NULL, &philo_do, philo))
			return (ft_error(), 1);
		i++;
	}
	i = 0;
	while (i < ptr->time.pnb)
	{
		if (pthread_detach(ptr->philo[i].thread))
			return (ft_error(), 1);
		i++;
	}
	return (0);
}
