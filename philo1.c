/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:59 by aalhamel          #+#    #+#             */
/*   Updated: 2022/10/30 20:27:56 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first  solution for Philo
#include "Philo.h"

int	ft_parser(char **arv, t_alhai *alhai)
{
	int	i;

	i = 1;
	while (arv[i])
	{
		if (ft_atoi(arv[i]) <= 0)
			return (0);
		i++;
	}
	alhai->num_philo = ft_atoi(arv[1]);
	alhai->time_die = ft_atoi(arv[2]);
	alhai->time_eat = ft_atoi(arv[3]);
	alhai->time_sleep = ft_atoi(arv[4]);
	if (arv[5])
	{
		alhai->num_cycle = ft_atoi(arv[5]);
		return (0);
	}
	else if (!arv[5])
		alhai->num_cycle = 999999;
	if (alhai->num_philo <= 0 || alhai->time_die <= 60 || alhai->time_eat <= 60
		|| alhai->num_philo > 200 || alhai->time_sleep <= 60)
		return (0);
	return (1);
}

void	print_index(t_alhai *alhai)
{
	int	i;

	i = 0;
	while (i < alhai->num_philo)
		printf("index -> %d \n", alhai->philo[i++].index);
}

int	main(int arc, char **arv)
{
	int		i;
	int		ab[200];
	t_alhai	alhai;

	if (ft_parser(arv, &alhai) == -1)
		return (-1);
	mutex_create(&alhai);
	init_philo(&alhai);
	athread(&alhai);
	return (0);
}
