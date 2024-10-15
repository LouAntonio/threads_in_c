#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

void    *routine()
{
    printf("My test function\nPID = %d\n---\n", getpid());
    sleep(3);
    printf("...\n");
}

// with process
int main(void)
{
    int pid = fork();
    int x = 2;
    if (pid == -1)
        return (1);
    if (pid == 0)
        x++;
    sleep(3);
    printf("X = %d\n", x);
    //printf("My test string\nPID = %d\n---\n", getpid());
    if (pid != 0)
        wait(NULL);
    return (0);
}

// with threads
/* int main(void)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
} */