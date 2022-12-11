/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/10 23:01:38 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *data)
{
	int	i;
	int	meals;
	t_philo *philo;
	philo = (t_philo *) data;
	
	while (1)
	{
		i = 0;
		meals = 0;
		while (i < philo->times.pnb)
		{
			// if (philo->philo[i].times.meals == 0)
			// 	meals++;
			if (get_time() - philo->lmeal > philo->times.die)
			{
				sem_wait(philo->dead);
				print_it("is dead\n", philo);
				exit(1);
			}
			// if (meals == data->time.pnb)
			// 	ft_kill(data);
			i++;
		 }
	}
}

void	*ft_meals(void *ptr)
{
	int	i;
	t_data *data;

	data = (t_data *) ptr;
	i = 0;
	while (i < data->time.pnb)
	{
		sem_wait(data->meals);
		i++;
	}
	ft_kill(data);
	exit(8);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int wpid;
	int	i;
	i = -1;

	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (create_process(&data))
		return (ft_error(), 1);
	// id = fork();
	// if (id == 0)
		// ft_meals(&data);
	pthread_create(&data.meals_trd, 0, ft_meals, &data);
	wpid = waitpid(-1, 0, 0);
	if (wpid > 0)
		ft_kill(&data);
	return (0);
}
