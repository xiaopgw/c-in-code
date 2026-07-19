#include "my.h"
struct sembuf mysembuf;
void mydeng(int a1, int a2, int a3)
{
    mysembuf.sem_num = a1;
    mysembuf.sem_op = a2;
    mysembuf.sem_flg = a3;
}
int main(int argc, char const *argv[])
{
    // key_t key = ftok("test", 51);
    // printf("%x\n", key);
    // int shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0777);
    // if (errno == EEXIST)
    // {
    //     shmid = shmget(key, N, 0777);
    // }
    // else if(shmid <= 0)
    // {
    //     perror("shm->");
    // }

    // printf("%d\n", shmid);
    // char *p = shmat(shmid, NULL, 0);
    // if(p == (void*)-1)
    // {
    //     printf("X->");
    //     return -1;
    // }

    // getchar();

    // pid_t id =  fork();
    
    // key_t key = ftok("test", 51);
    // if (key < 0)
    // {
        
    //     perror("key->");
    // }
    // int shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0777);
    // if (errno == EEXIST)
    // {
    //     shmid = shmget(key, N, 0777);
    // }
    // else if (shmid <= 0)
    // {
    //     perror("shmid->");
    // }
    // char *p = shmat(shmid, NULL, 0);
    // if (p == (void *)-1)
    // {
    //     perror("p->");
    // }


    // while (1)
    // {
    // scanf("%s", p);
    // if(!strcmp(p, "quit"))
    // break;
    // }

    // if (id < -1)
    // {
    //     perror("id->");
    //     return -1;
    // }
    // else if(id == 0)
    // {
    //     scanf("%s", p);
    // }
    // else
    // {
    //     wait(NULL);
    //     printf("%s\n", p);
    // }

    // int semid;
    // semid = semget(key, 2, IPC_CREAT | IPC_EXCL | 0765);
    // // printf("%d\n", semid);
    // if (semid > 0)
    // {
    //     union semnum sem;
    //     sem.val = 2;
    //     semctl(semid, 0, SETVAL, sem);
    //     sem.val = 4;
    //     semctl(semid, 1, SETVAL, sem);
    //     printf("%d\n", semctl(semid, 0, GETVAL, sem));
    //     printf("%d\n", semctl(semid, 1, GETVAL, sem));
        
    // }

    // else if (errno == EEXIST)
    // {
    //     semid = semget(key, 2, 0765);
    // }
    // else if (semid <= 0)
    // {
    //     perror("shmid->");
    //     return -1;
    // }



    // struct msgbuf msg = {200, 'a'}, rev_msg = {0};
    // int msgid = 0;
    // msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0765);
    // if (errno == EEXIST)
    // {
    //     msgid = msgget(key, 0765);
    // }
    // else if(msgid <= 0)
    // {
    //     perror("msgid->");
    //     return -1;
    // }
    
    // msgsnd(msgid, &msg, sizeof(msg) - sizeof(msg.mtype), 0);
    // msg.mtype = 100;
    // msg.mtext = 'b';
    // msgsnd(msgid, &msg, sizeof(msg) - sizeof(msg.mtype), 0);
    // msgrcv(msgid, &rev_msg, sizeof(msg) - sizeof(msg.mtype), 100, 0);
    // printf("%c\n", rev_msg.mtext);





    // 共享内存
    // 信号灯集
    // 消息队列
    // 创key
    // 创建或打开
    // 进行一系列操作       //共享内存：映射，（可以进行增删改查），取消映射
                           //信号灯：初始化，PV操作
                           //消息队列：添加，读取
    // 删除

    // 创key
    key_t key = 0;
    key = ftok("test", 51);    // 返回值是key或-1有errno
    if(key < 0)
    {
        perror("key->");
        return -1;
    }
    printf("key == 0x%x\n", key);

    // 创建三个通信方式
// 第一个
    int shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0765);
    // 判断是否创建成功
    if (shmid <= 0)
    {
        if (errno == EEXIST)
        {
            shmid = shmget(key, N, 0765);
        }
        else if (shmid <= 0)
        {
            perror("shmid->");
            return -1;
        }
    }
    printf("shmid创建%d\n", shmid);
// 第二个
    union setval
    {
        int val;
    };
    int semid = 0;
    union setval l1 = {0}, l2 = {0};
    semid = semget(key, 3, IPC_CREAT | IPC_EXCL | 0765);
    if (semid <= 0)
    {
        if (errno == EEXIST)
        {
            semid = semget(key, 3, 0765);
        }
        else if(semid <= 0)
        {
            perror("semid->");
            return -1;
        }
    }
    else
    {
        //同时初始化
        semctl(semid, 0, SETVAL, l1);
        l1.val = 4;
        semctl(semid, 1, SETVAL, l1);
        l1.val = 8;
        semctl(semid, 2, SETVAL, l1);
    }
    printf("semid创建%d\n", semid);
    // 获取值
    int semg = 0;
    semg = semctl(semid, 0, GETVAL);
    // if (semg <= 0)
    // {
        
    //     if(semg <= 0)
    //     {
    //         perror("semg->");
    //         return -1;
    //     }
    // }
    printf("信号0的值%d\n", semg);
// 第三个
    int msgid = 0;
    msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0765);
    if (msgid <= 0)
    {
        if (errno == EEXIST)
        {
            msgid = msgget(key, 0765);
        }
        else if (msgid <= 0)
        {
            perror("msgid->");
            return -1;
        }
    }
    printf("创建的消息队列%d\n", msgid);
    
    // 操作共享内存
    // 映射共享内存
    
    char *arr = shmat(shmid, NULL, 0);
    arr[0] = 'b';
    int pid = fork();
    if (pid < 0)
    {
        perror("pid->");
        return -1;
    }
    else if (pid == 0)
    {
        
        while (1)
        {
            // scanf("%s", arr);
            // printf("1\n");
            mydeng(0, 1, 0);
            semop(semid, &mysembuf, 1);
            if (!strcmp(arr, "b"))
                break;
        }
        shmdt(arr);
        exit;
    }
    else
    {
        while (1)
        {
            // printf("2\n");
            mydeng(0, -1, 0);
            semop(semid, &mysembuf, 1);
            if (!strcmp(arr, "b"))
                break;
            printf("%s\n", arr);
        }
        // wait(NULL);
    }
    // 进行一点小添加
    // 删除映射
    shmdt(arr);
    shmctl(shmid, IPC_RMID, NULL);
    // 操作信号灯
    // 初始化
    // PV操作
    int sempv;
    mydeng(0, 1, 0);
    sempv = semop(semid, &mysembuf, 1);
    if (sempv < 0)
    {
        perror("sempv->");
        return -1;
    }
    mydeng(0, -1, 0);
    sempv = semop(semid, &mysembuf, 1);
    if (sempv < 0)
    {
        perror("sempv->");
        return -1;
    }
    // 删除灯
    semctl(semid, 0, IPC_RMID);
    // 操作消息队列
    // 添加
    struct msgbuf msg1 = {64, 'a'}, msg2 = {0};
    msgsnd(msgid, &msg1, sizeof(msg1) - sizeof(msg1.mtype), 0);
    // 读取
    msgrcv(msgid, &msg2, sizeof(msg2) - sizeof(msg2.mtype), 64, 0);
    printf("%c\n", msg2.mtext);
    //删除
    msgctl(msgid, IPC_RMID, NULL);








    return 0;
}
