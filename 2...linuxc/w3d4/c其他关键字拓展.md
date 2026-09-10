# linuxc2
## 内核系统构架
应用层 app shell命令
内核层: 五大功能
    内存管理
    文件管理
    网络管理
    设备管理
    进程管理
驱动层:网络设备驱动,块设备驱动,字符设备管理
硬件层:网卡,键盘
## 关机
sudo shutdown -h now/时间(min)
重启
sudo shutdown -r now/时间(min)
## 网络配置
查看虚拟机是否能联网
    ping www.baidu.com
查看ip地址:
    ifconfig
## Linux下的软甲安装
两种软件包管理机制
debian linux:deb        --ubuntu
redhat linux:rpm
两种软件包的管理工具
dpkg
sudo dpkg -i 软件包完整名称
sudo dpkg -r 软件名：卸载软件
sudo dpkg -s 软件名：查看软件的安装状态
sudo dpkg -L 软件名：列出软件目录信息
apt
sudo apt-get install 软件包名:下载并安装
sudo  apt-get --purge remove 软件包名:卸载软件包
sudo  apt-get update：下载更新软件包列表信息
sudo  apt-get  upgrade:将系统所有软件包升级到最新版本
sudo  apt-get clean:清空安装包的存放路径
## shell基础命令
### alias
alias 查看别名列表
alias 新名字='原名字'
unalias 新名 取消别名
## history
history 查看历史命令
history 10 查看近10条
.bash_history 存放历史命令
.bashrc 配置信息
## echo
向终端输出指定内容
echo hello world     不能输出空格
echo "hello world"   可以输出空格
## 通配符
*
？
[-]
[]
[^]
[[:lower:]]
[[:upper:]]

嵌入式系统(把软件嵌入到硬件里面)
嵌入式系统是以应用为中心，以计算机技术为基础，并且软硬件可裁剪，适用于对功能、可靠性、成本、体积、功耗有严格要求的专用计算机系统。
Linux起源 
https://mp.weixin.qq.com/s?__biz=MzkzNzAwNDAzNQ==&mid=2247483775&idx=1&sn=fc5ab0d0ac067f6605906888b40e05bb&chksm=c2975c13f5e0d505fe3074729088341552275cbfa0f95ff8a0b4627b1003493c1011077e2f89&mpshare=1&scene=23&srcid=0902yXFHTAa1jzL68pTXNIWX&sharer_sharetime=1662117806737&sharer_shareid=b33de6e893f06376514acc7d36a0a351#rd 
1965  麻省理工 贝尔实验室 奇异公司 
	      multics -->满足同时登录300个用户
		  失败--》资金
 1969 汤姆森.肯 (太空旅行游戏) 4个周 unics
	     2个人同时登录使用，汇编语言	
1970 unix  
	 丹尼斯·里奇-->c语言之父
	 贝尔实验室，unics的基础进行二次开发，c语言写，命名为unix 
	 推广--》大学推广
	  两个分支:
	      伯克利分校(TCP/IP)     systemV 
    1983 斯托曼  GNU(自由软件组织)  libc gcc  make  bash解析器
	     GPL 协议--》开源协议	*****   
1991 林纳斯--》linux开源不收费


UNIX和linux的区别：
    1）linux是开发源代码的自由软件．而unix是对源代码实行知识产权保护的传统商业软件。
    2）UNIX系统大多是与硬件配套的，而Linux则可运行在多种硬件平台上.
了解不同操作系统的内核：
    windows  -   NT
    ubuntu    - linux
    Android  - linux
    macOs ios  - unix
查看系统版本
lsb_release -a
	
内核系统架构
应用层  app   shell命令
内核层：五大功能
	内存管理
	文件管理
	网络管理
	设备管理
	进程管理
驱动层：网络设备驱动、块设备驱动、字符设备管理
硬件层：网卡、键盘
系统关机或重启
关机：
	sudo   shutdown  -h  now   立即关机
	sudo  shutdown  -h  时间(min)  "提示语"
重启
	sudo  shutdown  -r  now     立即重启
	sudo  shutdown   -r  时间(min)
网络配置
查看虚拟机是否能联网
	ping  www.baidu.com
	
查看Windows的ip地址：ipconfig
查看Linux的ip地址：ifconfig

虚拟机提供的网络类型
	

