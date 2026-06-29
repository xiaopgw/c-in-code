#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAP_WIDTH 60
#define MAP_HEIGHT 25
#define DISTANCE_X 26
#define DISTANCE_Y 3
#define BLACKSQUARE "■"
#define WHITESQUARE "□"
#define SNAKEHEAD "⊙"
#define SNAKEBODY "●"
#define SNAKELENGTH 3
#define SNAKEMAX 1500
#define WIN 1500

void map();
void disappear();
void food_position();
void snake_head();
void init_termios();
void restore_kbhit();
int kbhit();
int getch();
void movesnake(int *direct);
void snake_longlong();
int uwin();
int ufail();
int ufail_k();

// 食物结构体
struct Food
{
    int x;
    int y;
} food;
// 蛇结构体
struct Snake
{
    int x[SNAKEMAX];
    int y[SNAKEMAX];
    int snakelength;
} snake;
struct termios orig_termios;    // 保留终端原始数据

// 主函数
int main(int argc, char const *argv[])
{
    printf("\033[2J");                      //清屏
    printf("\033[?25l");                    //隐藏光标
    init_termios();                         //隐藏输入并自动确认
    snake_head();                           //初始化蛇
    int direct = 'a';                       //行走方向初始化
    srand(time(NULL));                      //随机数初始化
    food_position();                        //第一个食物
    map();                                  //打印地图
    while (1)                               //循环打印
    {
        
        fflush(stdout);                     //循环实时显示刷新画面
        movesnake(&direct);                 //循环显示蛇的移动
        snake_longlong();                   //生成食物
        usleep(100000);                      //休息0.5秒
        if(uwin() == 1 || ufail() == 1)     //检查是否结束
        {
            return 0;
        }
    }
    return 0;
}
//失败重复段
int ufail_k()
{
    printf("\033[%d;%dH", MAP_HEIGHT / 2 + DISTANCE_Y, MAP_WIDTH / 2 + DISTANCE_X - 5);
    printf("BAD END");
    restore_kbhit();     //终端还原
    printf("\033[?25h"); //显示光标
    fflush(stdout);
    return 1;
}
//失败条件
int ufail()
{
    int i = 1;
    while (i < snake.snakelength)
    {
        if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
        {
            return ufail_k();
        }
        i++;
    }
    // if (snake.x[0] == 3 && snake.y[0] == 26)
    // return ufail_k();
    int x = 0, y = 0;
    for (int i = 0; i < MAP_WIDTH; i += 2)
    {
        if (snake.x[0] == x + i + DISTANCE_X && snake.y[0] == y + DISTANCE_Y)
        {
            return ufail_k();
        }
    }
    for (int i = 0; i < MAP_WIDTH; i += 2)
    {
        if (snake.x[0] == x + i + DISTANCE_X && snake.y[0] == y + MAP_HEIGHT + DISTANCE_Y)
        {
            return ufail_k();
        }
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        if (snake.x[0] == x + DISTANCE_X && snake.y[0] == y + i + DISTANCE_Y)
        {
            return ufail_k();
        }
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        if (snake.x[0] == x + DISTANCE_X + MAP_WIDTH - 2 && snake.y[0] == y + i + DISTANCE_Y)
        {
            return ufail_k();
        }
    }

}
//胜利条件
int uwin()
{
    if (snake.snakelength == WIN)
    {
        printf("\033[%d;%dH", MAP_HEIGHT / 2 + DISTANCE_Y, MAP_WIDTH / 2 + DISTANCE_X - 5);
        printf("HAPPY END");
        return 1;
        restore_kbhit();     //终端还原
        printf("\033[?25h"); //显示光标
        fflush(stdout);
    }
}
// 创建地图
void map()
{
    int x = 0, y = 0;
    for (int i = 0; i < MAP_WIDTH; i += 2)
    {
        printf("\033[%d;%dH", y + DISTANCE_Y, x + i + DISTANCE_X);
        printf(BLACKSQUARE);
    }
    for (int i = 0; i < MAP_WIDTH; i += 2)
    {
        printf("\033[%d;%dH", y + MAP_HEIGHT + DISTANCE_Y, x + i + DISTANCE_X);
        printf(BLACKSQUARE);
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        printf("\033[%d;%dH", y + i + DISTANCE_Y, x + DISTANCE_X);
        printf(BLACKSQUARE);
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        printf("\033[%d;%dH", y + i + DISTANCE_Y, x + DISTANCE_X + MAP_WIDTH - 2);
        printf(BLACKSQUARE);
    }

    // printf("\033[?25l");
    // printf("\033[0;95H");
}
// 光标测试
void disappear()
{
    printf("\033[?25l");
    printf("光标消失\n");
    sleep(1);
    printf("\033[?25h");
    printf("光标回旋\n");
}
// 生成食物
void food_position()
{
    int end = 1;
    while (end)
    {
        while (1)
        {
            food.x = rand() % 56 + 2 + DISTANCE_X;
            if (food.x % 2 == 0)
                break;
        }
        food.y = rand() % 24 + 1 + DISTANCE_Y;
        int i = 0;
        while (i < snake.snakelength)
        {
            if (food.x == snake.x[i] || food.y == snake.y[i])
            {
                end = 1;
                break;
            }
            i++;
            end = 0;
        }
    }
    printf("\033[%d;%dH", food.y, food.x);
    printf(WHITESQUARE);
}
// //蛇蛇存储
// int old_sx()
// {
//     int old_sx = snake.x[snake.snakelength - 1];
//     return old_sx;
// }
// int old_sy()
// {
//     int old_sy = snake.y[snake.snakelength - 1];
//     return old_sy;
// }
//蛇蛇伸长
void snake_longlong()
{
    if (snake.x[0] == food.x && snake.y[0] == food.y)
    {
        // printf("\033[%d;%dH", sy, sx);
        // printf(SNAKEBODY);
        snake.snakelength++;
        food_position();
    }
}
// //删除尾巴
// void snake_longlong_delete(int sx, int sy)
// {
//     printf("\033[%d;%dH", sy, sx);
//     printf(SNAKEBODY);
// }
// 初始化蛇 
void snake_head()
{
    snake.snakelength = SNAKELENGTH;
    snake.x[0] = 54;
    snake.y[0] = 16;
    printf("\033[%d;%dH", snake.y[0], snake.x[0]);
    printf(SNAKEHEAD);
    for (int i = 1; i < snake.snakelength; i++)
    {
        snake.x[i] = snake.x[i - 1] + 2;
        snake.y[i] = snake.y[i - 1];
        printf("\033[%d;%dH", snake.y[i], snake.x[i]);
        printf(SNAKEBODY);
    }
}
//遍历蛇

