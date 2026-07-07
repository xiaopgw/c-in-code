# IO 与 进程 -- 学习笔记

---

# 第一部分：文件 IO

## 1.1 标准 C 库 IO（带缓冲）

标准 C 库的 IO 函数在用户态维护了一个缓冲区，数据先写到缓冲区，满了一定大小或遇到特定条件才调用系统调用写入内核。这样做的好处是减少系统调用次数，提高效率。

### 常用函数

  fopen()     -- 打开文件            (stdio.h)
  fclose()    -- 关闭文件            (stdio.h)
  fread()     -- 从文件读数据         (stdio.h)
  fwrite()    -- 向文件写数据         (stdio.h)
  fprintf()   -- 格式化写入文件       (stdio.h)
  fscanf()    -- 从文件格式化读取     (stdio.h)
  fseek()     -- 移动文件读写位置     (stdio.h)
  rewind()    -- 将读写位置重置到开头 (stdio.h)

```c
FILE *fp = fopen("test.txt", "r");  // r:读 w:写 a:追加
if (fp == NULL)
{
     perror("fopen err");
    return -1;
}

char buf[100];
fread(buf, 1, 100, fp);  // 从 fp 读取 100 字节到 buf
printf("%s\n", buf);

fclose(fp);  // 关闭文件
```

### 三种缓冲模式

  全缓冲 -- 填满缓冲区才刷新，用于普通文件读写
  行缓冲 -- 遇到换行符就刷新，用于终端标准输出 stdout
  无缓冲 -- 立即写入，用于标准错误 stderr

```c
// 默认 stdout 是行缓冲
printf("hello ");     // 不会立即输出，因为没有换行符
printf("world\n");    // 遇到 \n 才刷新缓冲区

// stderr 是无缓冲
fprintf(stderr, "error!\n");  // 立即输出
```

---

## 1.2 Linux 系统调用 IO（无缓冲）

系统调用直接进入内核完成操作，没有用户态缓冲区。每次调用都涉及用户态到内核态的切换。

### 核心函数

#### `open()` -- 打开或创建文件

```c
#include <fcntl.h>
#include <unistd.h>

int fd = open("file.txt", O_RDONLY);           // 只读打开
int fd = open("file.txt", O_WRONLY | O_CREAT, 0644);  // 写方式打开，不存在则创建

// 常用标志：
// O_RDONLY   -- 只读
// O_WRONLY   -- 只写
// O_RDWR     -- 读写
// O_CREAT    -- 不存在则创建
// O_TRUNC    -- 清空文件内容
// O_APPEND   -- 追加写入

// 返回值：
// 成功：文件描述符（非负整数）
// 失败：-1
```

#### `read()` -- 读取数据

```c
#include <unistd.h>

char buf[1024];
ssize_t n = read(fd, buf, sizeof(buf));  // 从 fd 读数据到 buf
// 返回值：
// > 0 : 实际读取的字节数
// = 0 : 读到文件末尾（EOF）
// -1  : 出错
```

#### `write()` -- 写入数据

```c
#include <unistd.h>

const char *str = "hello linux";
ssize_t n = write(fd, str, strlen(str));  // 将 str 写入 fd
// 返回值：实际写入的字节数（通常等于请求的字节数，除非出错）
```

#### `close()` -- 关闭文件

```c
#include <unistd.h>

close(fd);  // 关闭文件描述符，释放资源
```

### 完整示例：拷贝文件

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1 = open("src.txt", O_RDONLY);
    int fd2 = open("dst.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    char buf[1024];
    ssize_t n;
    while ((n = read(fd1, buf, sizeof(buf))) > 0)
    {
        write(fd2, buf, n);
    }
    
    close(fd1);
    close(fd2);
    return 0;
}
```

### `open()` vs `fopen()`

- '归属'：fopen() 是 C 标准库，open() 是 Linux 系统调用
- '返回类型'：fopen() 返回 FILE * 指针，open() 返回文件描述符 int
- '缓冲'：fopen() 有缓冲，open() 无缓冲
- '跨平台'：fopen() 可移植，open() 仅 Linux/Unix
- '性能'：fopen() 大量数据时效率高，open() 实时性要求高时用

---

## 1.3 特殊文件描述符

Linux 系统在进程启动时，默认打开三个文件描述符：

  编号 0 -- stdin  -- 键盘   -- 标准输入
  编号 1 -- stdout -- 屏幕   -- 标准输出
  编号 2 -- stderr -- 屏幕   -- 标准错误

```c
write(1, "hello\n", 6);   // 相当于 printf("hello\n");
write(2, "error\n", 6);   // 相当于 fprintf(stderr, "error\n");
```

---

## 1.4 文件描述符重定向

### `dup()` -- 复制文件描述符

```c
#include <unistd.h>

