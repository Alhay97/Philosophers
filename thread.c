/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:20:08 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/03 19:42:12 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void only_one(t_philo *philo)
{
	while(*philo->death_flag == 0)
	{
		usleep(50);
	}
}

void	*thread_func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->alhai->num_philo == 1)
	{
		only_one(philo);
	}
	pthread_mutex_lock(&philo->alhai->mutex_death);
	while (*philo->death_flag == 0 && philo->all_eat == 0)
	{
		pthread_mutex_unlock(&philo->alhai->mutex_death);
		while (check_forks(philo) == 0)
			usleep(50);
		philo_eating(philo);
		drop_fork(philo);
		philo_sleep(philo);
		ft_print(philo, 't');
		usleep(500);
		pthread_mutex_lock(&philo->alhai->mutex_death);
	}
	pthread_mutex_unlock(&philo->alhai->mutex_death);
	return (NULL);
}

void	athread(t_alhai *alhay)
{
	int	i;

	i = 0;
	alhay->start_time = current_time();
	while (i < alhay->num_philo)
	{
		alhay->philo[i].last_meal = current_time();
		pthread_create(&alhay->threadz[i], NULL,
			&thread_func, &alhay->philo[i]);
		usleep(100);
		i++;
	}
	i = 0;
	killer(alhay);
	while (i < alhay->num_philo)
		pthread_join(alhay->threadz[i++], NULL);
}

/* to check if the the two forks are being used */
int	check_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->right_fork]);
	if (philo->alhai->forks[philo->right_fork] == 1)
	{
		pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
		return (0);
	}
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->left_fork]);
	if (philo->alhai->forks[philo->left_fork] == 1)
	{
		pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
		pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
		return (0);
	}
	philo->alhai->forks[philo->left_fork] = 1;
	philo->alhai->forks[philo->right_fork] = 1;
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
	return (1);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->right_fork]);
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->left_fork]);
	philo->alhai->forks[philo->right_fork] = 0;
	philo->alhai->forks[philo->left_fork] = 0;
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
}
