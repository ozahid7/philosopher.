/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:53:07 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:40:39 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_do(t_philo *philo)
{
	philo->lmeal = get_time();
	if (philo->id % 2 == 0)
		ft_sleep(philo->times.eat);
	while (1)
	{
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		print_it("eating\n", philo);
		philo->lmeal = get_time();
		ft_sleep(philo->times.eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		print_it("sleeping\n", philo);
		ft_sleep(philo->times.sleep);
		print_it("thinking\n", philo);
		if (philo->times.meals >= 0)
			philo->times.meals--;
		if (philo->times.meals == 0)
			sem_post(philo->meals);
	}
}
