/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 08:08:21 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	long	time;

	time = 0;
	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (data_init(&data))
		return (ft_error(), 1);
	//pthread_mutex_destroy(&data.philo->myfork);
	
	pthread_mutex_destroy(data.philo->next_fork);
	free (data.philo);
	return (0);
}
