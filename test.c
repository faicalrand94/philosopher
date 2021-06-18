#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
int i = 0;
pthread_mutex_t mut;

void *fun(void * ikhan)
{
    for (int j = 0; j < 1000000; j++)
    {
        pthread_mutex_lock(&mut);
        i++;
        pthread_mutex_unlock(&mut);

    }
    return (NULL);
}

void *fun2(void * ikhan)
{
    for (int j = 0; j < 2000000; j++)
    {
        pthread_mutex_lock(&mut);
        i++;
        pthread_mutex_unlock(&mut);

    }
    return (NULL);
}

int main()
{
    pthread_t p1;
    pthread_t p2;

    pthread_mutex_init(&mut, NULL);
    pthread_create(&p1, NULL, fun, NULL);
    pthread_create(&p2, NULL, fun2, NULL);
    pthread_join(p1, NULL);
    printf("%d\n", i);
    
    pthread_join(p2, NULL);
    printf("%d\n", i);
    //pthread_mutex_destroy(&mut);
    return (0);
}