#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	*roll_dice()
{
	int value = (rand() % 6) + 1;
	int *res = malloc(sizeof(int));
	*res = value;
	printf("The value is %d\n", value); 
	return ((void *)&res);
}

int main(void)
{
	int *res; 
	pthread_t th;
	srand(time(NULL));
	if (pthread_create(&th, NULL, &roll_dice, NULL)  != 0)
		return (1);
	if (pthread_join(th, (void **)&res) != 0)
		return (2);
	printf("The result is: \n", *res);
	free(res);
	return (2); 
}