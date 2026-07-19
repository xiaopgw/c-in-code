#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/errno.h>
// #include <sys/type.h>

#define N 32

void deng();

int main(int argc, char const *argv[])
{

    // 共享内存
    // 信号灯集
    // 创key
    key_t key = 0;
    key = ftok("test", 51);
    if (key < 0)
    {
        perror("key->");
        return -1;
    }
    // 开辟共享空间
    int shmid = 0;
    shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0765);
    // 开辟信号空间
    int semid = 0;
    semid = semget(key, 3, IPC_CREAT | IPC_EXCL | 0765);
    // 映射
    char *shmp = 0;
    shmp = shmat(shmid, NULL, 0);
    // 用父子进程模拟两个进程
    int fs = fork();
    // 用信号灯同步映射
    if (fs < 0)
    {
        perror("fs->");
        return -1;
    }
    else if(fs > 0)
    {

    }
    else
    {

    }
    
    // 删除映射
    // 成功实现后删除共享空间
    // 删除信号
    

    return 0;
}
