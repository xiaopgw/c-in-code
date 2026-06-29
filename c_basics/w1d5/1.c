#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    // int a = 0;
    // scanf("%d", &a);
    // for (int i = 1; i <= a; i++)
    // {
    //     for (int j = 0; j < i - 1; j++)
    //         {
    //             printf(" ");
    //         }
    //     for (int t = 0; t < a - i; t++)
    //     {
    //         printf("*");
    //     }
    //     putchar(10);
    // }
    // int i = 1, l = 0;
    // while(i < 2000)
    // {
    //     int t = 0;
    //     for (int j = 1; j < i / 2; j++)
    //     {
    //         if(i % j == 0)
    //         {
    //             t += j;
    //         }
    //     }
    //     if (t == i)
    //     {
    //         printf("%d\n", t);
    //     }
    //     i++;
    // }
    // srand(time(NULL));
    // printf("来瞧一瞧，看一看，猜猜1~10，三次机会，三次机会，搏一搏，单车变摩托！！！\n");
    // int a = rand() % 10 + 1, b = 0, i = 0;
    // while (i < 3)
    // {
    //     scanf("%d", &b);
    //     if(b == a)
    //     {
    //         printf("哈哈哈，可惜可惜~欸~~~~~你猜中啦！！！\n");
    //         return 0;
    //     }
    //     else if (b > a)
    //         printf("哦哟~可惜~数字大了~\n");
    //     else
    //         printf("恭喜你！！！~~~数字小了~\n");
    //     i++;
    // }
    // printf("太棒啦，恭喜你~~~~~你的次数用完了，正确答案是~~~%d\n", a);
    // int man = 0;
    // while(1)
    // {
    //     man++;
    //     if (man >= 10)
    //     break;
    //     printf("-%d,--%d,---%d\n", man, 20 - man * 2, 10 + man);

    // }

    // int a = 0, aa = 0, c = 0;
    // scanf("%d %d", &a, &aa);
    // for (int i = 0; i < aa; i++)
    // {
    //     int b = 0;
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         b = b * 10 + a;
    //     }
    //     c = c + b;
    // }
    // printf("%d\n", c);
    // return 0;

    // 回文数
    int num = 0, one = 0, ten = 0, hundred = 0, thousand = 0, ten_thousand = 0;
    do
    {
        scanf("%d", &num);
        ten_thousand = num / 10000;
        thousand = num / 1000 % 10;
        hundred = num / 100 % 10;
        ten = num / 10 % 10;
        one = num % 10;
        if (num == 0)
        {
            printf("程序结束\n");
            return 0;
        }
        else if (ten_thousand == one && thousand == ten)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    } while (1);

    // 三角形
    float line_a = 0, line_b = 0, line_c = 0;
    scanf("%f %f %f", &line_a, &line_b, &line_c);
    if (line_a < line_b)
    {
        line_a = line_a + line_b;
        line_b = line_a - line_b;
        line_a = line_a - line_b;
    }
    if (line_a < line_c)
    {
        line_a = line_a + line_c;
        line_c = line_a - line_c;
        line_a = line_a - line_c;
    }
    if (line_b < line_c)
    {
        line_b = line_b + line_c;
        line_c = line_b - line_c;
        line_b = line_b - line_c;
    }
    if (line_b + line_c <= line_a)
    {
        printf("不存在\n");
    }
    else if (line_a == line_b && line_b == line_c)
    {
        printf("等边三角形\n");
    }
    else if (line_b == line_c && line_b * line_b + line_c * line_c == line_a * line_a)
    {
        printf("这是等腰直角三角形，但却是你永远都达不到的事实，所以我要在这里放一个我的小秘密，（降低音量，不用声带发音说悄悄话（其实我的眼睛度数已经超过我的眼镜的度数啦o（>_<）o））\n");
    }
    else if (line_b == line_c)
    {
        printf("等腰三角形\n");
    }
    else if (line_b * line_b + line_c * line_c == line_a * line_a )
    {
        printf("直角三角形\n");
    }
    else
    {
        printf("普通三角形\n");
    }

    //输出该日在今年的天数
    int year = 0, month = 0, day = 0;
    scanf("%d %d %d", &year, &month, &day);
    for (int i = 1; i < month; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            day += 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            day += 30;
        }
        if(i == 2)
        {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                day += 29;
            }
            else
            {
                day += 28;
            }
        }
    }
    printf("%d\n", day);

    //2的幂判断
    int power = 0, num2 = 1;
    scanf("%d", &power);
    while (num2 <= power)
    {
        if (power == num2)
        {
            printf("Y\n");
            return 0;
        }
        num2 *= 2;
    }
    printf("N\n");
    return 0;
}
