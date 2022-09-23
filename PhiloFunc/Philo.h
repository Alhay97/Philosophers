#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

//create an array of struct for each philospheres

typedef struct philosphers
{
    
};

int	check_sum(unsigned long sum, int sign, const char *str);

int     ft_atoi(const char *str);

void	ft_putchar_fd(int c, int fd);

void    ft_putstr_fd(char *str, int fd);

void	ft_putendl_fd(char *str, int fd);

#endif
