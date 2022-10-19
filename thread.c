#include "Philo.h"

void mutex_create(t_alhai *alhay)
{
	int i = 0;
	while (i < alhay->num_philo )
	{
		pthread_mutex_init(&alhay->forks_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&alhay->mutex_print, NULL);
}

void *thread_func(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (1)
	{
		while (check_forks(philo) == 0)
			usleep(50);
		philo_eating(philo);
		drop_fork(philo);
		philo_sleep(philo);
		ft_print(philo,'t');
	}
	return NULL;
}

void ft_print(t_philo *philo, char c)
{
	long long starter;

	starter = current_time() - philo->alhai->start_time;

	pthread_mutex_lock(&philo->alhai->mutex_print);
	if (c == 's')
		printf("[%lld] philosopher %d is sleeping", starter ,philo->index);
	else if (c == 'e')
		printf("[%lld] philosopher %d is eating", starter ,philo->index);
	else if (c == 't')
		printf("[%lld] philosopher %d is thinking", starter ,philo->index);
	else if (c == 'p')
	{
		printf("[%lld] philosopher %d has picked up a fork", starter ,philo->index);
		printf("[%lld] philosopher %d has picked up a fork", starter ,philo->index);
	}

	pthread_mutex_unlock(&philo->alhai->mutex_print);
}


void init_philo(t_alhai *alhay)
{
	int i;
	i = 0;
	while (i < alhay->num_philo)
	{
		alhay->philo[i].index = i;
		alhay->philo[i].time_ate = 0;
		alhay->philo[i].left_fork = i;
		alhay->philo[i].right_fork =  i + 1;
		alhay->forks[i] = 0;
		if (i == (alhay->num_philo -1))
		{
			alhay->philo[i].right_fork = 0;
		}
		i++;
	}
}

//to check if the the two forks are being used
int check_forks(t_philo *philo)
{

	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->left_fork]);
	if (philo->alhai->forks[philo->left_fork] == 1)
	{
		pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
		return (0);
	}
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->right_fork]);
	if (philo->alhai->forks[philo->right_fork] == 1 )
	{
		pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
		pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
		return (0);
	}
	philo->alhai->forks[philo->left_fork] = 1;
	philo->alhai->forks[philo->right_fork] = 1;
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
	return (1);
}

void	philo_eating(t_philo *philo)
{
	ft_print(philo, 'p');
	ft_print(philo, 'e');
	alhai_sleep(philo->alhai->time_eat);
	philo->time_ate++;
	philo->last_meal = current_time();
}



void athread(t_alhai *alhay)
{
	int i;
	i =0;
	while (i < alhay->num_philo)
	{
		alhay->philo[i].last_meal = current_time();
		printf("alhai\n");
    	pthread_create(&alhay->threadz[i], NULL, &thread_func, &alhay->philo[i]);
		i++;
	}
	i = 0;
	while (i < alhay->num_philo)
		pthread_join(alhay->threadz[i++], NULL);
}

//sleeping function
void philo_sleep(t_philo *philo)
{
	ft_print(philo,'s');
	alhai_sleep(philo->alhai->time_sleep);
}

 void drop_fork(t_philo *philo)
 {
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->right_fork]);
	pthread_mutex_lock(&philo->alhai->forks_mutex[philo->left_fork]);
	philo->alhai->forks[philo->left_fork] = 0;
	philo->alhai->forks[philo->right_fork] = 0;
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->right_fork]);
	pthread_mutex_unlock(&philo->alhai->forks_mutex[philo->left_fork]);
 }
