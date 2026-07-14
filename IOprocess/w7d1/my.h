#ifndef _MY_H
#define _MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/msg.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 32

union semnum
{
    int val;
};
struct msgbuf
{
    long mtype;
    char mtext;
};
// int a(int a);
// int a(int a, int b);
#endif