/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:59 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/01 17:24:27 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first  solution for Philo
#include "Philo.h"

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
