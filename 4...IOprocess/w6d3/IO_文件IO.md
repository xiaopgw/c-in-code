# 文件IO
## 开关读写
### 关
```c
#include <unistd.h>
int close (int fd);
参数：fd：文件描述符
```
### 读写文件
read write
```c
#include <unistd.h>
    ssize_t read(int fd, void *buf, size_t count);
功能：从一个打开的可读文件中读取数据
参数：  fd：文件描述符
        buf：存放位置
        count：期望个数
返回值：成功：实际读到的个数
        返回-1：表示出错：并设置errno号
        返回 0：表示读到文件结尾

    ssize_t write(int fd, const void *buf, size_t count);
功能：向指定文件描述符中，写入count个字节的数据。
参数：  fd：文件描述符
        buf：要写的内容
        count：期望值
返回值：成功：实际写入数据的个数
        失败：-1
```
补充：diff  文件1   文件2：比较两个文件是否相同
（命令：完全相同的话是没有任何输出的，有不同的地方它会把不同的地方列出来）

## 定位操作
lseek
```c
# include <sys/typea.h>
# include <unistd.h>
    off_t lseek(int fd, off_t offset, int whence);
功能：设置文件的偏移位置
参数：  fd：文件描述符
        offset：偏移量
            正数：向文件结尾位置移动
            负数：向文件开始位置移动
        whence：相对位置
            SEEK_SET：开始位置      // 0
            SEEK_CUR：当前位置      // 1
            SEEK_END：结尾位置      // 2
返回值：成功：文件的当前位置
        失败：-1
```

标准IO	
概念	
在C库中定义的一组输入输出的函数
特点	
1.有缓冲区，减少系统调用，提高效率
2.围绕流操作，FILE *
3.默认打开三个流：stdin\stdout\stderr
4.只操作普通文件
5.可移植性相对较好	
函数	
打开文件：fopen\freopen
关闭文件：fclose
读写文件：fgetc/fputc fgets/fputs fread/fwrite
文件定位：fseek/rewind/ftell

文件IO
概念
在posix中定义的一组输入输出的函数
特点
1.无缓冲区，每次操作都引起系统调用
2.围绕文件描述符操作
3.默认打开三个文件描述符：0\1\2
4.除目录外其他文件
5.可移植性相对较弱
函数
打开文件：open
关闭文件：close
读写文件：read/write
文件定位：lseek

# 库
当使用别人的函数时除了包含头文件以外还要有库
## 静态库的制作
1. 将源文件

## 动态库的制作
1. 用gcc创建共享库
    gcc -fPIC -c xxx.c -o xxx.o
        -fPIC 创建与地址无关的编译程序
    gcc -shared -o libxxx.so xxx.o xxx.o
2. 测试使用动态库：
    gcc xxx.c -L. -l 指定库