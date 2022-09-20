//first  solution for Philo
#include "Philo.h"

int main(int arc, char **arv)
{
	int i;
	i = 0;
	int j = 0;
	int *ab;

	ab = malloc(sizeof(int) * arc-1);
	arv++;
    while (i < arc - 1)
    {
		if ((ab[i] = ft_atoi(arv[i])) < 0){
			printf("there is an error number\n");
			return (0);
		}
		i++;
	}
	while (j < i)
		printf("%d\n", ab[j++]);
	return 0;
}
