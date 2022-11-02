/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:59 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/02 19:03:30 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first  solution for Philo
#include "Philo.h"

int	main(int arc, char **arv)
{
	t_alhai	alhai;
	(void)arc;
	if (ft_parser(arv, &alhai) == -1)
		return (-1);
	mutex_create(&alhai);
	init_philo(&alhai);
	athread(&alhai);
	free (alhai.forks);
	free(alhai.if_dead);
	return (0);
}
