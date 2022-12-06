/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:52:19 by ozahid-           #+#    #+#             */
/*   Updated: 2022/11/20 00:23:16 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "philo_utils.h"

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
	int				i;
	pthread_t		thread;
	pthread_mutex_t	myfork;
	pthread_mutex_t	print;
	pthread_mutex_t	*next_fork;
	t_times			times;
	int				id;
	long			lmeal;
	int				meals_number;
	long			start;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	t_times			time;
}	t_data;

int		check_time(t_philo *philo);
int		check_death(t_data *data);
int		init_mutex(t_philo *ptr, int pnb);
void	print_it(char *str, t_philo *ptr);
long	get_time(void);
int		data_init(t_data *ptr);
int		ft_parce(t_data *ptr, int ac, char **av);
int		check_args_int(char ch, int *sig);
int		check_empty(char **av);
int		ft_strlen(char *str);
int		check_empty(char **av);
void	*philo_do(void *num);
void	ft_sleep(long time);
int		is_double(int id);

#endif