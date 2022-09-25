#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
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

typedef struct s_info
{
    int num_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_cycle;
	long long start_time;
	struct s_philo *philo;
}   t_info;

typedef struct s_philo
{
	t_info info;
	int index;
	long long last_meal; //last time the philo second
	int left_fork;
	int right_fork;
	unsigned int time_ate; // how many times philo ate
} t_philo;

int	check_sum(unsigned long sum, int sign, const char *str);

int     ft_atoi(const char *str);

void	ft_putchar_fd(int c, int fd);

void    ft_putstr_fd(char *str, int fd);

void	ft_putendl_fd(char *str, int fd);

#endif
