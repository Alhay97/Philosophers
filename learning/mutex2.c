/*
Working of a mutex

Suppose one thread has locked a region of code using mutex and is executing that piece of code.
Now if scheduler decides to do a context switch, then all the other threads which are ready to execute the same region are unblocked.
Only one of all the threads would make it to the execution but if this thread tries to execute the same region of code that is already locked then it will again go to sleep.
Context switch will take place again and again but no thread would be able to execute the locked region of code until the mutex lock over it is released.
Mutex lock will only be released by the thread who locked it.
So this ensures that once a thread has locked a piece of code then no other thread can execute the same region until it is unlocked by the thread who locked it.
*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



pthread_t tid[2];
int counter;
pthread_mutex_t lock;



// this function is created the success or failure of the mutex 
void *trythis(void *arg)
{
	pthread_mutex_lock(&lock);// locks the mutex
	unsigned long i ;

	counter += 1;

	printf("\n Job %d has started\n", counter);

	i = 0;
	while(i < (0xFFFFFFFF))
	{
		i++;
	}
	printf("\n Job %d has ended\n", counter);

	pthread_mutex_unlock(&lock); //unlocks the mutex

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	if(pthread_mutex_init(&lock,NULL) != 0)// initialize the mutex locks
	{
		printf("\n mutex init has failed \n");
		return 1;
	}
	while (i < 2)
	{
		error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		if (error != 0)
			printf("\n Thread cannot be created : [%s]\n",strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock); // destroy the mutex

	return (0);
}


// The output is:
/*
 Job 1 has started

 Job 1 has ended

 Job 2 has started

 Job 2 has ended
 */
