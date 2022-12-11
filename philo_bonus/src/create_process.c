/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:26:49 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/10 23:03:00 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void init_sema(t_data *data)
{
	// data->forks = sem_open("forks",O_CREAT, 0666, data->time.pnb);
	// data->meals = sem_open("meals",O_CREAT, 0666, 0);
	// data->print = sem_open("print",O_CREAT, 0666, 1);

	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("dead");
	sem_unlink("meals");
	data->forks = sem_open("forks", O_CREAT, 0777, data->time.pnb);
	data->print = sem_open("print", O_CREAT, 0777, 1);
	data->meals = sem_open("meals", O_CREAT, 0777, 0);
	data->dead = sem_open("dead",O_CREAT, 0666, 1);
}

void print_it(char *str, t_philo *philo)
{
	sem_wait(philo->print);
	printf("%ld %d %s", (get_time() - philo->start), philo->id, str);
	sem_post(philo->print);
}

void	philo_do(t_philo *philo)
{
	philo->start = get_time();
	philo->lmeal = get_time();
	if (philo->id % 2 == 0)
		usleep(philo->times.eat * 1000);
	while (1)
	{
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		sem_wait(philo->forks);
		print_it("has taken a fork\n", philo);
		print_it("is eating\n", philo);
		philo->lmeal = get_time();
		usleep(philo->times.eat * 1000);
		//printf("nb of meals: %d\n", time.meals);
		sem_post(philo->forks);
		sem_post(philo->forks);
		print_it("is sleeping\n", philo);
		usleep(philo->times.sleep * 1000);
		print_it("is thinking\n", philo);
		if (philo->times.meals >= 0)
			philo->times.meals--;
		if (philo->times.meals == 0)
			sem_post(philo->meals);
	}
}

void ft_kill(t_data *data)
{
	int i;

	i = 0;
	while(data->pid[i])
	{
		kill(data->pid[i], 9);
		i++;
	}
}

int	create_process(t_data *data)
{
	int		i;
	int		id;
	t_philo	*philo = NULL;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->time.pnb);
	if (!data->philo)
		return (0);
	data->pid = malloc(sizeof(int) * data->time.pnb);
	if (!data->pid)
		return (0);
	init_sema(data);
	id = 2;
	while (i < data->time.pnb)
	{
		if (id != 0)
			id = fork (); 
		if (id == 0)
		{
			philo = &data->philo[i];
			philo->id = i + 1;
			philo->times = data->time;
			philo->dead = data->dead;
			philo->forks = data->forks;
			philo->print = data->print;
			philo->meals = data->meals;
			pthread_create(&philo->thread, NULL, &check_death, philo);
			philo_do(philo);
			//i++;
			break ;
		}
		else
			data->pid[i] = id;
		i++;
	}
	return (0);	
}
