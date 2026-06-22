#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SAVE_LIVE "save.txt"//文件保存名字
#define SUBJECT 3           //学科数量
#define MENU_H 17           //菜单总高度
#define MENU_W 42           //菜单总宽度
#define DISTANCE_H  5       //菜单离边界距离高度
#define DISTANCE_W  10      //菜单离边界距离宽度

typedef struct 
{
    int stnum;
    float subject[SUBJECT];
    float av;
}st;

st *student = NULL;
size_t count = 0;

void menu();
int print(int *q);
void Type();
void List();
int empty();
void Sort();
void Average();
void System_clear();
void savewrite();
int loadwrite();
void SL();
void Sort2();

int main(int argc, char const *argv[])
{
    st student_old[100] = {0};
    student = student_old;
    // printf("1s-%d", student[0].stnum);
    int q = 1;
    menu();
    while(q)
    {
        print(&q);
    }
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
    printf("O = 按学号由高到底排序");
    printf("\033[%d;%dH", DISTANCE_H + 9, DISTANCE_W + 10);
    printf("S = 按学号查询学生成绩");
    printf("\033[%d;%dH", DISTANCE_H + 10, DISTANCE_W + 10);
    printf("C = 清屏");
    printf("\033[%d;%dH", DISTANCE_H + 11, DISTANCE_W + 10);
    printf("X = 存储系统");
    printf("\033[%d;%dH", DISTANCE_H + 12, DISTANCE_W + 10);
    printf("Q = 退出系统");
    printf("\033[%d;%dH", DISTANCE_H + 14, DISTANCE_W + 7);
    printf("按ALT + F4打开作者隐藏小彩蛋");
    printf("\033[%d;%dH", DISTANCE_H + MENU_H - 1, DISTANCE_W + 5);
    printf("Copyright <C> 2011.06.12 By 姓名");
    
    printf("\033[%d;%dH", DISTANCE_H + MENU_H + 2, 0);

    // printf("\033[0;0H");
}

void Type()
{
    printf("请输入学生人数");
    int len = 0, i = 0;
    scanf("%d", &len);
    for (; student[i].stnum != 0; i++);
    printf("%d", i);
    printf("请输入3名学生的三门课成绩:\n");
    printf("学号 语文 数学 外语\n");
    for (size_t j = 0; j < len; j++)
    {
        student[i + j].stnum = i + j + 1;
        printf(" %d   ", student[i + j].stnum);
        for (size_t t = 0; t < SUBJECT; t++)
        {
            scanf(" %f", &student[i + j].subject[t]);
        }
        count++;     
    }
}

void List()
{
    if (empty())return;
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

}

void Average()
{
    if (empty())return;
    for (size_t i = 0; i < count; i++)
    {
        student[i].av = 0;
        for (size_t t = 0; t < SUBJECT; t++)
        {
            student[i].av += student[i].subject[t];
        }
        student[i].av /= SUBJECT;
    }
    printf("平均分已计算。");
    List();
}

void Sort()
{
    if (empty())return;
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = 0; j < count - i - 1; j++)
        {
            if (student[j].av > student[j + 1].av)
            {
                int f1 = student[j].stnum;
                student[j].stnum = student[j + 1].stnum;
                student[j + 1].stnum = f1;
                for (size_t t = 0; t < SUBJECT; t++)
                {
                    float f2 = student[j].subject[t];
                    student[j].subject[t] = student[j + 1].subject[t];
                    student[j + 1].subject[t] = f2;
                }
                float f3 = student[j].av;
                student[j].av = student[j + 1].av;
                student[j + 1].av = f3;
            }
        }
    }
    printf("已按平均分排序。\n");
    List();
}

void Sort2()
{
    if (empty())return;
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = 0; j < count - i - 1; j++)
        {
            if (student[j].stnum > student[j + 1].stnum)
            {
                int f1 = student[j].stnum;
                student[j].stnum = student[j + 1].stnum;
                student[j + 1].stnum = f1;
                for (size_t t = 0; t < SUBJECT; t++)
                {
                    float f2 = student[j].subject[t];
                    student[j].subject[t] = student[j + 1].subject[t];
                    student[j + 1].subject[t] = f2;
                }
                float f3 = student[j].av;
                student[j].av = student[j + 1].av;
                student[j + 1].av = f3;
            }
        }
    }
    printf("已按学号分排序。\n");
    List();
}

void Search()
{
    if (empty())return;
    int l= 0;
    printf("输入要查询的学生学号:");
    scanf("%d", &l);
    printf("学生成绩如下\n");
    printf("学号\t语文\t数学\t外语\t平均分\n");
    printf(" %d\t", student[l].stnum);
    for (size_t t = 0; t < SUBJECT; t++)
        {
            printf("%.1f\t", student[l].subject[t]);
        }
    printf(" %.1f\n", student[l].av);


}

void System_clear()
{
    system("clear");
}

int empty()
{
    if (!count)
    {
        printf("成绩表为空！请先使用命令 T 录入学生成绩。\n");
        return 1;
    }
    return 0;
}

int print(int *q)
{
    printf("请输入命令=");
    char abc;
    scanf(" %c", &abc);
    switch(abc)
    {
        case 'H':
        case 'h':
        menu();
        break;
        case 'T':
        case 't':
        Type();
        break;
        case 'A':
        case 'a':
        Average();
        break;
        case 'L':
        case 'l':
        List();
        break;
        case 'P':
        case 'p':
        Sort();
        break;
        case 'O':
        case 'o':
        Sort2();
        break;
        case 'S':
        case 's':
        Search();
        break;
        case 'C':
        case 'c':
        System_clear();
        break;
        case 'Q':
        case 'q':
        *q = 0;
        break;
        case 'X':
        case 'x':
        SL();
        break;
    }
}

void SL()
{
    char sl = 0;
    printf("是否存储或读取记录?\n"
           "     E     D\n");
    scanf(" %c", &sl);
    if (sl == 'E' || sl == 'e')
    {
        savewrite();
        printf("存储成功\n");
    }
    else if (sl == 'D' || sl == 'd')
    {
        loadwrite();
        printf("读取成功\n");
    }
    else
    {
        printf("录入失败\n");
    }

}

void savewrite()
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

int loadwrite()
{
    FILE *fp = fopen(SAVE_LIVE, "r");
    if (!fp) {printf("读取失败"); return -1;}
    //读取学生个数
    fscanf(fp, "%ld", &count);
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

