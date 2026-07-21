# day2
# 1.TCP代码优化
1. 端口和ip地址通过命令行传参到代码中。
2. 设置客户端退出，服务器结束循环接收(通过recv返回值为0判断客户端是否退出)
3. 设置服务器端自动获取自己的ip地址。
	INADDR_ANY  或者 "0.0.0.0"
4. 去掉fgets获取的多余的'\n'.
if(buf[strlen(buf)-1]=='\n')	//去掉fgets获取的'\n'
buf[strlen(buf)-1]='\0';
5. 实现循环服务器，服务器不退出，当链接服务器的客户端退出，服务器等到下一个客户端链接。
6. 设置来电显示功能，获取到请求链接服务器的客户端的ip和端口。
# 2. UDP 编程
## 2.1. 编程流程
![alt text](<1  1.png>)
```c
udp流程：(类似发短信)
server:
创建数据报套接字（socket(,SOCK_DGRAM,)）----->有手机
绑定网络信息（bind()）---------------------->绑定号码（发短信知道发给谁）
接收信息（recvfrom()）--------------------->接收短信
关闭套接字（close()）----------------------->接收完毕
 
client:
创建数据报套接字(socket())----------------------->有手机
指定服务器的网络信息------------------------------>有对方号码
发送信息（sendto()）---------------------------->发送短信
关闭套接字（close()）--------------------------->发送完

```
## 2.2. 函数接口
```c
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
功能：接收数据
参数：
	sockfd：套接字描述符
	buf:接收缓存区的首地址
	len：接收缓存区的大小
	flags：0
	src_addr:发送端的网络信息结构体的指针
	addrlen：发送端的网络信息结构体的大小的指针
返回值：
	成功接收的字节个数
	失败：-1
	

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
功能：发送数据

参数：
	sockfd：套接字描述符
	buf:发送缓存区的首地址
	len：发送缓存区的大小
	flags：0
	src_addr:接收端的网络信息结构体的指针
	addrlen：接收端的网络信息结构体的大小
 
返回值： 
	成功发送的字节个数
	失败：-1

```
### 注意：
1.对于TCP是先运行服务器，客户端才能运行。
2.对于UDP来说，服务器和客户端运行顺序没有先后，因为是无连接，所以服务器和客户端谁先开始，没有关系。
3.一个服务器可以同时连接多个客户端。想知道是哪个客户端登录，可以在服务器代码里面打印IP和端口号。
4.UDP，客户端当使用send的时候，上面需要加connect，这个connect不是代表连接的作用，而是指定客户端即将要发送给谁数据。这样就不需要使用sendto而用send就可以。
5.在TCP里面，也可以使用recvfrom和sendto，使用的时候将后面的两个参数都写为NULL就OK。

# setsockopt
linux中socket属性
![alt text](<image (3).jpg>)
```c
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 
int setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen)
 
功能：设置套接字属性
 参数：
	sockfd：套接字描述符 (指定要设置/获取哪个套接字的属性)
	level：协议层 (指定要控制的协议层次)
		SOL_SOCKET（应用层） 通用套接字选项;  
		IPPROTO_TCP（传输层）
		IPPROTO_IP（网络层） 
	optname：选项名(指定要控制的内容，指定控制方式)
     
 --- SOL_SOCKET: man 7 socket -----
       
        SO_REUSEADDR：允许端口快速重用            int*
		SO_BROADCAST     允许发送广播数据          int 
		SO_RCVBUF       接收缓冲区大小              int 
		SO_SNDBUF       发送缓冲区大小              int 
		SO_RCVTIMEO      接收超时                 struct timeval 
		SO_SNDTIMEO      发送超时                 struct timeval
		
	void *optval：根据optname不同，该类型不同;
    socklen_t optlen/socklen_t *optlen：真实的optval指针指向的内存空间的大小;
    
返回值：
    成功，返回0；
    失败，返回-1，更新errno;

```

# 3.广播
## 3.1. 概念
前面介绍的数据包发送方式只有一个接受方，称为单播
1. 如果同时发给局域网中的所有主机，称为广播
2. 只有用户数据报(使用UDP协议)套接字才能广播
3. 一般被设计成局域网搜索协议
4. 广播地址：
   4. 1. 以192.168.1.0 (255.255.255.0) 网段为例，最大的主机地址192.168.1.255代表该网段的广播地址
   4. 2. 发到该地址的数据包被所有的主机接收

