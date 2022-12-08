/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/08 01:50:04 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *_data)
{
	int	i;
	int	meals;
	t_data *data;
	data = (t_data *) _data;
	
	while (1)
	{
	i = 0;
	meals = 0;
		while (i < data->time.pnb)
		{
	// 		// if (philo[i].times.meals == 0)
	// 		// 	meals++;
			if (get_time() - data->philo->lmeal > data->time.die)
			{
				print_it("is dead\n", data);
				//printf("---------------------%ld\n", get_time() - data->philo->start);
				exit(1);
			}
	// 		// if (meals == philo->times.pnb)
	// 		// 	return (0);
			i++;
		 }
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (create_process(&data))
		return (ft_error(), 1);
	waitpid(-1, NULL, 0);
	ft_kill(&data);
	//printf("tfo\n");
	return (0);
}
