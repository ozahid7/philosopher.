/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:52:55 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (create_process(&data))
		return (ft_error(), 1);
	pthread_create(&data.meals_trd, 0, ft_meals, &data);
	waitpid(-1, 0, 0);
	ft_kill(&data);
	sem_close(data.print);
	sem_close(data.forks);
	free(data.philo);
	free(data.pid);
	return (0);
}
