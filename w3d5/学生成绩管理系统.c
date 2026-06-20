#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SAVE_LIVE "save.txt"//文件保存名字
#define SUBJECT 3           //学科数量
#define MENU_H 16       //菜单总高度
#define MENU_W 42        //菜单总宽度
#define DISTANCE_H  5        //菜单离边界距离高度
#define DISTANCE_W  10       //菜单离边界距离宽度

typedef struct 
{
    int stnum;
    float subject[SUBJECT];
    float av;
}st;

st *student = NULL;
size_t count = 0;

void menu();
int print();
void Type();
void List();




int main(int argc, char const *argv[])
{
    st student_old[100] = {0};
    student = student_old;
    // printf("1s-%d", student[0].stnum);

    menu();
}

void menu()
{
    printf("\033[2J");
    printf("\033[%d;%dH", DISTANCE_H, DISTANCE_W);
    for (size_t i = 0; i < MENU_W; i++) printf("*");
    printf("\033[%d;%dH", DISTANCE_H + 2, DISTANCE_W);
    for (size_t i = 0; i < MENU_W; i++) printf("*");
    printf("\033[%d;%dH", DISTANCE_H + MENU_H - 2, DISTANCE_W);
    for (size_t i = 0; i < MENU_W; i++) printf("*");
    printf("\033[%d;%dH", DISTANCE_H + MENU_H, DISTANCE_W);
    for (size_t i = 0; i < MENU_W; i++) printf("*");
    for (size_t i = 0; i < MENU_H; i++)
    {   
        printf("\033[%ld;%dH", DISTANCE_H + i, DISTANCE_W + 2);
        printf("*");
    }
    for (size_t i = 0; i < MENU_H; i++)
    {   
        printf("\033[%ld;%dH", DISTANCE_H + i, DISTANCE_W + MENU_W - 3);
        printf("*");
    }

    printf("\033[%d;%dH", DISTANCE_H + 1, DISTANCE_W + 7);
    printf("学生成绩管理系统——帮助菜单");
    printf("\033[%d;%dH", DISTANCE_H + 3, DISTANCE_W + 10);
    printf("H = 显示帮助菜单");
    printf("\033[%d;%dH", DISTANCE_H + 4, DISTANCE_W + 10);
    printf("T = 成绩录入");
    printf("\033[%d;%dH", DISTANCE_H + 5, DISTANCE_W + 10);
    printf("A = 计算学生平均分");
    printf("\033[%d;%dH", DISTANCE_H + 6, DISTANCE_W + 10);
    printf("L = 列出成绩表");
    printf("\033[%d;%dH", DISTANCE_H + 7, DISTANCE_W + 10);
    printf("P = 按平均成绩由高到底排序");
    printf("\033[%d;%dH", DISTANCE_H + 8, DISTANCE_W + 10);
    printf("S = 按学号查询学生成绩");
    printf("\033[%d;%dH", DISTANCE_H + 9, DISTANCE_W + 10);
    printf("C = 清屏");
    printf("\033[%d;%dH", DISTANCE_H + 10, DISTANCE_W + 10);
    printf("X = 存储系统");
    printf("\033[%d;%dH", DISTANCE_H + 11, DISTANCE_W + 10);
    printf("Q = 退出系统");
    printf("\033[%d;%dH", DISTANCE_H + 13, DISTANCE_W + 7);
    printf("按ALT + F4打开作者隐藏小彩蛋");
    printf("\033[%d;%dH", DISTANCE_H + MENU_H - 1, DISTANCE_W + 5);
    printf("Copyright <C> 2011.06.12 By 姓名");
    
    printf("\033[%d;%dH", DISTANCE_H + MENU_H + 2, 0);
    printf("请输入命令=");

    // printf("\033[0;0H");
    print();
}

void Type()
{
    printf("请输入学生人数");
    int len = 0, i = 0;
    scanf("%d", &len);
    printf("1s-%d", student[i].stnum);
    for (; student[i].stnum != 0; i++);
    printf("2s-%d", student[i].stnum);
    printf("i-%d", i);
    printf("请输入3名学生的三门课成绩:\n");
    printf("学号 语文 数学 外语\n");
    for (size_t j = 0; j < len; j++)
    {
        student[i + j].stnum = j + 1;
        printf(" %d   ", student[i + j].stnum);
        for (size_t t = 0; t < SUBJECT; t++)
        {
            scanf(" %f", &student[i + j].subject[t]);
        }
        count++;     
    }

    printf("请输入命令=");
    print();
}

void List()
{
    printf("学生成绩如下\n");
    printf("学号\t语文\t数学\t外语\t平均分\n");
    for (size_t i = 0; i < count; i++)
    {
        printf(" %d\t", student[i].stnum);
        for (size_t t = 0; t < SUBJECT; t++)
        {
            printf("%.1f\t", student[i].subject[t]);
        }
        printf(" %.1f\n", student[i].av);
    }
    printf("请输入命令=");
    print();
}

int print()
{
    char abc;
    scanf(" %c", &abc);
    switch(abc)
    {
        case 'H':
        case 'h':
        menu();
        return abc;
        case 'T':
        case 't':
        Type();
        return abc;
        case 'A':
        case 'a':
        return abc;
        case 'L':
        case 'l':
        List();
        return abc;
        case 'P':
        case 'p':
        return abc;
        case 'S':
        case 's':
        return abc;
        case 'C':
        case 'c':
        return abc;
        case 'Q':
        case 'q':
        return abc;
        case 'X':
        case 'x':
        return abc;
    }
}

void savewrite(const st *student)
{
    FILE *fp = NULL;
    fp = fopen(SAVE_LIVE, "w");
    if (!fp) {printf("保存失败"); return;}
    //写入学生个数
    fprintf(fp, "%ld\n", count);
    //写入数据
    for (size_t i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n", student[i].stnum);
        for (size_t j = 0; j < SUBJECT; j++)
        {
            fprintf(fp, "%.1f\n", student[i].subject[j]);
        }
        fprintf(fp, "%.1f\n", student[i].av);
    }
    
    
    fclose(fp);
}

int loadwrite (st *student)
{
    FILE *fp = fopen(SAVE_LIVE, "r");
    if (!fp) {printf("读取失败"); return -1;}
    //读取数据
    for (size_t i = 0; i < count; i++)
    {
        if(fscanf(fp, "%d", &student[i].stnum) != 1) {printf("没有读到%ld同学的成绩", i);return -1;}
        for (size_t j = 0; j < SUBJECT; j++)
        {
            if (fscanf(fp, "%f", &student[i].subject[j]) != 1) {printf("没有读到%ld同学的成绩", i);return -1;}
        }
        if(fscanf(fp, "%f", &student[i].av) != 1) {printf("没有读到%ld同学的成绩", i);return -1;}
    }
    
    
    fclose(fp);
    return 0;
}
