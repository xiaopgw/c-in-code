#include <stdio.h>
#include <modbus.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/sem.h>

#define baud 9600
#define N 64
#define P -1
#define V 1


void *coil(void *modb);
void *hold(void *modb);
key_t keyWebsever();
int shmWebSever(key_t key);
int semWebSevser(key_t key);
void sem_op(int semid, int num, int op);

typedef struct shm_struct
{
    int coil;
    int value;
    int hold[4];
} sshm, pshm;

enum e_coil
{
    LED,
    BUZ
};
enum e_sem
{
    sem1,
    sem2,
    sem3,
    sem4
};

union semun
{
    int val;
};

sshm *shmdata = NULL;
int semid = 0;



int main(int argc, char const *argv[])
{
    key_t key = keyWebsever();
    shmWebSever(key);
    semWebSevser(key);

    int ID = 1;
    // modbus编程
    // 同时控制蜂鸣器和led灯以及每秒显示一次四个传感器的信息
    // 其中四个传感器是用保存寄存器请求和访问
    // 两个设备是用线圈控制
    // 要实现需要多任务编程，父子进程/多线程/IO多路混合复用
    // 创建modbus实例
    modbus_t *modb;
    // printf("1\n");
    modb = modbus_new_rtu("/dev/ttyS1", baud, 'N', 8, 1);
    if (modb == NULL)
    {
        printf("modbus_new_rtu");
        return -1;
    }
    // 设置从机ID
    if (modbus_set_slave(modb, ID) < 0)
    {
        printf("modbus_set_slave");
        return -1;
    } // 和从机建立连接
    if (modbus_connect(modb) < 0)
    {
        fprintf(stderr, "Modbus connect failed: %s\n", modbus_strerror(errno));
    // 注意：modbus_strerror(errno) 会返回具体的错误描述
    modbus_free(modb);
        return -1;
    }
    // 这里用多线程，分两个线程，一个线程跑寄存器的请求
    pthread_t ptcoil, pthold;
    // printf("1\n");
    pthread_create(&pthold, NULL, hold, modb);
    // 一个线程跑线圈控制
    pthread_create(&ptcoil, NULL, coil, modb);
    // 回收线程

    pthread_join(pthold, NULL);
    pthread_join(ptcoil, NULL);

    // 最后关闭释放
    modbus_close(modb);
    modbus_free(modb);
    return 0;
}
void *hold(void *arg)
{
    while (1)
    {
        modbus_t *modb = arg;
        uint16_t arr[N] = {};
        // sem_op(semid, sem1, P);
        // 读取保持寄存器的值，其中第一个值为光线传感器，234分别是加速度传感器的xyz
        modbus_read_registers(modb, 0, 4, arr);
        printf("光线%d, 加速度x:%d, y:%d, z:%d\n", arr[0], arr[1], arr[2], arr[3]);
        for (int i = 0; i < 4; i++)
        {
            shmdata->hold[i] = arr[i];
        }
        // sem_op(semid, sem2, V);
        sleep(1);
    }
}
void *coil(void *arg)
{
    while (1)
    {
        modbus_t *modb = arg;
        uint16_t arr[N];
        int type, state;
        uint8_t statesla[1];
        // printf("这里应该阻塞\n");
        sem_op(semid, sem3, P);

        // printf("没错这里不该显示\n");
        
        // scanf("%d %d", &type, &state);
        switch (type)
        {
        case LED:
            modbus_write_bit(modb, type, state);
            modbus_read_bits(modb, type, 1, statesla);
            // shmdata->led = statesla[0] & 0x01;
            sem_op(semid, sem4, V);
            // printf("%c\n", shmdata->led);
            break;
        case BUZ:
            modbus_write_bit(modb, type, state);
            modbus_read_bits(modb, type, 1, statesla);
            // shmdata->buz = statesla[0] & 1;
            sem_op(semid, sem4, V);
            // printf("%c\n", shmdata->buz);
            break;
        }
    }
}

// 创key
key_t keyWebsever()
{
    // key
    key_t key;
    key = ftok("work.c", N);
}
// 共享内存
int shmWebSever(key_t key)
{
    // 创建共享内存相关

    int shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0765);
    if (shmid < 0)
    {
        if (errno == EEXIST)
        {
            shmid = shmget(key, 0, 0765);
        }
        else
        {
            perror("shmid->");
            return -1;
        }
    }

    void *shmp = shmat(shmid, NULL, 0);
    if (shmp == (void *)-1)
    {
        perror("shmat->");
        return -1;
    }
    // 共享内存内的结构体
    shmdata = shmp;
}
// 信号灯集
int semWebSevser(key_t key)
{
    // 信号灯控制
    semid = semget(key, 4, IPC_CREAT | IPC_EXCL | 0765);
    if (semid < 0)
    {
        if (errno == EEXIST)
        {
            semid = semget(key, 0, 0765);
        }
        else
        {
            perror("semid->");
            return -1;
        }
    }
    // 初始化
    union semun sem;
    sem.val = 0;
    int semc = semctl(semid, 2, SETVAL, sem);
    int semc = semctl(semid, 3, SETVAL, sem);
    if (semc < 0)
    {
        perror("semc->");
        return -1;
    }
}
// pv操作
void sem_op(int semid, int num, int op)
{
    struct sembuf buf;
    buf.sem_num = num;
    buf.sem_op = op;
    buf.sem_flg = 0;
    
    semop(semid, &buf, 1);
}
