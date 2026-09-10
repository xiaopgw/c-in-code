#include <stdio.h>
#include "Crc_Calc.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // 打开串口1
    int fd = open("/dev/ttyS1", O_RDWR);
    if (fd < 0)
    {
        perror("fd->");
        return -1;
    }
    // 初始化
    uart_init(fd);
    
    
    // 设置协议格式
    uint8_t req[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, };
    uint8_t data[8] = {0};
    // 准备协议CRC
    uint16_t crc;
    crc = GetCRC16(req, 6);
    req[6] = crc >> 8;
    req[7] = crc;
    // 把协议发出去
    write(fd, req, 8);
    // 读取发回的消息
    read(fd, data, 32);
    for (int i = 0; i < 7; i++)
    {
        printf("%02X ", data[i]);
    }
    putchar(10);
    return 0;
}
