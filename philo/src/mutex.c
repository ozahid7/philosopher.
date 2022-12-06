/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:30:10 by ozahid-           #+#    #+#             */
/*   Updated: 2022/11/22 05:09:52 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_it(char *str, t_philo *ptr)
{
	pthread_mutex_lock(&ptr->print);
	printf("%ld  %d %s\n", get_time() - ptr->start, ptr->id, str);
	pthread_mutex_unlock(&ptr->print);
}

int	init_mutex(t_philo *ptr, int pnb)
{
	int	i;

	i = 0;
	pthread_mutex_init(&ptr->print, NULL);
	while (i < pnb)
	{
		pthread_mutex_init(&ptr[i].myfork, NULL);
		ptr[i].next_fork = &ptr[(i + 1) % pnb].myfork;
		i++;
	}
	return (0);
}
