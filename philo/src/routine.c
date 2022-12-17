/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:23:52 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:04:21 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_do(void *str)
{
	t_philo		*philo;

	philo = (t_philo *) str;
	if (is_double(philo->id))
		ft_sleep (100);
	while (philo->data->run != 1)
	{
		pthread_mutex_lock(&philo->myfork);
		print_it("has taken a fork", philo);
		pthread_mutex_lock(philo->next_fork);
		print_it("has taken a fork", philo);
		print_it("eating", philo);
		philo->lmeal = get_time();
		ft_sleep(philo->times.eat);
		if (philo->times.meals > 0)
			philo->times.meals--;
		pthread_mutex_unlock(&philo->myfork);
		pthread_mutex_unlock(philo->next_fork);
		print_it("sleeping", philo);
		ft_sleep(philo->times.sleep);
		print_it("thinking", philo);
	}
	return (0);
}
