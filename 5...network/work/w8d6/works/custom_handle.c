/***********************************************************************************
Copy right:	    hqyj Tech.
Author:         jiaoyue
Date:           2023.07.01
Description:    http请求处理
***********************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include "custom_handle.h"


#define KB 1024
#define HTML_SIZE (64 * KB)
#define P -1
#define V 1

//普通的文本回复需要增加html头部
#define HTML_HEAD "Content-Type: text/html\r\n" \
				  "Connection: close\r\n"
// ——————————————————————————————————————————————————————————
// 添加的共享内存通信
// ——————————————————————————————————————————————————————————

typedef struct shm_struct
{
    int coil;
    int value;
    int led;
    int buz;
    int hold[4];
} sshm, pshm;

typedef enum coilen
{
    LED,
    BUZ
} ec;
enum e_sem
{
    sem1,
    sem2,
    sem3,
    sem4
};

union semun
{
    int val;
};

sshm *shmdata = NULL;
int semid = 0;
// pv操作
void sem_op(int semid, int num, int op)
{
    struct sembuf buf;
    buf.sem_num = num;
    buf.sem_op = op;
    buf.sem_flg = 0;
    
    semop(semid, &buf, 1);
}


// 创key
key_t keyWebsever()
{
    // key
    key_t key;
    return key = ftok("work.c", N);
}
// 共享内存
int shmWebSever(key_t key)
{
    // 创建共享内存相关

    int shmid = shmget(key, 0, 0);
    if (shmid < 0)
    {
            perror("shmid->");
    }

    void *shmp = shmat(shmid, NULL, 0);
    if (shmp == (void *)-1)
    {
        perror("shmat->");
        return -1;
    }
    // 共享内存内的结构体
    shmdata = shmp;
}
// 信号灯集
int semWebSevser(key_t key)
{
    // 信号灯控制
    semid = semget(key, 0, 0);
    if (semid < 0)
    {
            perror("semid->");
            return -1;
    }
    // 初始化
    union semun sem;
    sem.val = 0;

}
// ——————————————————————————————————————————————————————————
static int handle_login(int sock, const char *input)
{
    char reply_buf[HTML_SIZE] = {0};
    char *uname = strstr(input, "username=");
    uname += strlen("username=");
    char *p = strstr(input, "password");
    *(p - 1) = '\0';
    printf("username = %s\n", uname);

    char *passwd = p + strlen("password=");
    printf("passwd = %s\n", passwd);

    if(strcmp(uname, "admin")==0 && strcmp(passwd, "admin")==0)
    {
        sprintf(reply_buf, "<script>localStorage.setItem('usr_user_name', '%s');</script>", uname);
        strcat(reply_buf, "<script>window.location.href = '/index.html';</script>");
        send(sock,reply_buf,strlen(reply_buf),0);
    }
    else
    {
        printf("web login failed\n");

        //"用户名或密码错误"提示，chrome浏览器直接输送utf-8字符流乱码，没有找到太好解决方案，先过渡
        char out[128] = {0xd3,0xc3,0xbb,0xa7,0xc3,0xfb,0xbb,0xf2,0xc3,0xdc,0xc2,0xeb,0xb4,0xed,0xce,0xf3};
        sprintf(reply_buf, "<script charset='gb2312'>alert('%s');</script>", out);
        strcat(reply_buf, "<script>window.location.href = '/login.html';</script>");
        send(sock,reply_buf,strlen(reply_buf),0);
    }

    return 0;
}

static int handle_add(int sock, const char *input)
{
    int number1, number2;
    
    //input必须是"data1=1data2=6"类似的格式，注意前端过来的字符串会有双引号
    sscanf(input, "\"data1=%ddata2=%d\"", &number1, &number2);
    printf("num1 = %d\n", number1);

    char reply_buf[HTML_SIZE] = {0};
    printf("num = %d\n", number1+number2);
    sprintf(reply_buf, "%d", number1+number2);
    printf("resp = %s\n", reply_buf);
    send(sock,reply_buf,strlen(reply_buf),0);

    return 0;
}
// 小尝试
static int mynum(int sock, const char *input)
{
    char buf_send[64] = {};
    int num = atoi(input) * 10;
    sprintf(buf_send, "%d", num);
    send(sock, buf_send, strlen(buf_send), 0);
}
// modbus数据传输处理
static int modbusdata(int sock, const char *input)
{
    int led, buz, requ;

    sscanf(input, "\"LED=%dBUZ=%drequest:%d\"", &led, &buz, &requ);
    if (requ == 1)
    {
        sem_op(semid, sem1, V);
        sem_op(semid, sem2, P);
        send(sock, shmdata->hold, strlen(shmdata->hold), 0);
    }
    // shmdata->led = 1;
    // shmdata->buz = 1;
}
// 保持寄存器
static int holding(int sock, const char *input)
{
    char buf[N] = {};
    sprintf(buf, "%d,%d,%d,%d", 
            shmdata->hold[0], shmdata->hold[1],
            shmdata->hold[2],shmdata->hold[3]);
    send(sock, buf, strlen(buf), 0);
    printf("\n\n==================================================\n\n");
    return 0;
}

// 线圈寄存器
static int coil(int sock, const char *input)
{
    char buf[N] = {};
    // int coil, value;
    sscanf(input, "type=coil&coil=%d&value=%d", 
            &shmdata->coil, &shmdata->value);
    sem_op(semid, sem3, V);
    sem_op(semid, sem4, P);
    sprintf(buf, "%d,%d",shmdata->led, shmdata->buz);
    send(sock, buf, strlen(buf), 0);
    
    printf("\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    // printf("%d %d\n", shmdata->coil,shmdata->value);
    return 0;
}

/**
 * @brief 处理自定义请求，在这里添加进程通信
 * @param input
 * @return
 */
int parse_and_process(int sock, const char *query_string, const char *input)
{
    //query_string不一定能用的到
    // 共享内存通信
    key_t key = keyWebsever();
    shmWebSever(key);
    semWebSevser(key);
    //先处理登录操作
    if(strstr(input, "username=") && strstr(input, "password="))
    {
        return handle_login(sock, input);
    }
    //处理求和请求
    else if(strstr(input, "data1=") && strstr(input, "data2="))
    {
        return handle_add(sock, input);
    }
    // modbus处理
    else if (strstr(input, "type=coil") != NULL) {
        return coil(sock, input);
    }
    else if (strstr(input, "type=sensors") != NULL) {
        return holding(sock, input);
    }
    else  //剩下的都是json请求，这个和协议有关了
    {
        // 构建要回复的JSON数据
        const char* json_response = "{\"message\": \"Hello, client!\"}";

        // 发送HTTP响应给客户端
        send(sock, json_response, strlen(json_response), 0);
    }

    return 0;
}
