#include <stdio.h>
int main(int argc, char const *argv[])
{
    //输出整数的所有因子
    int a = 0;
    printf("请输入一个整数型数字，我会输出他的因子\n");
    scanf("%d", &a);
    if (getchar() != '\n' || a <= 0) {printf("咱们输点正常的东西就行了，不正常的……输进来不太好\n"); return -1;}
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0) printf("%d\n", i);
    }
    //按输入输出2的个数
    int c = 0;
    long long b = 0;
    printf("请输入一个整数型的比19小、比0大的数字\n");
    scanf("%d", &c);
    if (getchar() != '\n' || c <= 0) {printf("你这输进来的是正常的东西吗，竟敢玷污本小姐，爬！\n"); return -1;}
    if (c > 19) {printf("本小姐最大只能接受19的，再大就塞不进来了，回去重修吧！\n"); return -1;}
    for (int i = 0; i < c; i++)
    {
        b = 2 + b * 10;
    }
    printf("%lld\n", b);
    return 0;
}
