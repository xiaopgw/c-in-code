#include <stdio.h>
#include <sqlite3.h>
int main(int argc, char const *argv[])
{
    char *err_m;
    sqlite3 *db;
    int sq = sqlite3_open("sqlite3_ku", &db);
    if (sq != SQLITE_OK)
    {
        fprintf(stderr, "sq->%s\n", sqlite3_errmsg(db));
        return -1;
    }
    printf("成功打开数据库\n");

    const char *create_sql = "CREATE TABLE IF NOT EXISTS XIAOPGW ("
                         "id INTEGER PRIMARY KEY,"
                         "name TEXT NOT NULL,"
                         "score INT);";
    int sq = sqlite3_exec(db, create_sql, NULL,NULL, &err_m);


    return 0;
}
