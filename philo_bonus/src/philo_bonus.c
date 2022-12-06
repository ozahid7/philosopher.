/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/04 02:07:00 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *_philo)
{
	int	i;
	int	meals;
	t_philo *philo;
	philo = (t_philo *) _philo;
	
	while (1)
	{
		i = 0;
		meals = 0;
		while (i < philo->times.pnb)
		{
			// if (philo[i].times.meals == 0)
			// 	meals++;
			if (check_time(&philo[i]))
			{
				printf("%ld %d is dead\n", get_time() - philo->start, philo->id);
				exit (1);
			}
			// if (meals == philo->times.pnb)
			// 	return (0);
			i++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (create_process(&data))
		return (ft_error(), 1);

	waitpid(-1, NULL, 0);
	return (0);
}
