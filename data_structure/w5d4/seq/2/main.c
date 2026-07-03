#include"my.h"
// 创空
int main(int argc, char const *argv[])
{
    sequeue_p queue = CreateQueue();
    for (int i = 0; i < N - 1; i++)
    {
        PushQueue(queue, i + 1);
    }
    ShowQueue(queue);
    // 出队列
DeleteQueue(queue);
ShowQueue(queue);
    return 0;
}
