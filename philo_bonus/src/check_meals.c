/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:57:29 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:48:35 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_meals(void *ptr)
{
	int		i;
	t_data	*data;

	data = (t_data *) ptr;
	i = 0;
	while (i < data->time.pnb)
	{
		sem_wait(data->meals);
		i++;
	}
	ft_kill(data);
	sem_close(data->meals);
	sem_close(data->print);
	sem_close(data->forks);
	free(data->philo);
	free(data->pid);
	exit(0);
	return (NULL);
}
