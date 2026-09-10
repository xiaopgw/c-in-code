#include <stdio.h>
#include "cJSON.h"
#include <stdlib.h>
#include <string.h>
#define N 2048

// 序列化
// 反序列化
// 链接到服务器

int main(int argc, char const *argv[])
{
    char send[N] = {};
    char recv[N] = {};

    while (1)
    {

        scanf("%s", send);
        cJSON *stree = cJSON_CreateObject();
        if (stree == NULL)
        {
            perror("tree->");
            return -1;
        }

        cJSON_AddItemToObject(stree, "name", cJSON_CreateString("name"));
        cJSON_AddItemToObject(stree, "age", cJSON_CreateNumber(16));
        cJSON_AddItemToObject(stree, "msg", cJSON_CreateString(send));

        char *tree = cJSON_Print(stree);
        // printf("%s\n", tree);

        cJSON_Delete(stree);
        free(tree);
        // 缺一个发送到网页
        memset(send, 0, sizeof(send));

        cJSON *rtree = cJSON_Parse(recv);
        cJSON *Rname = cJSON_GetObjectItem(rtree, "name");
        cJSON *Rage = cJSON_GetObjectItem(rtree, "age");
        cJSON *Rmsg = cJSON_GetObjectItem(rtree, "msg");

        printf("名字%s年龄%d信息%s\n", Rname->valuestring, Rage->valueint, Rmsg->valuestring);
    }

    return 0;
}
