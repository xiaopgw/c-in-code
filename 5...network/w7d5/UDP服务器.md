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