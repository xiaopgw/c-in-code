#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define N 32
char arr[N] = {};
void *first(void *arg);
void *second(void *arg);
void *third(void *arg)
{

}

int main(int argc, char const *argv[])
{
    scanf("%s", arr);
    pthread_t pt1, pt2, pt3;
    int pc = pthread_create(&pt1, NULL, first, NULL);

}
