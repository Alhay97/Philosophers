/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:56 by aalhamel          #+#    #+#             */
/*   Updated: 2022/10/31 19:39:41 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				index;
	long long		last_meal;
	int				left_fork;
	int				right_fork;
	unsigned int	time_ate;
	int				*death_flag;
	struct s_alhai	*alhai;

}	t_philo;

typedef struct s_alhai
{
	pthread_t		threadz[200];
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_cycle;
	long long		start_time;
	int				*if_dead;
	int				*forks;
	t_philo			philo[200];
	pthread_mutex_t	forks_mutex[200];
	pthread_mutex_t	mutex_print;
}	t_alhai;

void		drop_fork(t_philo *philo);

void		philo_sleep(t_philo *philo);

void		athread(t_alhai *alhay);

void		philo_eating(t_philo *philo);

int			check_forks(t_philo *philo);

void		init_philo(t_alhai *alhay);

void		ft_print(t_philo *philo, char c);

void		*thread_func(void *data);

int			ft_parser(char **arv, t_alhai *alhai);

void		print_index(t_alhai *philo);

int			check_sum(unsigned long sum, int sign, const char *str);

int			ft_atoi(const char *str);

void		ft_putchar_fd(int c, int fd);

void		ft_putstr_fd(char *str, int fd);

void		ft_putendl_fd(char *str, int fd);

long long	current_time(void);

void		alhai_sleep(t_philo *philo,int duration);

void		mutex_create(t_alhai *alhay);

int			death_checker(t_philo *philo);

void 		killer(t_alhai *alhay);

void		death_printer(t_philo *philo);

#endif
