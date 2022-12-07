/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:52:19 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/06 05:13:03 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
# include "philo_utils_bonus.h"

typedef struct s_times
{
	char	**args;
	int		pnb;
	int		eat;
	int		sleep;
	int		die;
	int		meals;

}	t_times;

typedef struct s_philo
{
	int				*pid;
	int				i;
	t_times			times;
	int				id;
	pthread_t		thread;
	long			lmeal;
	sem_t			*forks;
	sem_t			*print;
	int				meals_number;
	long			start;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	t_times			time;
}	t_data;

void	*philo_do(void *data_ptr);
int		create_process(t_data *data);
void	*check_death(void *_philo);
int		init_semaphores(t_data *data, int pnb);
void	print_it(char *str, t_philo *philo);
long	get_time(void);
int		data_init(t_data *ptr);
int		ft_parce(t_data *ptr, int ac, char **av);
int		check_args_int(char ch, int *sig);
int		check_time(t_philo *philo);
int		check_empty(char **av);
int		ft_strlen(char *str);
void	ft_sleep(long time);
int		is_double(int id);

#endif