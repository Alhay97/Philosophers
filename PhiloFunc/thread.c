#include "Philo.h"


/*
1. create a infinte while loop
2.start with taking forks and eating
*/

void *thread_func(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data; // <-- continue here
	printf(" %d thread reached here \n", philo->index);
	return NULL;
}

void init_philo(t_alhai *alhay)
{
	int i;
	i = 0;
	while (i < alhay->num_philo)
	{
		alhay->philo[i].index = i;
		alhay->philo[i].time_ate = 0;
		i++;
	}
}

void athread(t_alhai *alhay)
{
	int i;
	i =0;
	while (i < alhay->num_philo)
	{
    	pthread_create(&alhay->threadz[i], NULL, &thread_func, &alhay->philo[i]);
		i++;
	}
	i = 0;
	while (i < alhay->num_philo)
		pthread_join(alhay->threadz[i++], NULL);
}

