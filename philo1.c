//first  solution for Philo
#include "Philo.h"

// arguments for Philo->1. a.out
// 						2. number of philosphers
// 						3.Time to die
// 						4.Time to Eat
// 						5.Time to sleep
// 						6.number of cycles
// save it all in a structure

// https://c-for-dummies.com/blog/?p=4236

int  ft_parser(char **arv, t_alhai *alhai)
{
	int i;

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
	if(arv[5])
	{
    	alhai->num_cycle = ft_atoi(arv[5]);
		return (0);
	}
	else if(!arv[5])
        alhai->num_cycle = 999999;
	if(	alhai->num_philo <= 0 || alhai->time_die <= 60 || alhai->time_eat <= 60
		|| alhai->num_philo > 200 || alhai->time_sleep <= 60)
		return (0);
	return (1);

}

void print_index(t_alhai *alhai)
{
	int i = 0;
	while (i < alhai->num_philo)
		printf("index -> %d \n", alhai->philo[i++].index);
}

int main(int arc, char **arv)
{
	int i;
	int ab[200];
	t_alhai alhai;

	if(ft_parser(arv, &alhai) == -1)
		return(-1);
	mutex_create(&alhai);
	init_philo(&alhai);
	// while (i < philo.num_philo)
	// {
	// 	printf("%d index \n", philo.philo[i++].index);
	// }
	athread(&alhai);

	return 0;
}
