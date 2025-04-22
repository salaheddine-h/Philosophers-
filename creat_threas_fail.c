#include <pthread.h>
#include <stdio.h>

void *routine(void *arg) 
{
    return NULL;
}

int main() 
{
    pthread_t threads[20000];
    int i;
    for (i = 0; i < 10000; i++) {
        if (pthread_create(&threads[i], NULL, routine, NULL) != 0) {
            printf("Thread creation failed at %d\n", i);
            break;
        }
    }
    printf("Created %d threads\n", i);
    return 0;
}

