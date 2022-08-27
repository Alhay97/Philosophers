#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	fork();
	fork();
	fork();
	fork();

	printf("Hello alhai\n");
	return (0);
}
