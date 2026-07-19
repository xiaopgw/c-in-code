#include "my.h"
// void handler(int sig)
//     {
//         if (sig == SIGINT)
//         {
//             printf("SIGINT\n");
//         }
//         if (sig == SIGTSTP)
//         {
//             printf("SIGTSTP\n");
//         }

//     }
int main(int argc, char const *argv[])
{
    // pid_t pid;
    // pid = fork();
    // if(pid < 0)
    // {
    //     perror("fork->");
    // }
    // else if(pid == 0)
    // {
    //     printf("in the chlid %d %d\n", getpid(), getppid());
    //     while(1);
    // }
    // else
    // {
    //     printf("int the parent %d %d\n", getpid(), pid);
    //     while(1);
    // }
    // kill(getpid(), SIGKILL);
    // raise(SIGKILL);

    // printf("%d\n", alarm(10));
    // sleep(3);
    // printf("%d\n", alarm(2));
    // pause();

    // signal(SIGTSTP, handler);
    // signal(SIGINT, handler);    // 忽略信号
    // pause();



    // 无名管道
    // FILE *fp = fopen("test", "r");
    // char arr[N] = {};
    // char brr[N] = {};
    // int fd[2] = {0};
    // pipe(fd);
    // fgets(arr, N - 1, fp);
    // write(fd[1], arr, N);
    // read(fd[0], brr, N);
    // printf("%s", brr);


    // 有名管道
    // 
    
    return 0;
}
