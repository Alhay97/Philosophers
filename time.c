#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>


long long current_time(void)
{
	struct timeval now_time;

	gettimeofday(&now_time, NULL);
	return ((now_time.tv_sec * 1000) + (now_time.tv_usec / 1000));  //this is conversion from seconds to milliseconds from 1994 till the current time
}

// it checks if the differnce in time is more than the duration perimeter
void alhai_sleep(int duration)
{
	long long start_time;
	start_time = current_time();
	while (current_time() - start_time < duration)
		usleep(duration);
}
