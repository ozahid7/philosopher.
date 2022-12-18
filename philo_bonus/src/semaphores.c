/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:50:47 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:31:10 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sema(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meals");
	data->forks = sem_open("forks", O_CREAT, 0777, data->time.pnb);
	data->print = sem_open("print", O_CREAT, 0777, 1);
	data->meals = sem_open("meals", O_CREAT, 0777, 0);
}

void	print_it(char *str, t_philo *philo)
{
	sem_wait(philo->print);
	printf("%ld %d %s", (get_time() - philo->data->start), philo->id, str);
	sem_post(philo->print);
}
