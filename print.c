/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:36:28 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/03 19:04:53 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	ft_print(t_philo *philo, char c)
{
	long long	starter;

	pthread_mutex_lock(&philo->alhai->mutex_death);
	if (*philo->death_flag == 1)
	{
		pthread_mutex_unlock(&philo->alhai->mutex_death);
		return ;
	}
	pthread_mutex_unlock(&philo->alhai->mutex_death);
	starter = current_time() - philo->alhai->start_time;
	pthread_mutex_lock(&philo->alhai->mutex_print);
	if (c == 's')
		printf("\033[0;34m [%lld] philosopher %d is sleeping 😴\n",
			starter, philo->index + 1);
	else if (c == 'e')
		printf("\033[1;31m [%lld] philosopher %d is eating 🍽️ 😋 🍽️\n",
			starter, philo->index + 1);
	else if (c == 't')
		printf("\033[1;33m [%lld] philosopher %d is thinking 🤔\n",
			starter, philo->index + 1);
	else if (c == 'p')
	{
		printf("\033[0;35m [%lld] philosopher %d has picked up a fork 🍽️\n",
			starter, philo->index + 1);
		printf("\033[0;35m [%lld] philosopher %d has picked up a fork 🍽️\n",
			starter, philo->index + 1);
	}
	pthread_mutex_unlock(&philo->alhai->mutex_print);
}

void	philo_eating(t_philo *philo)
{
	ft_print(philo, 'p');
	ft_print(philo, 'e');
	pthread_mutex_lock(&philo->alhai->mutex_eat);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->alhai->mutex_eat);
	alhai_sleep(philo, philo->alhai->time_eat);
	philo->time_ate++;
	pthread_mutex_lock(&philo->alhai->mutex_eat);
	if (philo->time_ate >= philo->alhai->num_cycle)
		philo->all_eat = 1;
	pthread_mutex_unlock(&philo->alhai->mutex_eat);
}

//sleeping function
void	philo_sleep(t_philo *philo)
{
	ft_print(philo, 's');
	alhai_sleep(philo, philo->alhai->time_sleep);
}

void	death_printer(t_philo *philo)
{
	if (*philo->death_flag == 1)
		return ;
	usleep(150);
	pthread_mutex_lock(&philo->alhai->mutex_print);
	printf("\033[1;33m [%lld] philosopher %d is Dead\n",
		current_time() - philo->alhai->start_time, philo->index + 1);
	pthread_mutex_unlock(&philo->alhai->mutex_print);
}
