/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:44 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/01 20:29:29 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	death_checker(t_philo *philo)
{
	if ((current_time() - philo->last_meal) > (philo->alhai->time_die))
	{
		death_printer(philo);
		pthread_mutex_lock(&philo->alhai->mutex_death);
		*philo->death_flag = 1;
		pthread_mutex_unlock(&philo->alhai->mutex_death);
		return (1);
	}
	return (0);
}

void	killer(t_alhai *alhay)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&alhay->mutex_death);
	while (!*alhay->if_dead)
	{
		pthread_mutex_unlock(&alhay->mutex_death);
		while (i < alhay->num_philo)
		{
			if (death_checker(&alhay->philo[i]) == 1)
				break ;
			i++;
		}
		usleep(100);
		pthread_mutex_lock(&alhay->mutex_death);
		i = 0;
	}
	pthread_mutex_unlock(&alhay->mutex_death);
}
