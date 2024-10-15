#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;

void    *routine(void *arg)
{
	if (pthread_mutex_trylock(&mutex) == 0){
		printf("Locked\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	} else {
		printf("The resourse is locked\n");
		sleep(1);
		routine(arg);
	}
}

int main(void)
{
	pthread_t th[4];
	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Error while creating thread\n");
	}

	for (int i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Error while joining thread\n");
	}
	return (0);
}