如果没有，运行命令：
	sudo  nmcli  network  off
	sudo  nmcli  network  on
配置桥接模式
1）保证虚拟机提供了桥接模式
	菜单栏---》虚拟机---》设置---》网络适配器---》桥接模式
		
		
2）保证虚拟机可以设置桥接模式
 菜单栏---》编辑---》虚拟网络编辑器
		
更改设置(如没有桥接模式)----->添加网络(添加桥接网络)

问题：无法添加桥接网络
1）尝试还原默认设置后，再重新添加桥接网络
2）如果1没有用，找到VMware的软件安装包，双击安装包修改该软件
3）如果1和2都没有用，安装更高版本的VMware 
桥接到主机的网卡

如果自动失败，手动找到主机的网卡
1） 找到网络---->属性

2.描述的位置即是主机的网卡
    
3. 找到主机网卡后，不选自动直接桥接到主机具体的网卡
配置NAT模式
1）编辑->虚拟网络编辑器->选择vmnet8->nat模式->确定。
2）虚拟机->设置->网络适配器->选择nat模式



https://hqyj.yuque.com/ckmklb/bgsx6f/khk4f6?singleDoc# 《虚拟机安装问题汇总》
Linux下的软件安装
两种软件包管理机制
debian linux:deb		---- ubuntu 
redhat linux: rpm

deb软件包：
	二进制软件包  .deb
	源码包		 .dsc


软件包的管理工具  dpkg   apt
dpkg
安装时需要获取软件包，不需要网络，不能检查软件的依赖
命令：
	sudo  dpkg -i  软件包的完整名称
sudo dpkg -r 软件名：卸载软件
sudo dpkg -s 软件名：查看软件的安装状态
sudo dpkg -L 软件名：列出软件目录信息
apt
安装时不需要获取软件包，需要网络，可以检查软件的依赖
https://cloud.tencent.com/developer/article/1535223 
sudo  apt-get  install  软件包名：下载并安装
	sudo  apt-get --purge remove 软件包名:卸载软件包
	sudo  apt-get update：下载更新软件包列表信息
sudo  apt-get  upgrade:将系统所有软件包升级到最新版本
sudo  apt-get clean:清空安装包的存放路径

shell的基础命令
shell是命令解析器
用户在命令行输入命令或按键，经过shell解析成内核能理解的指令，控制操作系统作出响应，进而控制相关硬件，然后再把结果通过shell提交给用户

解析器的分类：
Bourne Shell（简称sh）：Bourne Shell由AT&T贝尔实验室的S.R.Bourne开发，也因开发者的姓名而得名。它是Unix的第一个Shell程序，早已成为工业标准。目前几乎所有的Linux系统都支持它。不过Bourne Shell的作业控制功能薄弱，且不支持别名与历史记录等功能。目前大多操作系统是将其作为应急Shell使用。
 	C Shell（简称csh）：C Shell由加利福尼亚大学伯克利分校开发。最初开发的目的是改进Bourne Shell的一些缺点，并使Shell脚本的编程风格类似于C语言，因而受到广大C程序员的拥护。不过C Shell的健壮性不如Bourne Shell。
Korn Shell（简称ksh）：Korn Shell由David Korn开发，解决了Bourne Shell的用户交互问题，并克服了C Shell的脚本编程怪癖的缺点。Korn Shell的缺点是需要许可证，这导致它应用范围不如Bourne Shell广泛。
Bourne Again Shell（简称bash）：Bourne Again Shell由AT&T贝尔实验室开发，是Bourne Shell的增强版。随着几年的不断完善，已经成为最流行的Shell。它包括了早期的Bourne Shell和Korn Shell的原始功能，以及某些C Shell脚本语言的特性。此外，它还具有以下特点：能够提供环境变量以配置用户Shell环境，支持历史记录，内置算术功能，支持通配符表达式，将常用命令内置简化。
别名
alias 查看别名列表
alias  新名字='原名字'
unalias  新名      取消别名
	
history
history  查看历史命令
history  10   查看近10条
.bash_history	存放历史命令
.bashrc			配置信息
	

echo
向终端输出指定内容
	
	
通配符
	*	?	[^]	[]			
	|

while(1)
{
	scanf
	switch()
{
	case 'A':
		函数调用
}
}
	
将如下字符串 ”abc     defg   h i jk      lm   n”，空格去掉。
abcdefghijklmn
 











