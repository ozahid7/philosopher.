/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:26:19 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/04 01:55:59 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_time(t_philo *philo)
{
	struct timeval		cur;

	gettimeofday(&cur, NULL);
	if (get_time() - philo->lmeal > philo->times.die)
		return (1);
	return (0);
}

long	get_time(void)
{
	struct timeval		cur;
	long long			time;

	gettimeofday(&cur, NULL);
	time = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (time);
}

void	ft_sleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(1);
	}
}
