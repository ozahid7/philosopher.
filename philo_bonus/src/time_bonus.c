/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:26:19 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/08 00:55:22 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		usleep(50);
	}
}
