/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:23:52 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 08:13:49 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_do(void *str)
{
	t_philo		*philo;

	philo = (t_philo *) str;
	philo->lmeal = get_time() - philo->data->start;
	if (is_double(philo->id))
		ft_sleep (100);
	while (1)
	{
		pthread_mutex_lock(&philo->myfork);
		print_it("has taken a fork", philo, get_time() - philo->data->start);
		pthread_mutex_lock(philo->next_fork);
		print_it("has taken a fork", philo, get_time() - philo->data->start);
		print_it("eating", philo, get_time() - philo->data->start);
		philo->lmeal = get_time() - philo->data->start;
		ft_sleep(philo->times.eat);
		if (philo->times.meals > 0)
			philo->times.meals--;
		pthread_mutex_unlock(&philo->myfork);
		pthread_mutex_unlock(philo->next_fork);
		print_it("sleeping", philo, get_time() - philo->data->start);
		ft_sleep(philo->times.sleep);
		print_it("thinking", philo, get_time() - philo->data->start);
	}
	return (0);
}
