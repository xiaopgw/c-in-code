#include"my.h"
int main(int argc, char const *argv[])
{
    dboffset_p link = CreateLinklist();
    for (int i = 0; i < 8; i++)
    {
        PushLinkList(link, i, i + 1);
    }
    PushLinkList(link, 1, 64);
    PushLinkList(link, 2, 32);
    PushLinkList(link, 4, 16);
    PushLinkList(link, 8, 8);

    ShowDoubleLinkList(link);
    // 狠狠的抽出
    PopLinkList(link, 1);
    PopLinkList(link, 1);
    PopLinkList(link, 2);
    PopLinkList(link, 8);
    ShowDoubleLinkList(link);




    return 0;
}
