#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void	*routine()
{
	printf("The value of `i` is\n");
}

int main(void)
{
	int i = 0;
	pthread_t pt[4];
	while (++i <= 4)
		pthread_create(&pt[i], NULL, &routine, NULL);
	i = 0;
	while (++i <= 4)
		pthread_join(pt[i], NULL);
}