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

int main(int argc, char const *argv[])
{
    int ID = 1;
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
    uint16_t arr[N];
    int type, state;

    uint8_t statesla[2], statesla2;

    modbus_write_bit(modb, type, state);
    modbus_read_bits(modb, 0, 2, statesla);
    printf("%d %d\n", statesla[0], statesla[1]);

    modbus_read_bits(modb, 0, 1, &statesla2);
    printf("%d\n", statesla2);
    modbus_read_bits(modb, 1, 1, &statesla2);
    printf("%d\n", statesla2);
    
    // modbus_read_bits(modb, 1, 1, &statesla);

    modbus_close(modb);
    modbus_free(modb);


    
    return 0;
}
