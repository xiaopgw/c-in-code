# linux
## 软连接和硬链接
### 硬链接
	可以理解为文件的多个入口，多个文件名指向同一份磁盘数据
	根据Linx系统给文件分配inode(ls -li)号进行建立
	格式:
	ln  源文件  目标文件
硬链接文件属性:
源文件和连接文件有相同的inode号
修改其中一个文件的内容，另一个也会改变
源文件删除，链接文件还在
删除源文件后，再创建同名文件，不链接，就没关系
文件夹不能进行硬链接

### 软链接  <!-- (快捷方式) -->
	根据文件的路径建立 最好用绝对路径
	格式:
	ln -s 源文件  目标文件
软连接文件属性:
源文件和链接文件inode号不同
修改任意一个内容另一个而也会修改
软连接可以链接文件夹
源文件删除，链接文件的内容就消失了
删除源文件后，再创建同名文件，不需重链接，也会链接上，但内容会根据新创建的文件走
# c语言 分文件编程
把文件分成多个  .c(一个工程，有且只有一个主函数)
		  多个  .h(自定义)  

.h 头文件包含
	其他头文件
	函数声明
	全局变量的声明
	宏定义
	重定义
	构造数据类型

<>系统定义的头文件，去系统目录下找/user/include
""自定义的头文件，先在当前目录找，后去系统目录找

# gdb代码调试
gcc -g 1.c -o 1
gdb 1       进入gdb
	r:  运行代码
	l:  查看文件 默认显示前十行，按回车继续重复上一个命令来继续列出接下来的10行
	b 行号: 添加断点
	info b: 查看断点情况
	d num(断点编号): 删除断点
	p 变量名: 查看变量的值
	s/n:单步运行，s会进入子函数顺序执行;
		单步执行,n不会进入子函数(自定义函数)
	c:  执行到下一个断点的位置
	help:   帮助
	q:  退出

进入gdb调试，输入l查看行号(代码太长显示不全，回车补齐),输入b行号 添加断点,输入r运行代码至断点处，输入s或n进行单步调试(如果是自定义函数可以用s进入，但如果是系统函数，需要用n大步迈进不进入子函数，直接继续运行到主函数的下一行)，过程中可以p变量名查看变量的值，输入q退出
# valgrind(只做了解)

# makefile
工程管理器
## 格式
目标:依赖
<Tab>命令
依赖<———命令<———目标

```text
gcc -c hello.c -o hello.o   目标:hello.o 依赖:hello.c
gcc hello.o -o hello        目标:hello.o 依赖:hello.c
```
逆序书写

需要新建一个makefile来放这些命令，然后用make来打开这个文件
## 单个文件
可以先写一个基础的
```makefile
hello:hello.o
	gcc hello.o -o hello
hello.o:hello.c
	gcc -c hello.c -o hello.o
```
这个可以随时用make编译hello.c

同时可以用伪目标来做一个删除编译出来的文件的命令
```makefile
hello:hello.o
	gcc hello.o -o hello
hello.o:hello.c
	gcc -c hello.c -o hello.o
clean:
	rm *.o hello
```
这样输入make clean就可以单独运行clean下的命令

由此可知，所谓的makefile命令就是目标:依赖，如果目标<依赖的时间戳，那就运行下面的命令，甚至还可以单独运行命令，所以这个makefile是可以完全自定义的
所以可以
```makefile
test:
	echo "hello world"
```
如果有重名的clean文件，需要在clean命令上面加.PHONY:clean 避免因出现重名文件而产生的错误
```makefile
hello:hello.o
	gcc hello.o -o hello
hello.o:hello.c
	gcc -c hello.c -o hello.o
.PHONY:clean
clean:
	rm *.o hello
```

## 多个文件
可以通过加多个.c文件，一起编译，而且可以，如果某个.c文件更改了，他就会只编译这一个.c文件
```makefile
hello:hello.o hello1.o
	gcc hello.o hello1.o -o hello
hello.o:hello.c
	gcc -c hello.c -o hello.o
hello1.o:hello1.c
	gcc -c hello1.c -o hello1.o
clean:
	rm *.o hello
```
## makefile变量
自定义变量 预定义变量 自动变量
### 自定义变量
一般用大写表示变量名
取变量的值 $(变量名)
=  递归方式展开赋值
:= 直接赋值
+= 追加新的值
?= 判断变量之前是否定义过值，没有定义过就赋值，否则不变
```makefile
V1 = hello
V2 := $(V1) world
V1 += !
V1 ?= asdf
test:
	echo $(V1)		
	echo $(V2)
#V1 = hello !;V2 = hello world
```
### 预定义变量
系统预先设定好的变量，可能有默认值（这个就不记了）
### 自动变量
$<	$^	$@
```makefile
hello:hello.o hello1.o
	gcc $^ -o $@
hello.o:hello.c
	gcc -c $< -o $@
hello1.o:hello1.c
	gcc -c $< -o $@
clean:
	rm *.o hello
```
同时可以用%.c代替所有的.c文件所以可以再简化
```makefile
hello:hello.o hello1.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o hello
```


- [linux](#linux)
	- [软连接和硬链接](#软连接和硬链接)
		- [硬链接](#硬链接)
		- [软链接  ](#软链接--)
- [c语言 分文件编程](#c语言-分文件编程)
- [gdb代码调试](#gdb代码调试)
- [valgrind(只做了解)](#valgrind只做了解)
- [makefile](#makefile)
	- [格式](#格式)
	- [单个文件](#单个文件)
	- [多个文件](#多个文件)
	- [makefile变量](#makefile变量)
		- [自定义变量](#自定义变量)
		- [预定义变量](#预定义变量)
		- [自动变量](#自动变量)





1.a和b相同，c不同，删除新建后，a和c相同，b是之前a的内容
2.似乎是因为文件夹里面默认还有两个文件.. 和.可以进入上一个文件夹和进入本文件的文件，但这个我具体没学过，所以不知道原理是为什么
3.不能，应该会报错吧，因为<>是去系统文件找头文件，但我具体没试过会怎么样，他会显示什么呢
4.头文件里不能赋值和打印，只能声明，应该去掉这部分
5.第一行 第三行 n
6.我没看到什么问题，如果是命令行应该是用tab缩进的话，这个只是看还是看不出来是空格还是制表符……
7.hello! hello! world abc
8.
app:main.o utils.o data.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
9.防止外面出现同名的文件，如果有同名的文件，不会执行，因为没更新时间戳

那3警告他会正常运行吗
