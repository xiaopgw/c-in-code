#include <stdio.h>
#include <sqlite3.h>
int main(int argc, char const *argv[])
{
    // 设置指向库的结构体的指针
    sqlite3 *db = NULL;
    // 打开库
    if (sqlite3_open("mc.db", &db) != SQLITE_OK)
    {
        // 报错处理
        if (db != NULL)
        {
            printf("创建/打开库错误，%s\n", sqlite3_errmsg(db));
            return -1;
        }
        else
        {
            printf("其他库错误\n");
        }
    }
    else
    {
        printf("成功打开库\n");
    }

    // 关闭库
    if (sqlite3_close(db) == SQLITE_OK)
    {
        printf("成功关闭库\n");
    }
    // 
    sqlite3_exec(db, );
    return 0;
}
