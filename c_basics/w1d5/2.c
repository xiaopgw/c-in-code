#include <stdio.h>

int k1(int arr[]);
int k2(int arr[]);
void k3(int arr[]);
void k4(int arr[]);
void num10_2(int num10);

int main()
{
    int k = 0;
    int arr[] = {0, 1, 2, 4, 8, 16, 32, 64, 128};
    scanf("%d", &k);
    if (k == 1)
        num10_2(k1(arr));
    else if (k == 2)
        num10_2(k2(arr));
    else if (k == 3)
        k3(arr);
    else if (k == 4)
        k4(arr);
}

int k1(int arr[])
{
    int k1 = arr[1] | arr[3] | arr[5] | arr[7];
    return k1;
}
int k2(int arr[])
{
    int k2 = arr[2] | arr[4] | arr[6] | arr[8];
    return k2;
}
void k3(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        k1(arr);
        num10_2(k1(arr));
        putchar(10);
        k2(arr);
        num10_2(k2(arr));
        putchar(10);
    }
}
void k4(int arr[])
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 8; i >= 1; i--)
        {
            num10_2(arr[i]);
            putchar(10);
        }
    }

}
//十转二
void num10_2(int num10)
{
    int bits[8] = { 0 }, j = 0;
    while (num10 > 0)
    {
        bits[j++] = num10 % 2;
        num10 = num10 / 2;
    }
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }
}