## 3.2. 广播发送流程
1. 创建套接字
2. 填充结构体信息（IP：广播地址）
3. 允许发送广播数据
int opt = 1;
setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));
4. 发送数据
5. 关闭
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 1. 创建数据报套接字
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket err");
        return -1;
    }

    // 2. 填充服务器结构体信息
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;                          // 协议族
    saddr.sin_port = htons(8080);                        // 端口号(网络字节序)
    saddr.sin_addr.s_addr = inet_addr("192.168.50.255"); // IP地址(32位无符号整数)

    socklen_t len = sizeof(saddr);

    // 3. 允许发送广播数据
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));

    // 4. 发送数据
    char buf[32] = {};
    while (1)
    {
        fgets(buf, sizeof(buf), stdin);
        if (buf[strlen(buf) - 1] == '\n') // 去掉\n
            buf[strlen(buf) - 1] = '\0';
            
        sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&saddr, len);
        printf("send ok\n");
    }

    // 5. 关闭
    close(sockfd);

    return 0;
}

```
## 3.3. 广播接收流程
1. 创建数据报套接字
2. 填充结构体信息（广播IP）
3. 绑定
4. 接收
5. 关闭
int opt = 1;
setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));
4. 发送数据
5. 关闭
## 3.3. 广播接收流程
1. 创建数据报套接字
2. 填充结构体信息（广播IP）
3. 绑定
4. 接收
5. 关闭
# 4.组播
## 4.1. 概念
● 单播方式只能发给一个接收方。
● 广播方式发给所有的主机。过多的广播会大量占用网络带宽，造成广播风暴，影响正常的通信。
● 组播是一个人发送，加入到多播组的人接收数据。
● 多播方式既可以发给多个主机，又能避免象广播那样带来过多的负载(每台主机要到传输层才能判断广播包是否要处理)

## 4.2. 组播地址
不分网络地址和主机地址，第1字节的前4位固定为1110 。是D类IP
224.0.0.1~~239.255.255.255

224.0.0.0～224.0.0.255为预留的组播地址（永久组地址），地址224.0.0.0保留不做分配，其它地址供路由协议使用
224.0.1.0～224.0.1.255是公用组播地址，可以用于Internet
224.0.2.0～238.255.255.255为用户可用的组播地址（临时组地址），全网范围内有效
239.0.0.0～239.255.255.255为本地管理组播地址，仅在特定的本地范围内有效
## 4.3. 组播发送流程
1. 创建用户数据报套接字
2. 填充结构体（组播IP）
3. 发送
4. 关闭
## 4.4. 组播接收流程
1. 创建用户数据报套接字
2. 填充结构体（组播IP）
3. 绑定
4. 加入多播组
5. 等待接收数据
# 5.服务器模型
1) 在网络程序里面,通常都是一个服务器处理多个客户机。
2) 为了处理多个客户机的请求, 服务器端的程序有不同的处理方式。
## 5.1. 循环服务器模型
同一个时刻只能响应一个客户端的请求，伪代码如下
```c
socket(); // 创建
bind();  // 绑定
listen(); // 监听
while(1)
{
    accept();  // 连接
    while(1)
    {
        // 处理数据
    }
    close();
}
close();

```
## 5.2. 并发服务器模型
同一个时刻可以响应多个客户端的请求，常用的模型有多进程模型/多线程模型/IO多路复用模型。

### 5.2.1. 多进程模型
每来一个客户端连接，开一个子进程来专门处理客户端的数据，实现简单，但是系统开销相对较大，更推荐使用线程模型。伪代码如下：
```c
socket(); // 创建
bind();  // 绑定
listen(); // 监听
while(1)
{
    accept();  // 连接
    if(fork() == 0)
    {
        while(1)
        {
            // 处理数据
        }
        close();
        exit();
    }
}
close();

```
### 5.2.2. 多线程模型(重点)
每来一个客户端连接，开一个子线程来专门处理客户端的数据，实现简单，占用资源较少，属于使用比较广泛的模型：
```c
socket(); // 创建
bind();  // 绑定
listen(); // 监听
while(1)
{
    accept();  // 连接
    pthread_create();
}
close();

```
