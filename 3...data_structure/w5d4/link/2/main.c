#include"my.h"
int main(int argc, char const *argv[])
{
    linkoffset_p queue = CreateQueue();
    for (int i = 0; i < 8; i++)
    {
        PushQueue(queue, i + 1);
    }
    ShowQueue(queue);
    PopQueue(queue);
    ShowQueue(queue);
    return 0;
}
