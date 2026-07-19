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




- [linuxc2](#linuxc2)
  - [内核系统构架](#内核系统构架)
  - [关机](#关机)
  - [网络配置](#网络配置)
  - [Linux下的软甲安装](#linux下的软甲安装)
  - [shell基础命令](#shell基础命令)
    - [alias](#alias)
  - [history](#history)
  - [echo](#echo)
  - [通配符](#通配符)








