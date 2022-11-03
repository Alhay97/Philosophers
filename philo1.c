/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:59 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/03 21:02:22 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first  solution for Philo
#include "Philo.h"

// int	destroy_mutex(t_philosophy	*philosophy)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philosophy->philo_count)
// 	{
// 		if (pthread_mutex_destroy(&(philosophy->forks_mutex[i])) != 0)
// 			return (1);
// 		i++;
// 	}
// 	if (pthread_mutex_destroy(&(philosophy->dead_m)) != 0)
// 		return (1);
// 	if (pthread_mutex_destroy(&(philosophy->meals_m)) != 0)
// 		return (1);
// 	if (pthread_mutex_destroy(&(philosophy->write_m)) != 0)
// 		return (1);
// 	return (0);
// }

void	init_alhai(t_alhai *alhai)
{
	alhai->num_philo = 0;
	alhai->time_die = 0;
	alhai->time_eat = 0;
	alhai->time_sleep = 0;
	alhai->num_cycle = 0;
}

int	main(int arc, char **arv)
{
	t_alhai	alhai;

	if (arc < 5 || arc > 6)
		return (0);
	init_alhai(&alhai);
	if (ft_parser(arv, &alhai) == 0)
		return (-1);
	mutex_create(&alhai);
	init_philo(&alhai);
	athread(&alhai);
	//destroy_mutex(philosophy);
	free (alhai.forks);
	free(alhai.if_dead);
	return (0);
}
