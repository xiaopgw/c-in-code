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
    gcc xxx.c -l 指定库

## 静态库的制作
1-将源文件编译成目标文件
gcc  -c  xxx.c  -o  xxx.o
2-创建静态库用 ar 命令，它将很多.o转换成.a
	ar  crs  libxxx.a  xxx.o  xxx.o ...
静态库文件名的命名规范是以lib为前缀，紧接着跟静态库名，扩展名为.a
3-测试使用静态库：
gcc xxx.c  -L.  -l指定库名      // -L指定库的路径  -l指定库名



## 动态库的制作
1. 我们用gcc来创建共享库
	gcc  -fPIC  -c   xxx.c  -o  xxx.o
		-fPIC 创建与地址无关的编译程序
	gcc  -shared  -o  libxxx.so  xxx.o  xxx.o ...
2. 测试使用动态库：
gcc xxx.c  -L.  -l指定库名

可以正常编译通过，但是运行时报错./a.out: error while loading shared libraries: libmyadd.so: cannot open shared object file: No such file or directory
原因：当加载动态库时，系统会默认从/lib或/usr/lib路径下查找库文件，所以不用加-L指定路径了，直接gcc main.c -lmydynamic就可以了。

解决方法
1) 把库拷贝到/usr/lib和/lib目录下。(此方法编译时不需要指定库的路径) 



补充：
-L路径：指定库的路径
-l库名：指定链接的库名
-I(大写i) 路径：指定头文件的路径 默认查找的路径/usr/include
<> 代表从系统路径下查找
"" 代表从当前路径下查找如果没有再去系统路径下查找
ldd 可执行文件名：查看链接的动态库

补充：
同名的静态库和动态库：默认优先使用动态库，如果想使用静态库 需要在后面加 -static，这是内核规定的。
如果链接没有lib前缀的库文件，可以直接用-指定库的全名无需加l选项。

## 总结静态库和动态库
静态库：编译阶段，以.a结尾，执行速度快，体积大，移植性好，升级麻烦。
动态库：运行阶段，以.so结尾，执行速度慢，体积小，移植性差，升级简单。
# Linux IO 模型
## 阻塞IO
最常见、效率低、不浪费CPU
```
阻塞I/O 模式是最普遍使用的I/O 模式，大部分程序使用的都是阻塞模式的I/O 。
学习的读写函数在调用过程中会发生阻塞相关函数如下：
•读操作中的read
读阻塞--》需要读缓冲区中有数据可读，读阻塞解除
•写操作中的write
写阻塞--》阻塞情况比较少，主要发生在写入的缓冲区的大小小于要写入的数据量的情况下，写操作不进行任何拷贝工作，将发生阻塞，一旦缓冲区有足够的空间，内核将唤醒进程，将数据从用户缓冲区拷贝到相应的发送数据缓冲区。
```
## 非阻塞IO
轮询、耗费CPU、可以同时处理多路IO
```
•当我们设置为非阻塞模式，我们相当于告诉了系统内核：“当我请求的I/O 操作不能够马上完成，你想让我的进程进行休眠等待的时候，不要这么做，请马上返回一个错误给我。”
•当一个应用程序使用了非阻塞模式的套接字，它需要使用一个循环来不停地测试是否一个文件描述符有数据可读（称做polling）。
•应用程序不停的polling 内核来检查是否I/O操作已经就绪。这将是一个极浪费CPU 资源的操作。
•这种模式使用中不普遍。
```
int fp = fcntl(0, F_GETFL);
fcntl(0, F_SETFL, fp | O_NONBLOCK);
fcntl(0, F_SETFL, fp & ~O_NONBLOCK);
## 信号驱动IO
异步通知：异步通知是一种非阻塞的通知机制，发送方发送通知后不需要等待接收方的响应或确认。通知发送后，发送方可以继续执行其他操作，而无需等待接收方处理通知。
1. 通过信号方式，当内核检测到设备数据后，会主动给应用发送信号SIGIO。
2. 应用程序收到信号后做异步处理即可。
3. 应用程序需要把自己的进程号告诉内核，并打开异步通知机制。

## IO多路复用



如果我对这个终端设置了非阻塞，那我其他终端会受影响吗
用软硬连接呢
不同文件呢
head读取的行数有上限吗，我的是int的最大值行