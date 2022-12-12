/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:53:07 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/12 04:53:38 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_do(t_philo *philo)
{
	philo->start = get_time();
	philo->lmeal = get_time();
	if (philo->id % 2 == 0)
		usleep(philo->times.eat * 1000);
	while (1)
	{
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		print_it("is eating\n", philo);
		philo->lmeal = get_time();
		usleep(philo->times.eat * 1000);
		sem_post(philo->forks);
		sem_post(philo->forks);
		print_it("is sleeping\n", philo);
		usleep(philo->times.sleep * 1000);
		print_it("is thinking\n", philo);
		if (philo->times.meals >= 0)
			philo->times.meals--;
		if (philo->times.meals == 0)
			sem_post(philo->meals);
	}
}