// 上下左右
// int direct = 'a';
void movesnake(int *direct)
{
    fflush(stdout);
    printf("\033[%d;%dH", snake.y[snake.snakelength - 1], snake.x[snake.snakelength - 1]);
    printf("  ");
    fflush(stdout);
    for (int i = snake.snakelength - 1; i > 0; i--)
    {
        snake.x[i] = snake.x[i - 1];
        snake.y[i] = snake.y[i - 1];
    }
    for (int i = snake.snakelength - 1; i > 0; i--)
    {
        printf("\033[%d;%dH", snake.y[i], snake.x[i]);
        // printf("\033[%d;%dH", snake.y[2], snake.x[2]);
        printf(SNAKEBODY);
    }
    fflush(stdout);
    if (kbhit())
    {
        char getcha = getch();
        if (getcha == 'w' || getcha == 's' || getcha == 'a' || getcha == 'd' ||
            getcha == 'w' || getcha == 's' || getcha == 'a' || getcha == 'd')
            *direct = getcha;
        // int c = getch();
        // if (c != -1)
        // {
        //     direct = getch();
        // }
    }

    switch (*direct)
    {
        case 'w':
        snake.y[0]--;
        break;
        case 's':
        snake.y[0]++;
        break;
        case 'a':
        snake.x[0] -= 2;
        break;
        case 'd':
        snake.x[0] += 2;
        break;
    }
    printf("\033[%d;%dH", snake.y[0], snake.x[0]);
    printf(SNAKEHEAD);
    fflush(stdout);
}

// kbhit()
// 把保留终端初始化，然后设置新变量，禁用字符显示和回车（行缓冲和回显），更改新变量为阻塞模式，始终端只读一个字符，然后把新变量设置换到当前
void init_termios()
{
    struct termios new_termios;

    // 获取当前终端的数据
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;

    // 更改为阻塞模式
    new_termios.c_lflag &= ~(ICANON | ECHO);

    // 变更为阻塞模式
    new_termios.c_cc[VMIN] = 1;
    new_termios.c_cc[VTIME] = 0;

    // 更新设置
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    // 设置文件状态的非阻塞
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);      // 用flags读取当前文件状态
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // 吧当前文件状态的阻塞格改成阻塞模式，并设置（F_SETFL）
}
// 恢复终端状态
void restore_kbhit()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
}
// 检测是否有按键
int kbhit()
{
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}
// 读取按键
int getch()
{
    getchar();
    // char c;
    // if (read(STDIN_FILENO, &c, 1) == 1)
    // return c;
}