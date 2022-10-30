/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:19:53 by aalhamel          #+#    #+#             */
/*   Updated: 2022/10/30 20:21:32 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

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

void	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}

void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
