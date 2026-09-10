// #include <sys/types.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <errno.h>
// #include <sys/sem.h>

// #define N 64

// union semun
// {
//     int val;
// };

// // 创key
// key_t keyWebsever()
// {
//     // key
//     key_t key;
//     key = ftok("work.c", N);
//     return key;
// }
// // 共享内存
// void shmWebSever(key_t key)
// {
//     // 创建共享内存相关

//     int shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0765);
//     if (shmid < 0)
//     {
//         if (errno == EEXIST)
//         {
//             shmid = shmget(key, 0, 0765);
//         }
//         else
//         {
//             perror("shmid->");
//             return -1;
//         }
//     }

//     void *shmp = shmat(shmid, NULL, 0);
//     if (shmp == (void *)-1)
//     {
//         perror("shmat->");
//         return -1;
//     }
//     // 共享内存内的结构体
//     shmdata = shmp;
// }
// // 信号灯集
// void semWebSevser(key_t key)
// {
//     // 信号灯控制
//     semid = semget(key, 2, IPC_CREAT | IPC_EXCL | 0765);
//     if (semid < 0)
//     {
//         if (errno == EEXIST)
//         {
//             semid = semget(key, 0, 0765);
//         }
//         else
//         {
//             perror("semid->");
//             return -1;
//         }
//     }
//     // 初始化
//     union semun sem;
//     sem.val = 0;
//     int semc = semctl(semid, 0, SETVAL, sem);
//     if (semc < 0)
//     {
//         perror("semc->");
//         return -1;
//     }
// }