int new_fd = dup(old_fd);
// 复制 old_fd，系统分配一个最小的可用编号给 new_fd
// 复制后两个 fd 指向同一个文件
```

### `dup2()` -- 复制到指定编号

```c
#include <unistd.h>

dup2(old_fd, new_fd);
// 将 old_fd 复制到 new_fd 指定的编号
// 如果 new_fd 已经打开，先关闭它再复制
```

### 重定向的典型用法

```c
// 实现：将 printf 的输出重定向到文件
int fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
dup2(fd, 1);      // 将文件描述符 1（stdout）指向文件
close(fd);        // 关掉原来的 fd

printf("这条信息会写入文件，而不是打印到屏幕\n");
```

```c
// 实现：ls > output.txt 的底层逻辑
// 在 fork + exec 之前，先重定向文件描述符
int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
dup2(fd, 1);      // stdout -> 文件
close(fd);
execlp("ls", "ls", NULL);  // ls 的输出自动写入文件
```

---

## 1.5 标准 C 库 IO 与系统调用的关系图

```
应用程序
    |
    |---- fopen/fread/fwrite ---> 用户态缓冲区 ---> fflush/fclose ---> write/read
    |                                                                    |
    |---- open/read/write ----------- 直接进入内核 ---------------------> 内核驱动
                                                                             |
                                                                         磁盘/设备
```

标准 C 库 IO 在底层最终还是调用系统调用 `read()` / `write()`，只是中间多了一层缓冲区。

---

# 第二部分：进程

## 2.1 进程的概念

**程序**：存放在磁盘上的可执行文件，是静态的。

**进程**：程序的一次执行过程，是动态的。进程是操作系统分配资源的最小单位。

### PCB（进程控制块）

内核为每个进程维护一个 `task_struct` 结构体，包含：
- 进程 ID（PID）
- 进程状态
- 程序计数器
- 内存指针
- 打开的文件描述符表
- CPU 调度信息等

### 进程状态

创建 -> 就绪 <--> 运行 -> 阻塞 -> 就绪
         \                         /
          \--- 终止 <----- 僵尸 --/

  运行态 -- 正在占用 CPU 执行
  就绪态 -- 具备运行条件，等待 CPU 调度
  阻塞态 -- 等待某种事件（如 IO 完成）
  僵尸态 -- 进程已退出，但未释放 PCB
  终止态 -- 进程结束

---

## 2.2 `fork()` -- 创建子进程

`fork()` 是 Linux 进程创建的核心函数，面试高频考点。

```c
#include <unistd.h>

pid_t fork(void);
```

### fork 的特性

调用一次 `fork()`，返回**两次**：

  返回值 0   -- 在子进程中返回
  返回值 >0  -- 在父进程中返回，返回的是子进程的 PID
  返回值 -1  -- 创建失败

### fork 的基本用法

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    
    if (pid > 0)
    {
        // 父进程
        printf("父进程: pid=%d, 子进程pid=%d\n", getpid(), pid);
    }
    else if (pid == 0)
    {
        // 子进程
        printf("子进程: pid=%d, 父进程pid=%d\n", getpid(), getppid());
    }
    else
    {
        perror("fork err");
        return -1;
    }
    
    // 父子进程都会执行到这里
    printf("这句话父子进程各打印一次\n");
    
    return 0;
}
```

### fork 后的内存关系

```
fork() 之前：父进程有变量 a = 10
                 |
fork() 之后：父进程 a = 10     子进程 a = 10（独立副本）
             修改 a = 20       修改 a = 30
             父进程 a = 20     子进程 a = 30（互不影响）
```

关键点：
- 子进程复制父进程的代码段、数据段、堆栈
- 父子进程的变量相互独立，修改互不影响
- 采用**写时拷贝（COW）**技术，只有写入时才真正复制

### 常见的 fork 面试题

```c
// 这道题输出几个 "A"？
int main()
{
    fork();
    fork();
    printf("A\n");
    return 0;
}
// 答案：4 个。两次 fork 产生 2^2 = 4 个进程
```

```c
// 这道题呢？
int main()
{
    printf("A\n");
    fork();
    printf("B\n");
    return 0;
}
// 答案：先打一个 A，再打两个 B
// 因为 fork 之前 printf("A\n") 已经被父进程执行了
// fork 后父子进程各打一个 B
```

---

## 2.3 `exec()` 函数族 -- 替换进程映像

`exec()` 系列函数用于在当前进程中执行另一个程序，**不创建新进程**，只是将当前进程的代码段、数据段替换成新程序的内容。

