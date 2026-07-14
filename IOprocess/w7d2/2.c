#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int len = sizeof(arr) / sizeof(arr[0]);
pthread_t t1, t2;
pthread_mutex_t lock;
pthread_cond_t cond;
int flag = 0;

void *first(void *arg)
{
    while (1)
    {

        pthread_mutex_lock(&lock);
        if (flag == 0)
        {
            pthread_cond_wait(&cond, &lock);
        }
        for (int i = 0; i < len / 2; i++)
        {
            int t = arr[i];
            arr[i] = arr[len - 1 - i];
            arr[len - 1 - i] = t;
        }
        pthread_mutex_unlock(&lock);
        flag == 1;
        pthread_cond_signal(&cond);
    }
}
void *second(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        if (flag == 1)
        {
            pthread_cond_wait(&cond, &lock);
        }
        for (int i = 0; i < len; i++)
        {
            printf("%d ", arr[i]);
        }
        putchar(10);
        pthread_mutex_unlock(&lock);
        flag == 0;
        pthread_cond_signal(&cond);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    // 创建线程
    // 创建互斥锁
    // 建立条件变量
    // 我要做到这里反转数组，然后旁边就输出的形式，用线程实现，
    // 所以要创建两个线程，这时两个线程就是相当于两个不同的
    // 然后我要分辨让两个线程跑起来，然后让他们给cpu调度
    // 然后1用来反转，2用来遍历，1反转循环开始时要建立一个锁
    // 把1锁住，然后这个锁为啥是条件变量的锁呢
    // 然后让2遍历完再解开1的锁
    // 哦，还有个锁是互斥锁的锁，给1循环开始前锁上，以防1代码跑一半
    // 时间片不够，过去跑2了,所以用互斥锁锁住,只让1访问临界资源
    // 当然这有可能先访问2,但也就是先顺序打印而已
    // 但是现在也只是让可以反转了,就是可以相互转换的可能了,但不能
    // 同步转换,
    // 所以用条件变量同步转换, 条件变量可以当我实现完1,然后给一条
    // 信息,让2线程继续走,然后当2线程实现完,让1线程继续走,但这时候
    // 还有个问题,我们是死循环,所以还是会不断反转数组,当走完时间片
    // 到2的时候都不知道反转多少次了,同时2也不知道打印多少次了,所以2
    // 得有个sleep让他1秒打印一次,然后把2打印次数先解决,然后利用全局变量
    // if判断,让循环只执行一次.

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("X->");
        return -1;
    }
    if (pthread_cond_init(&cond, NULL) != 0)
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
    // 回收函数
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
