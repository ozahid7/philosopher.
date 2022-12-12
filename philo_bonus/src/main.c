/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:54 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/12 04:59:08 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		wpid;
	int		i;

	i = -1;
	if (ft_parce(&data, ac, av))
		return (ft_error(), 1);
	if (create_process(&data))
		return (ft_error(), 1);
	pthread_create(&data.meals_trd, 0, ft_meals, &data);
	wpid = waitpid(-1, 0, 0);
	if (wpid > 0)
		ft_kill(&data);
	return (0);
}