```c
#include <unistd.h>

// 常用成员：
int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execvp(const char *file, char *const argv[]);
```

命名规则：
- 带 `l`（list）：参数以列表形式传递
- 带 `v`（vector）：参数以数组形式传递
- 带 `p`（path）：自动在 PATH 环境变量中搜索可执行文件

```c
// execlp：带 p，自动搜索 PATH
execlp("ls", "ls", "-l", NULL);  // 执行 ls -l

// execl：不带 p，需要写完整路径
execl("/bin/ls", "ls", "-l", NULL);

// execvp：参数以数组形式传递
char *argv[] = {"ls", "-l", NULL};
execvp("ls", argv);
```

### fork + exec 的组合（标准模式）

```c
pid_t pid = fork();

if (pid == 0)  // 子进程
{
    execlp("ls", "ls", "-l", NULL);
    perror("execlp err");  // 只有 exec 失败才会执行到这里
    exit(-1);
}
else if (pid > 0)  // 父进程
{
    wait(NULL);  // 等待子进程结束
}
```

---

## 2.4 `wait()` / `waitpid()` -- 回收子进程

子进程退出后，如果不回收，会变成**僵尸进程**，占用系统资源。

### wait()

```c
#include <sys/wait.h>

pid_t wait(int *status);
// 阻塞等待任意一个子进程退出
// 返回值：退出子进程的 PID
// status：保存退出状态
```

### waitpid()

```c
pid_t waitpid(pid_t pid, int *status, int options);
// pid > 0  : 等待指定 PID 的子进程
// pid = -1 : 等待任意子进程（同 wait）
// options  : WNOHANG（非阻塞，没有子进程退出立即返回 0）
```

### 完整示例

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    
    if (pid == 0)
    {
        // 子进程
        printf("子进程工作...\n");
        sleep(2);
        return 100;  // 子进程退出码 100
    }
    else if (pid > 0)
    {
        // 父进程
        int status;
        pid_t ret = wait(&status);  // 阻塞等待子进程结束
        
        if (WIFEXITED(status))  // 子进程是否正常退出
        {
            printf("子进程 %d 正常退出，退出码: %d\n", 
                   ret, WEXITSTATUS(status));
        }
    }
    return 0;
}
```

---

## 2.5 僵尸进程与孤儿进程

### 僵尸进程

子进程退出后，父进程没有调用 `wait()` 回收，子进程的 PCB 仍然保留在内核中。

```c
// 制造僵尸进程
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("子进程退出\n");
        exit(0);
    }
    else
    {
        sleep(30);  // 父进程睡眠期间，子进程已经是僵尸状态
        wait(NULL); // 回收后僵尸消失
    }
    return 0;
}
```

查看僵尸进程：`ps aux | grep Z`

### 孤儿进程

父进程先于子进程退出，子进程变成孤儿进程，由 `init` 进程（PID=1）收养。

```c
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        sleep(5);      // 这期间父进程已经退出了
        printf("我成了孤儿，被 init 收养\n");
    }
    else
    {
        printf("父进程先退出\n");
        exit(0);
    }
    return 0;
}
```

---

# 第三部分：进程间通信（IPC）

进程间通信（Inter-Process Communication）是 Linux 系统编程的核心内容。

## 3.1 管道 `pipe()`

管道是半双工的（单向），常用于父子进程间通信。

```c
#include <unistd.h>

int pipe(int pipefd[2]);
// pipefd[0] -- 读端
// pipefd[1] -- 写端
// 成功返回 0，失败返回 -1
```

### 父子进程管道通信

```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);  // 创建管道
    
    pid_t pid = fork();
    
    if (pid == 0)  // 子进程：写
    {
        close(fd[0]);  // 关闭读端
        const char *msg = "hello 父进程";
        write(fd[1], msg, strlen(msg));
        close(fd[1]);
    }
    else  // 父进程：读
    {
        close(fd[1]);  // 关闭写端
        char buf[100] = {0};
        read(fd[0], buf, sizeof(buf));
        printf("收到子进程消息: %s\n", buf);
        close(fd[0]);
        
        wait(NULL);  // 回收子进程
    }
    return 0;
}
```

### 管道的典型应用：实现 `ls | grep hello`

```c
int main()
{
    int fd[2];
    pipe(fd);
    
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        // 第一个子进程：执行 ls
        close(fd[0]);          // 关闭读端
        dup2(fd[1], 1);        // stdout -> 管道写端
        close(fd[1]);
        execlp("ls", "ls", NULL);
    }
    
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        // 第二个子进程：执行 grep hello
        close(fd[1]);          // 关闭写端
        dup2(fd[0], 0);        // stdin <- 管道读端
        close(fd[0]);
        execlp("grep", "grep", "hello", NULL);
    }
    
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    
    return 0;
}
```

## 3.2 命名管道 FIFO

普通管道只能用于有亲缘关系的进程之间。FIFO 可以让无亲缘关系的进程通信。

```c
#include <sys/types.h>
#include <sys/stat.h>

