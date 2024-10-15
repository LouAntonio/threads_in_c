#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*rountine(void *arg)
{
	int index = *(int *)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += primes[index + i];
    printf("Local sum: %d\n", sum);
    *(int *)arg = sum;
   return (arg);
}

int main(void)
 {
    int i;
	pthread_t th[2];
	for  (i = 0; i < 2; i++){
		int *a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &rountine, a) != 0)
			perror("Failed to create thread");
	}

    int tot = 0;
	for (i = 0; i < 2; i++) {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed to join thread");
        }
        tot += *r;
        free(r);
    }
    printf("Total is = %d\n", tot);
    return (0);
 }