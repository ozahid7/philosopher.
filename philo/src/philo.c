/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/11/27 01:07:37 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_do(void *str)
{
	t_philo		*philo;

	philo = (t_philo *) str;
	philo->start = get_time();
	philo->lmeal = get_time();
	if (is_double(philo->id))
		ft_sleep (philo->times.eat);
	while (1)
	{
		pthread_mutex_lock(&philo->myfork);
		print_it("has taken a fork", philo);
		pthread_mutex_lock(philo->next_fork);
		print_it("has taken a fork", philo);
		print_it("is eating", philo);
		philo->lmeal = get_time();
		ft_sleep(philo->times.eat);
		if (philo->times.meals > 0)
			philo->times.meals--;
		pthread_mutex_unlock(&philo->myfork);
		pthread_mutex_unlock(philo->next_fork);
		print_it("is sleeping", philo);
		ft_sleep(philo->times.sleep);
		print_it("is thinking", philo);
	}
	return (0);
}

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
			if (check_time(&data->philo[i]))
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (data_init(&data))
		return (ft_error(), 1);
	check_death(&data);
	pthread_mutex_destroy(&data.philo->myfork);
	pthread_mutex_destroy(data.philo->next_fork);
	pthread_mutex_destroy(&data.philo->print);
	free (data.philo);
	return (0);
}
