#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

//create an array of struct for each philospheres
// arguments for Philo->1. a.out 
//						2. number of philosphers 
// 						3.Time to die
// 						4.Time to Eat
//						5.Time to sleep
//						6.number of cycles 
// save it all in a structure

typedef struct s_philo
{
    pthread_t philo_thread;
    int num_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_cycle;
}   t_philo;

typedef struct s_time
{
    time_t time;
    suseconds_t time2;
}   t_time;

int	check_sum(unsigned long sum, int sign, const char *str);

int     ft_atoi(const char *str);

void	ft_putchar_fd(int c, int fd);

void    ft_putstr_fd(char *str, int fd);

void	ft_putendl_fd(char *str, int fd);

#endif