int mkfifo(const char *pathname, mode_t mode);
// 创建命名管道文件
```

```c
// 进程 A（写端）
mkfifo("myfifo", 0644);
int fd = open("myfifo", O_WRONLY);
write(fd, "hello", 5);
close(fd);

// 进程 B（读端）
int fd = open("myfifo", O_RDONLY);
read(fd, buf, sizeof(buf));
printf("%s\n", buf);
close(fd);
```

## 3.3 信号 `signal()`

信号是一种异步通信方式，进程收到信号后会暂停当前工作，去处理信号。

```c
#include <signal.h>

// 注册信号处理函数
void handler(int sig)
{
    printf("收到信号: %d\n", sig);
}

int main()
{
    signal(SIGINT, handler);  // 注册 Ctrl+C 信号处理
    // 或者用 SIG_IGN 忽略信号
    // signal(SIGINT, SIG_IGN);  // 忽略 Ctrl+C
    
    while (1)
    {
        printf("工作中...\n");
        sleep(1);
    }
    return 0;
}
```

```c
// 发送信号
kill(pid, SIGINT);    // 向指定进程发送信号
raise(SIGINT);        // 向自己发送信号
```

常见信号：

  SIGINT(2)   -- 键盘中断 Ctrl+C       -- 终止进程
  SIGQUIT(3)  -- 键盘退出 Ctrl+\       -- 终止 + 转储
  SIGKILL(9)  -- 强制杀死              -- 终止（不可捕获）
  SIGSTOP(19) -- 暂停进程              -- 暂停（不可捕获）
  SIGCHLD(17) -- 子进程状态改变        -- 忽略

## 3.4 共享内存（最快的 IPC）

共享内存是最高效的 IPC 方式，因为数据直接在物理内存中共享，不需要在用户态和内核态之间拷贝。

```c
#include <sys/shm.h>

// 创建/获取共享内存
int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0644);

// 映射共享内存到进程地址空间
void *ptr = shmat(shmid, NULL, 0);

// 使用共享内存（读写）
sprintf(ptr, "hello");  // 写入
printf("%s\n", (char *)ptr);  // 读取

// 解除映射
shmdt(ptr);

// 删除共享内存
shmctl(shmid, IPC_RMID, NULL);
```

## 3.5 消息队列

```c
#include <sys/msg.h>

// 创建消息队列
int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0644);

// 发送消息
struct msgbuf buf;
buf.mtype = 1;
sprintf(buf.mtext, "hello");
msgsnd(msgid, &buf, strlen(buf.mtext), 0);

// 接收消息
msgrcv(msgid, &buf, sizeof(buf.mtext), 1, 0);  // 接收 type=1 的消息
```

## 3.6 信号量（用于同步互斥）

信号量主要用于解决多个进程访问共享资源时的同步问题。

```c
#include <sys/sem.h>

// 创建信号量集
int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0644);
// 初始化信号量值
semctl(semid, 0, SETVAL, 1);  // 初始值为 1（二值信号量，相当于互斥锁）

// P 操作（申请资源，值减 1）
struct sembuf op = {0, -1, 0};
semop(semid, &op, 1);

// 访问共享资源...

// V 操作（释放资源，值加 1）
op.sem_op = 1;
semop(semid, &op, 1);
```

---

# 第四部分：难点总结与面试常见问题

## 4.1 fork 的返回值理解

fork() 调用一次返回两次：
  父进程收到 > 0 --> 子进程的 PID
  子进程收到 = 0 --> 表示自己是子进程

通过 if-else 结构区分父子进程是标准写法。

## 4.2 僵尸进程如何避免

- 父进程调用 wait() / waitpid() 回收
- 父进程注册 SIGCHLD 信号处理函数
- 父进程先退出（子进程变成孤儿，由 init 回收）

## 4.3 管道 vs 共享内存

  管道         -- 速度慢（需内核缓冲），单向，自带阻塞机制，适用小数据量
  共享内存     -- 速度最快（直接内存映射），双向，需信号量配合，适用大数据量

## 4.4 常用命令

```bash
ps -ef          # 查看所有进程
ps aux          # 查看进程详细信息
kill -9 PID     # 强制杀死进程
top             # 动态查看进程资源占用
pstree          # 以树形结构查看进程关系