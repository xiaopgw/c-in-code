#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define N 32

// char arr[N] = {0};
// char flag = 0;
// sem_t sem = {0};

// void *myp(void *arg)
// {
//     while (1)
//     {
//         // if (flag == 1)
//         // {
//             sem_wait (&sem);
//             if (!strcmp(arr, "quit"))
//                 break;
//             printf("%s\n", arr);

//             // flag = 0;
//         // }
//     }
//     return NULL;
// }

// int main(int argc, char const *argv[])
// {
//     if (sem_init(&sem, 0, 1) < 0)
//     {
//         perror("si->");
//         return -1;
//     }

//     pthread_t pid;
//     if (pthread_create(&pid, NULL, myp, NULL) != 0)
//     {
//         perror("pth->");
//         return -1;
//     }
//     while (1)
//     {
//         scanf("%s", arr);
//         sem_post (&sem);
//         // flag = 1;
//         if (!strcmp(arr, "quit"))
//             break;
//     }
//     pthread_join(pid, NULL);

// }

int ar[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
pthread_mutex_t lock;
pthread_cond_t cond, cond0;
int flag = 0;



void *first(void *arg)
{
    int t;
    while(1)
    {
        // sleep(2);
        pthread_mutex_lock(&lock);
        // if (flag == 1)
        // {
            // pthread_cond_wait(&cond0, &lock);
        // }
        for (int i = 0; i < 5; i++)
        {
            t = ar[i];
            ar[i] = ar[9 - i];
            ar[9 - i] = t;
        }
        // flag = 1;
        // 产生条件变量
        // pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
}
void *second(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        // 等待条件变量产生
        // if (flag == 0)
        // {
            // pthread_cond_wait(&cond, &lock);
        // }
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", ar[i]);
        }
        putchar(10);
        // flag = 0;
        // pthread_cond_signal(&cond0);
        pthread_mutex_unlock(&lock);
        
        sleep(1);
    }
}
int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    
    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("X->");
        return -1;
    }
    if (pthread_create(&t1, NULL, first, NULL) != 0)
    {
        perror("X->");
        return -1;
    }
    if (pthread_create(&t2, NULL, second, NULL) != 0)
    {
        perror("X->");
        return -1;
    }
    
    // if(pthread_cond_init(&cond, NULL) != 0);
    // {
    //     perror("X->");
    //     return -1;
    // }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
