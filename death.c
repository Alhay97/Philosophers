/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:44 by aalhamel          #+#    #+#             */
/*   Updated: 2022/10/31 16:19:25 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"


//start_time
//time_die
//last_meal

void	death_checker(t_alhai *alhay)
{
    if ((current_time() - alhay->philo[alhay->philo->index].last_meal) > (alhay->time_die))
    {
        alhay->if_dead = 1;
        return ;
    }
}

void killer(t_alhai *alhay)
{
	int i;
	i = 0;
	while()
}
