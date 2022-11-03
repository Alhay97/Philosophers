/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:30:53 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/03 21:00:54 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void	init_philo(t_alhai *alhay)
{
	int	i;

	alhay->forks = malloc (sizeof(int) * alhay->num_philo);
	if (!alhay->forks)
		return ;
	i = 0;
	alhay->if_dead = malloc(sizeof(int));
	if (!alhay->if_dead)
		return ;
	*alhay->if_dead = 0;
	while (i < alhay->num_philo)
	{
		alhay->philo[i].all_eat = 0;
		alhay->philo[i].index = i;
		alhay->philo[i].time_ate = 0;
		alhay->philo[i].death_flag = alhay->if_dead;
		alhay->forks[i] = 0;
		alhay->philo[i].alhai = alhay;
		if ((alhay->num_philo - 1) == i)
			alhay->philo[i].left_fork = 0;
		else
			alhay->philo[i].left_fork = i + 1;
		alhay->philo[i].right_fork = i;
		if (i % 2)
			ft_swap(&alhay->philo[i].left_fork,
				&alhay->philo[i].right_fork);

		i++;
	}

}

void	mutex_create(t_alhai *alhay)
{
	int	i;

	i = 0;
	while (i < alhay->num_philo)
	{
		pthread_mutex_init(&alhay->forks_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&alhay->mutex_print, NULL);
	pthread_mutex_init(&alhay->mutex_death, NULL);
	pthread_mutex_init(&alhay->mutex_eat, NULL);
}
