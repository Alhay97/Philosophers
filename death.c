/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:44 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/01 17:29:48 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	death_checker(t_philo *philo)
{
	if ((current_time() - philo->last_meal) > (philo->alhai->time_die))
	{
		death_printer(philo);
		*philo->death_flag = 1;
		return (1);
	}
	return (0);
}

void	killer(t_alhai *alhay)
{
	int	i;

	i = 0;
	while (!*alhay->if_dead)
	{
		while (i < alhay->num_philo)
		{
			if (death_checker(&alhay->philo[i]) == 1)
				break ;
			i++;
		}
		usleep(100);
		i = 0;
	}
}
