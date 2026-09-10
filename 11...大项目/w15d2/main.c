#include <stdio.h>
#include "cJSON.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // //读取文件
    // FILE *fp = fopen("json.json", "r");
    // if (fp == NULL)
    // {
    //     perror("fp->");
    //     return -1;
    // }
    // char buf[2048] = {};
    // size_t len = fread(buf, 1, 2048, fp);
    // printf("%s\n------------------------------\n", buf);
    // cJSON *root = cJSON_Parse(buf);
    // if(NULL == root)
    // {
    //     printf("parse err\n");
    //     return -1;
    // }

    // //获取名字叫"ver"的节点值
    // cJSON *item = cJSON_GetObjectItem(root, "ver");
    // printf("ver = %s\n", item->valuestring);
#ifdef SFFD
    // 获取文件
    FILE *fp = fopen("json.json", "r");
    char buf[2048] = {};
    size_t fpread = fread(buf, 1, 2048, fp);
    printf("%s\n------------------------\n", buf);
    // 创建树
    cJSON * master = cJSON_Parse(buf);
    // 读取名叫ver的子节点
    cJSON *ver = cJSON_GetObjectItem(master, "ver");
    printf("ver = %s\n", ver->valuestring);
    // 读取login的子节点
    cJSON *login = cJSON_GetObjectItem(master, "login");
    cJSON *user = cJSON_GetObjectItem(login, "user");
    cJSON *pwd = cJSON_GetObjectItem(login, "pwd");
    printf("user = %s, pwd = %d\n", user->valuestring, pwd->valueint);
    // 读取data子节点
    cJSON *data = cJSON_GetObjectItem(master, "data");
    int len = cJSON_GetArraySize(data);
    for (int i = 0; i < len; i++)
    {
        cJSON *arr = cJSON_GetArrayItem(data, i);
        cJSON *key = cJSON_GetObjectItem(arr, "key");
        printf("key%d = %d, ", i, key->valueint);
        cJSON *type = cJSON_GetObjectItem(arr, "type");
        printf("type%d = %d, ", i, type->valueint);
        cJSON *val = cJSON_GetObjectItem(arr, "val");
        printf("val%d = %s, ", i, val->valuestring);
        putchar(10);
    }
    putchar(10);
#else

    // 创建一个根节点
    cJSON *root = cJSON_CreateObject();
    // 创建一个值为小明的子节点
    cJSON *name = cJSON_CreateString("XIAOPGW");
    // 把他连接到根节点
    cJSON_AddItemToObject(root, "name", name);

    // 创建版本号
    cJSON *level = cJSON_CreateNumber(1.12);
    cJSON_AddItemToObject(root, "level", level);
    // 创建
    cJSON *boold = cJSON_CreateNumber(100);
    cJSON_AddItemToObject(root, "boold", boold);
    // 对象
    cJSON *object = cJSON_CreateObject();
    cJSON *ark = cJSON_CreateNumber(6);
    cJSON_AddItemToObject(object, "ark", ark);
    cJSON *up = cJSON_CreateString("%%30");
    cJSON_AddItemToObject(object, "up", up);
    cJSON_AddItemToObject(root, "object", object);
    // 数组
    cJSON *arr = cJSON_CreateArray();
    cJSON *art1 = cJSON_CreateNumber(100);
    cJSON *art2 = cJSON_CreateNumber(200);
    cJSON_AddItemToArray(arr, art1);
    cJSON_AddItemToArray(arr, art2);

    cJSON *xiaopgw = cJSON_CreateObject();
    cJSON_AddItemToObject(xiaopgw, "模仿", cJSON_CreateNumber(6));
    cJSON_AddItemToObject(xiaopgw, "摸摸头", cJSON_CreateNumber(6));
    cJSON_AddItemToArray(arr, xiaopgw);

    cJSON_AddItemToObject(root, "arr", arr);
    // 查看当前根节点内容
    char *buf = cJSON_PrintUnformatted(root);
    printf("%s\n", buf);

    // 释放空间
    cJSON_Delete(root);
    free(arr);
#endif
    return 0;
}
