#include <stdio.h>
#include <modbus.h>
#include <pthread.h>

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
    if (modbus_new_rtu("/dev/ttyS1", baud, 'N', 8, 1) == NULL)
        return -1;
    // 设置从机ID
    if (modbus_set_slave(modb, ID) < 0)
        return -1;
    // 和从机建立连接
    if (modbus_connect(modb))
        return -1;
    // 这里用多线程，分两个线程，一个线程跑寄存器的请求
    pthread_t ptcoil, pthold;
    pthread_create(&ptcoil, NULL, hold, modb);
    // 一个线程跑线圈控制
    pthread_create(&pthold, NULL, coil, modb);
    // 回收线程
    pthread_join(ptcoil, NULL);
    pthread_join(pthold, NULL);
    // 最后关闭释放
    modbus_close(modb);
    modbus_free(modb);
    return 0;
}
void *hold(void *arg)
{
    modbus_t *modb = arg;
    uint16_t arr[N];
    // 读取保持寄存器的值，其中第一个值为光线传感器，234分别是加速度传感器的xyz
    modbus_read_registers(modb, 0, 4, arr);
    printf("光线%d, 加速度x:%d, y:%d, z:%d\n", arr[0], arr[1], arr[2], arr[3]);

}
void *coil(void *arg)
{
    modbus_t *modb = arg;
    uint16_t arr[N];

}