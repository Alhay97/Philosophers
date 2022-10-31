/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:20:11 by aalhamel          #+#    #+#             */
/*   Updated: 2022/10/31 19:42:12 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

long long	current_time(void)
{
	struct timeval now_time;

	gettimeofday(&now_time, NULL);
	return ((now_time.tv_sec * 1000) + (now_time.tv_usec / 1000));  //this is conversion from seconds to milliseconds from 1994 till the current time
}

// it checks if the differnce in time is more than the duration perimeter
void	alhai_sleep(t_philo *philo,int duration)
{
	long long	start_time;
	start_time = current_time();
	while (current_time() - start_time < duration)
	{
		if ((current_time() - philo->last_meal) > (philo->alhai->time_die))
		{
			break;
		}
		usleep(duration);
	}
}
