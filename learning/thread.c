#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	fun(void);

void	*func(void *arg)
{
	//detach the current thread from the called threads
	pthread_detach(pthread_self());
	printf("inside the thread\n");
	pthread_exit(NULL);
}

void	fun(void)
{
	//store the thread
	pthread_t	alhai;

	// it is where a new thread is created
	pthread_create(&alhai, NULL, &func, NULL);
	printf("this is the line to be printed"
		" before the thread is terminated\n");

		//checks if the created thread is same as the current thread
	if (pthread_equal(alhai, pthread_self()))
		printf("the thread are equal\n");
	else
		printf("the thread are not equal\n");

	//waiting for the just created thread to terminated
	pthread_join(alhai, NULL);
	printf("this line will be printed after"
		"the thread is terminated \n");

	//used to terminate the thread
	pthread_exit(NULL);
}

//the output for the above program will be:
/*
this is the line to be printed before the thread is terminated

inside the thread


the thread are not equal

this line will be printed afterthe thread is terminated
*/

int	main(void)
{
	fun();
	return (0);
}
