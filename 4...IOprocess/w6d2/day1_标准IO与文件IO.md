# 大纲
## IO：input(输入)、output(输出)
标准IO
文件IO
库
LinuxIO模型

（字符串输入输出gets，puts会有越界风险，但io会学一个不会越界的方法来输入输出）
## 进程：process
进程基础
进程间通信：无名管道(pipe)、有名管道(fifo)、信号(signal)、共享内存(shard memory)、消息队列(message queue)、信号灯集(semaphore set)
线程、同步、互斥、条件变量

# 函数三要素
功能：
参数：
返回值：

# 什么是标准IO
## 概念
标准IO：在C库中定义的一组专门用来输入输出的函数

系统分三层：应用层，内核层，硬件
## 特点
1. 通过缓冲机制减少系统的调用，提高效率
系统调用：内核向上提供的一组接口
2. 围绕流进行操作，流FILE*描述，FILE代表的是结构体
3. 默认打开三个流：stdin(标准输入)、stdout(标准输出)、stderr(标准错误)

## 操作
打开文件：fopen
关闭文件：fclose
读写操作：fgets、fputs、fread、fwrite
定位操作：rewind、fseek、ftell

# 缓冲区
(一旦进行输入输出就产生缓存区)
1. 全缓存：和文件相关
    刷新条件：
        缓存区满
        程序正常退出
        强制刷新：fflush(NULL);  <!-- 那这个文件相关的怎么看呢 -->

2. 行缓存：和终端相关
    刷新条件：
        缓存区满
        程序正常退出
        强制刷新：fflush(NULL);
        \n

3. 不缓存：标准错误

# 函数接口
## 打开文件fopen

```c
#include <stdio.h>
    FILE *fopen(const char *pathname, const char *mode);
功能：打开文件
参数：pathname：打开的文件路径
      mode：打开方式
        r:只读，顶到开头
        w:只写，存在清空，不存在创建，顶到开头
        a:追加，不存在创建，存在顶到结尾
        r+:可读可写，顶到开头
        w+:可读可写，存在清空，不存在创建，顶到开头
        a+:可读可写，不存在创建，存在写顶到结尾，读顶到开头
返回值：成功：文件流
        失败：NULL, 并且设置errno(错误码)
                                （也就是说可以用perror打印）
(对'流'的操作)
```

## 关闭文件fclose
```c
#include <stdio.h>
    int fclos(FILE *stream);
功能：关闭文件
参数：stream：文件流
```

## 读写文件操作
### fgets、fputs

每次读写一个字符串

```c
#include <stdio.h>
    char *fgets(char *s, int size, FILE *stream);
功能：从文件中读取一个字符串
参数：  s：存放读取的字符串首地址
        size：要读取多少个字节
        stream：文件流
返回值：成功：读取的字符串首地址
        失败或读到文件末尾：NULL        // 为什么不是只失败
特性：1. 一次调用最多读取一行数据，遇到\n或到末尾不再继续
      2. 实际读到个数为size-1个，结尾自动添加\0
    
#include <stdio.h>
    int fputs(const char *s, FILE *stream);
功能：像文件中写一个字符串
参数：s：要写入的内容
      stream：文件流
返回值：成功：非负整数
        失败：EOF
```
### fread、fwrite

二进制读写

```c
#include<stdio.h>
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
功能：从文件读取多个元素(将二进制数据从文件读出)
参数：  ptr：存放读取的元素
        size：读出元素字节大小
        nmemb：元素个数
        stream：文件流
返回值：成功：读取元素个数
        失败或读取到文件尾：0


#include<stdio.h>
    size_t fwrite(const void*ptr, size_t size, size_t nmemb,FILE *stream);
功能：将二进制数据写入文件
参数：  ptr：要输出数据的空间的地址
        size：写入的元素的字节大小
        nmemb：写入元素的个数
        stream：目标文件流指针
返回值：成功：写元素的个数
        失败：-1
```
## 文件定位操作
### rewind
void rewind(FILE* stream);
功能：将文件的位置指针定位到起始位置
### fseek
```c
int fseek(FILE *stream, long offset, int whence);
功能：文件的定位操作
参数：stream：文件流
     offset：偏移量：正数往前后，负数往前
     whence：相对位置：
         SEEK_SET:相对于文件开头        // 0
         SEEK_CUR:相对于文件当前位置    // 1
         SEEK_END:相对于文件末尾        // 2
返回值：成功：0
       失败：-1

如果是追加模式跟fseek无关
```

### ftell

long ftell(FILE *stream)
功能：获取当前的文件位置
参数：要检测的文件流
返回值：成功：当前的文件位置            <!-- 什么类型呢 -->
       失败：-1

# 文件IO
## 概念
又称系统IO，是系统调用，是操作系统提供的函数接口
在posix(可移植操作系统接口)中定义的一组输入输出的函数
## 特点
没有缓冲机制，每次操作都会经过系统调用，效率比较低
围绕文件描述符进行操作，文件描述符是非负整数：0、1、2
默认打开三个文件描述符：0(标准错误)、1(标准输出)、2(标准错误)
除目录外其他类型的文件都可以操作(功能更丰富，标准io只能操作普通文件)
 
问题：打开一个文件，文件描述符：
3
关闭3以后，重新打开文件，描述符是几？
3
一个进程的文件描述符最大到几？最多能打开多少个文件描述符？最多能打开多少个文件？
答：0~1023      1024        1024 - 3 = 1021
## 操作
打开文件：open
关闭文件：close
读写文件：read、write
定位操作：lseek
## 函数接口
### 打开文件open
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
功能：打开文件
参数：pathname：文件路径名
      flags：打开方式
        O_RDONLY：只读
        O_WRONLY：只写
        O_RDWR：可读可写
        O_CREAT：不存在创建
        O_TRUNC：清空
        O_APPEND：追加
返回值：成功：文件描述符
        失败：-1
当有O_CREAT时要用
int open(const char *pathname, int flags, mode_t mode);         // 跟上面是同一个
参数：mode：0755(八进制改权限)                                  // 怎么创建跟打开的权限不一样

```

题目要求：编程读写一个文件test.txt，每隔1秒向文件中写入一行数据，类似这样： 
1,  hello  
2,  hello
该程序应该无限循环，直到按Ctrl-C中断程序。
再次启动程序写文件时可以追加到原文件之后，并且序号能够接续上次的序号，比如： 
1,  hello  
2,  hello
3,  hello
4,  hello
5,  hello
sleep(1); //睡眠函数
fprintf/sprintf







