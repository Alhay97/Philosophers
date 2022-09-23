//first  solution for Philo
#include "Philo.h"

// arguments for Philo->1. a.out 
//						2. number of philosphers 
// 						3.Time to die
// 						4.Time to Eat
//						5.Time to sleep
//						6.number of cycles 
// save it all in a structure


//second step


// int main(int arc, char **arv)
// {
// 	int i;
// 	int j;
// 	int *ab;
// 	t_philo philo;

// 	ab = malloc(sizeof(int) * arc-1);
// 	i = 0;
// 	j = 0;
// 	arv++;
//     while (i < arc - 1)
//     {
// 		if (arc < 5 || arc > 6)
// 			return(0);
// 		else
// 		{
// 			if ((ab[i] = ft_atoi(arv[i])) < 0)
// 			{
// 				printf("there is an error number\n");
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
	
// 	philo.num_philo = ab[0];
//     philo.time_die = ab[1];
//     philo.time_eat = ab[2];
//     philo.time_sleep = ab[3];
//     philo.num_cycle = ab[4];
// 	printf("number of Philo-> %d\n", philo.num_philo);
// 	printf("time to die-> %d\n", philo.time_die);
//     printf("time to eat-> %d\n", philo.time_eat);
//    	printf("time to sleep-> %d\n", philo.time_sleep);
//     printf("number of cycles for each philo> %d\n", philo.num_cycle);
// 	return 0;
// }

int main()
{
	t_time ti;
	gettimeofday(&ti,NULL);
	printf("seconds : %ld \nmicro seconds : %d", 
    	ti.time, ti.time2);
	return (0);
}
