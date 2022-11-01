/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:53 by aalhamel          #+#    #+#             */
/*   Updated: 2022/11/01 17:33:14 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_sum(unsigned long sum, int sign, const char *str)
{
	if (sum > 2147483647 && sign == 1)
	{
		write(2, "Error1 \n", 6);
		return (0);
	}
	else if (sum > 2147483648 && sign == -1)
	{
		write(2, "Error2 \n", 6);
		return (0);
	}
	else if (*str)
	{
		write (2, "ERROR3 \n", 6);
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (check_sum (sum, sign, str) == 0)
		return (-1);
	return (sum * sign);
}
