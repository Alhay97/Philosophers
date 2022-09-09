#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	fun(void);

void	*func(void *arg)
{
	pthread_detach(pthread_self()); //detach the current thread from the called thread
	printf("inside the thread\n");
	pthread_exit(NULL);
}

void	fun(void)
{
	pthread_t	alhai;

	pthread_create(&alhai, NULL, &func, NULL); // it is where a new thread is created
	printf("this is the line to be printed"
		" before the thread is terminated\n");
	if (pthread_equal(alhai, pthread_self())) //checks if the created thread is same as the current thread
		printf("the thread are equal\n");
	else
		printf("the thread are not equal\n");
	pthread_join(alhai, NULL); //waiting for the just created thread to terminate
	printf("this line will be printed after"
		"the thread is terminated \n");
	pthread_exit(NULL); //used to terminate the thread
}

int	main(void)
{
	fun();
	return (0);
}
