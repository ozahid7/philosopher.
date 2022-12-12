/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:26:49 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/12 05:06:29 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_data *data, t_philo *philo, int id)
{
	int	i;

	i = 0;
	while (i < data->time.pnb)
	{
		if (id != 0)
			id = fork ();
		if (id == 0)
		{
			philo = &data->philo[i];
			philo->id = i + 1;
			philo->times = data->time;
			philo->dead = data->dead;
			philo->forks = data->forks;
			philo->print = data->print;
			philo->meals = data->meals;
			pthread_create(&philo->thread, NULL, &check_death, philo);
			philo_do(philo);
			break ;
		}
		else
			data->pid[i] = id;
		i++;
	}
}

int	create_process(t_data *data)
{
	int		i;
	int		id;
	t_philo	*philo;

	philo = NULL;
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->time.pnb);
	if (!data->philo)
		return (0);
	data->pid = malloc(sizeof(int) * data->time.pnb);
	if (!data->pid)
		return (0);
	init_sema(data);
	id = 2;
	init_data(data, philo, id);
	return (0);
}
