#include <stdio.h>
#include <modbus.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define baud 9600
#define N 64

void *coil(void *modb);
void *hold(void *modb);

typedef enum coilen
{
    LED,
    BUZ
} ec;

int main(int argc, char const *argv[])
{
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
        printf("modbus_connect");
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
        uint16_t arr[N];
        // 读取保持寄存器的值，其中第一个值为光线传感器，234分别是加速度传感器的xyz
        modbus_read_registers(modb, 0, 4, arr);
        printf("光线%d, 加速度x:%d, y:%d, z:%d\n", arr[0], arr[1], arr[2], arr[3]);
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
        scanf("%d %d", &type, &state);
        switch (type)
        {
        case LED:
            modbus_write_bit(modb, type, state);
            modbus_read_bits(modb, type, 1, statesla);
            printf("LED: 状态%d\n", statesla[0] & 0x01);
            break;
        case BUZ:
            modbus_write_bit(modb, type, state);
            modbus_read_bits(modb, type, 1, statesla);
            printf("BUZ: 状态%d\n", statesla[0]& 1);
            break;
        }
    }
}