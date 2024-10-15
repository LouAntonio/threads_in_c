#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mails_qtt = 0;
pthread_mutex_t mutex;

void    *routine()
{
	for (int i = 0; i < 1000000; i++){
		pthread_mutex_lock(&mutex);
		mails_qtt++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(void)
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);
	printf("mails qtt = %d\n", mails_qtt);
	return (0);
}