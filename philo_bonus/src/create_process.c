/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:26:49 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/04 02:09:07 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void init_sema(int philo_number)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_open("forks",O_CREAT, S_IRUSR | S_IWUSR, philo_number);
	sem_open("print",O_CREAT, S_IRUSR | S_IWUSR, philo_number);
}

void print_it(char *str, t_philo *philo)
{
	sem_wait(philo->print);
	printf("%ld %d %s", (get_time() - philo->start), philo->id, str);
	sem_post(philo->print);
}

void	*philo_do(void *data_ptr)
{
	int		i;

	i = 0;
	t_philo	*philo;
	philo = (t_philo *) data_ptr;
	philo->start = get_time();
	philo->lmeal = get_time();
	pthread_create(&philo[i].thread, NULL, &check_death, philo);
	if (philo->id % 2 == 0)
		ft_sleep(philo->times.eat);
	while (1)
	{
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		print_it("is eating\n", philo);
		philo->lmeal = get_time();
		ft_sleep(philo->times.eat);
		// if (philo->times.meals > 0)
		// 	philo->times.meals--;
		sem_post(philo->forks);
		sem_post(philo->forks);
		print_it("is sleeping\n", philo);
		ft_sleep(philo->times.sleep);
		print_it("is thinking\n", philo);
		i++;
	}
	pthread_detach(philo[i].thread);
}

int	create_process(t_data *data)
{
	int		i;
	int		id;
	t_philo	*philo;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->time.pnb);
	if (!data->philo)
		return (0);
	init_sema(data->time.pnb);
	while (i < data->time.pnb)
	{
		id = fork (); 
		if (id == 0)
		{
			philo = &data->philo[i];
			philo->id = i + 1;
			philo->times = data->time;
			philo_do(philo);
		}
		i++;
	}
	// i = 0;
	// while (i < data->time.pnb)
	// {
	// 	i++;
	// }
	return (0);	
}
