# Linux拓展
## 通配符
用命令批量处理一组文件
通配符      含义
*。         匹配任意长度的字符
？          匹配一个长度的字符
[…]         匹配其中一个指定的一个字符
[-]         匹配指定一个字符范围
[^…]        除了其中指定的字符都可以
[[:lower:]] 匹配所有小写字母
[[:upper:]] 匹配所有大写字母
## 管道
把前一个命令的输出作为后一个命令的输入
command1 | command2
例:
wc  -l  文件名  显示文件行数
wc  -W  文件名  显示文件的单词个数
wc  -c  文件名  显示文件字符个数

获取当前路径的文件数量
ls | wc -w

## 输入输出重定向
前一个命令的输出作为后边文件的内容
    command>file.c 输出重定向 新建模式  文件不存在时，先重建文件；如果文件已存在且有内容，会覆盖之前的内容
    command>>file.c 输出重定向 追加模式

把由命令产生的错误信息输出到文件中;
    command &> file.c
    command 2> file.c
输入重定向<
    command < file.c
    后边文件的内容作为前边命令的输入
## 命令置换符
把一个命令的输出作为另一个命令的阐述
echo "I'am `whoami`"
I'am xiaopgw
## 系统相关命令
man man 查看man手册
su      用户切换（默认root）
su      用户名  切换至指定用户
exit    退出
clear   清屏
date    查看当前系统日期
df      -Th查看磁盘空间
挂载
sudo  mount     -t  设备类型    设备名称    挂载点
sudo  umount    挂载点
## 进程管理
### 静态查看
ps -aux 显示当前系统正在运行的进程
PID 进程号 唯一标识
STAT 进程状态
man ps 查看进程各种状态
ps -ef 显示当前系统正在运行的进程 包括父进程ID
    PPID 父进程

./a.out & 把a.out在后台运行
fg 编号 把后台运行的进程拉到前台
Ctrl z 把前台运行的进程暂停，同时放在后台
bg 编号 把后台暂停的进程在后台运行起来
jobs 在当前终端查看前后台

### 动态查看
top 
NI  进程的nice值    [-20 ~ 19]  值越小，优先级越高
PR  进程的优先级    PR=NI+20

renice 修改正在运行的进程的优先级
    sudo    renice  num   PID
    num NI 值

kill 发送信号
    kill -l查看linux下的一些信号
    2: SIGINT
    3: SIGQUIT
    9: SIGKILL  杀死进程
    15:SIGTERM
    20:SIGTSTP

## 文件管理
### 文件系统类型
    磁盘文件系统:
    网络文件系统:
    专有/虚拟文件系统:

## Linux文件
/bin:
/dev:
/home:
/mnt:
/usr:
/usr/lib:
/usr/include:
## 文件操作相关命令
mkdir touch rm mv cp

cat -n
head -num
tail
grep
find 路径 -name 文件名
zip 把一个或多个文件压缩
    unzip
gzip 一个文件压缩
    gunzip
bzip2
    bunzip2

tar
    -x:解压
    -c:压缩
    -v:显示压缩过程
    -f:指定压缩名
    -j:压缩的名字（bz2）
    -z:压缩的名字（gz）
tar 选项 压缩(解压)文件名 [要压缩的文件列表]
压缩:
    -cjf
    -czf
解压:
    -xvf
