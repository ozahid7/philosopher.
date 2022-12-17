/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:52:19 by ozahid-           #+#    #+#             */
/*   Updated: 2022/12/17 11:02:58 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data	t_data;

typedef struct s_times
{
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
	pthread_mutex_t	*next_fork;
	t_times			times;
	t_data			*data;
	int				id;
	long			lmeal;
}	t_philo;

typedef struct s_data
{
	long			start;
	int				run;
	pthread_mutex_t	print;
	t_philo			*philo;
	t_times			time;
}	t_data;

int		check_death(t_data *data);
void	destroy_mutex(t_data *data);
int		init_mutex(t_data *data);
void	print_it(char *str, t_philo *ptr);
long	get_time(void);
int		data_init(t_data *ptr);
int		ft_parce(t_data *ptr, int ac, char **av);
int		check_args_int(char ch, int *sig);
int		check_empty(char **av);
int		ft_strlen(char *str);
void	*philo_do(void *num);
void	ft_sleep(long time);
int		is_double(int id);
void	ft_free_args(char **str);
int		ft_atoi(char *str, int *e);
void	ft_error(void);

#endif