// 以下是修正后的完整代码。你直接把 `IOprocess/w7d2/main.c` 的内容替换成这个就行。如果需要我帮你写到文件里，切换到 ACT MODE 即可。

// ```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ar[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int data_ready = 0;   // 0: first 可以生产, 1: second 可以消费
int running = 1;      // 控制循环退出

void *first(void *arg)
{
    while (running)
    {
        pthread_mutex_lock(&lock);

        // 翻转数组（生产数据）
        for (int i = 0; i < 5; i++)
        {
            int t = ar[i];
            ar[i] = ar[9 - i];
            ar[9 - i] = t;
        }

        // 通知 second：数据就绪
        data_ready = 1;
        pthread_cond_signal(&cond);

        // 等待 second 消费完毕
        while (data_ready == 1 && running)
        {
            pthread_cond_wait(&cond, &lock);
        }

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *second(void *arg)
{
    while (running)
    {
        pthread_mutex_lock(&lock);

        // 等待 first 生产数据
        while (data_ready == 0 && running)
        {
            pthread_cond_wait(&cond, &lock);
        }

        if (!running)
        {
            pthread_mutex_unlock(&lock);
            break;
        }

        // 消费数据：打印数组
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", ar[i]);
        }
        putchar('\n');

        // 消费完毕，通知 first 继续
        data_ready = 0;
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&lock);

        sleep(1);  // 控制输出节奏
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;

    // 注意：互斥锁和条件变量用 PTHREAD_*_INITIALIZER 静态初始化了，
    // 这里不需要再调用 pthread_mutex_init / pthread_cond_init

    if (pthread_create(&t1, NULL, first, NULL) != 0)
    {
        perror("pthread_create t1");
        return -1;
    }
    if (pthread_create(&t2, NULL, second, NULL) != 0)
    {
        perror("pthread_create t2");
        return -1;
    }

    // 运行 5 秒后退出（或按你的需求调整）
    sleep(50);

    // 通知两个线程退出
    pthread_mutex_lock(&lock);
    running = 0;
    pthread_cond_broadcast(&cond);  // 唤醒所有等待的线程
    pthread_mutex_unlock(&lock);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
// ```

// ---

// ## 关键改动说明

// | 改动项 | 说明 |
// |--------|------|
// | 初始化放到 create 前面 | 用 `PTHREAD_MUTEX_INITIALIZER` 静态初始化，create 之前已经可用 |
// | `&t1` / `&t2` 分开 | 两个线程 ID 分别保存，join 时也分别 join |
// | 加入 `data_ready` 标志 | 0 = first 可以生产，1 = second 可以消费 |
// | wait 放在 while 循环里 | 防止假唤醒（spurious wakeup），这是 pthread 标准要求的写法 |
// | first 生产后等 second 消费 | first 设 data_ready=1 后 wait 等待 second 清零，实现严格的交替执行 |
// | 用 `running` 控制退出 | main 线程 sleep(5) 后设 running=0 + broadcast 唤醒，两个线程安全退出 |
// | `putchar('\n')` | 替代 `putchar(10)`，语义更清晰 |

// 编译时需要链接 pthread 库：

// ```bash
// gcc main.c -o main -lpthread
// ```