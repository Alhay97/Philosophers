#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


pthread_t tid[2];
int counter;

void * trythis(void* arg)
{
	unsigned long i = 0;
	counter += 1;

	printf("\n Job %d has begun \n",counter);
	i = 0;
	while(i < (0xFFFFFFFF))
	{
		i++;
	} 
	printf("\n Job %d has ended \n",counter);
	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	while (i < 2)
	{
		error = pthread_create	(&(tid[i]), NULL, &trythis, NULL);
		if (error != 0)
			printf("\n This thread cannot be created : [%s]",strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
}

/*
the output is :

 Job 1 has begun

 Job 2 has begun

 Job 2 has ended

 Job 2 has ended

*/

/*
the reason is:
1-> thread 1 is being processing while the scheduler scheduled thread 2
2-> if reason (1) is true then the value of ("counter") variable got incrmented 
    again before job 1 has ended
3-> when the first job has ended, the wrong value of counter has been produced the log "job 2 has ended"
    followed by another "job 2 has ended" as it is dependent on the sechdular.
4-> the problem is the wrong value of ("counter") becuase of the usage ("counter") variable by a second thread
    when the first thread was using or about to use it
5-> lack of synchronization between the threads while using the shared resource ‘counter’ caused the problems or in one word 
    we can say that this problem happened due to ‘Synchronization problem’ between two threads
*/

