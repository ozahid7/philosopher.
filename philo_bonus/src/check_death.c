/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:59:10 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:40:58 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *data)
{
	int		i;
	int		meals;
	t_philo	*philo;

	philo = (t_philo *) data;
	while (1)
	{
		i = 0;
		meals = 0;
		while (i < philo->times.pnb)
		{
			if (get_time() - philo->lmeal > philo->times.die)
			{
				sem_wait(philo->print);
				printf("%ld %d died\n", get_time()
					- philo->data->start, philo->id);
				exit(1);
			}
			i++;
		}
	}
}
