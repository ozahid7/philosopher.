/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:26:49 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/08 01:47:46 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void init_sema(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("print");
	data->forks = sem_open("forks",O_CREAT, 0666, data->time.pnb);
	data->print = sem_open("print",O_CREAT, 0666, data->time.pnb);
}

void print_it(char *str, t_data *data)
{
	sem_wait(data->print);
	printf("%ld %d %s", (get_time() - data->philo->start), data->philo->id, str);
	sem_post(data->print);
}

void	*philo_do(t_data *data)
{
	//printf("im in routine\n");
	data->philo->start = get_time();
	data->philo->lmeal = get_time();
	if (data->philo->id % 2 == 0)
		ft_sleep(data->time.eat);
	//printf ("-----------------------id = %d \n", data->philo->id);
	while (1)
	{
		sem_wait(data->forks);
		print_it("has taken a fork\n", data);
		sem_wait(data->forks);
		print_it("has taken a fork\n", data);
		print_it("is eating\n", data);
		data->philo->lmeal = get_time();
		ft_sleep(data->time.eat);
		// if (philo->times.meals > 0)
		// 	philo->times.meals--;
		sem_post(data->forks);
		sem_post(data->forks);
		print_it("is sleeping\n", data);
		ft_sleep(data->time.sleep);
		print_it("is thinking\n", data);
	}
	// printf("******************pid = %d", data->philo->pid[i]);
}

void ft_kill(t_data *data)
{
	int i;

	i = 0;
	// printf("im in ft_kill \n");
	// printf("pid = %d\n", data->pid[i]);
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
	while (i < data->time.pnb)
	{
		id = fork (); 
		if (id == 0)
		{
			//philo->pid[i] = getpid();
			// printf("pid = %d \n", philo->pid[i]);
			philo = &data->philo[i];
			data->philo->id = i + 1;
			philo->times = data->time;
			pthread_create(&data->philo[i].thread, NULL, &check_death, data);
			philo_do(data);
			//i++;
		}
		else
			data->pid[i] = id;
			
		i++;
	}
	return (0);	
}
