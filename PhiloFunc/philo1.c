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

int  ft_parser(int arc, char **arv, t_alhai *philo, int *ab)
{
	int i;

	ab = malloc(sizeof(int) * arc-1);
	i = 0;
	arv++;
    while (i < arc - 1)
    {
		if (arc < 5 || arc > 6 || arc == 1)
			return(-1);
		else
		{
			if ((ab[i] = ft_atoi(arv[i])) < 0)
			{
				printf("there is an error number\n");
				return (-1);
			}
		}
		i++;
	}

	philo->num_philo = ab[0];
    philo->time_die = ab[1];
    philo->time_eat = ab[2];
    philo->time_sleep = ab[3];
    philo->num_cycle = ab[4];
	return (0);
}

void print_index(t_alhai *philo)
{
	int i = 0;
	while (i < philo->num_philo)
		printf("index -> %d \n", philo->philo[i++].index);
}


int main(int arc, char **arv)
{
	int i;
	int *ab;
	t_alhai philo;

	if(ft_parser(arc, arv, &philo, ab) == -1)
		return(-1);
	init_philo(&philo);
	// while (i < philo.num_philo)
	// {
	// 	printf("%d index \n", philo.philo[i++].index);
	// }
	athread(&philo);

	return 0;
}
