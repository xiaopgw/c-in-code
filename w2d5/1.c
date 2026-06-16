#include <stdio.h>
#include <unistd.h>
#include <string.h>

// int minestrlen();
// int mun_x(char arr[]);
// int sum(int arr[], int n);

// int main(int argc, char const *argv[])
// {
// int a[2][3] = {2, 3, 4, 5, 6, 7};
// int (*p)[3] = a;
// printf("%d\n", *(p[0] + 1));
// printf("%p\n", p + 1);
// printf("%p\n", p);
// int a = 10;
// int b = 20;
// int c = 30;
// int a[3][4] = {0};
// int *arr[3] = {a[0], a[1], a[2]};
// printf("%p\n", &a[2][3]);
// printf("%p\n", arr[2] + 3);
// char *arr[3] = {"he", "ll", "o\n"};
// char *p = *arr;
// printf("%p\n%p\n%p\n", arr[0], *(arr + 1), arr[2]);
// printf("%p\n", arr[4]);
// printf("%s\n", argv[0]);
// printf("%s\n", argv[1]);
// printf("%s\n", argv[2]);
// printf("%s\n", argv[3]);
// int ar[2][5] = {0};
// int (*p)[5] = ar;
// printf("%d\n", argc);
// char arr[32] = "hello";
// printf("%p", num);
// printf("%d\n", num);
// while (1)
// {
//     printf("1");
//     sleep(1);
// }
// return 0;
// char arr[32] = "axsldjflzxlkjxxxxxxxlksldzjflzx";
// printf("%d\n", mun_x(arr));
//     int arr[5] = {1, 2, 3, 4, 5};

//     printf("%d\n", sum(arr, 3));
// }
// int sum(int arr[], int n)
// {
//     if (n <= 0) return 0;
//     return arr[n - 1] + sum(arr, n - 1);
// }

// int minestrlen(char arr[])
// {
//     int s = 0;
//     char *p = arr;
//     while (*p != '\0')
//     {
//         p++;
//         s++;
//     }
//     return s;
// }
// int mun_x(char arr[])
// {
//     int num = 0;
//     for (int i = 0; arr[i] != '\0'; i++)
//     {
//         if (arr[i] == 'x')
//         {
//             num++;
//         }
//     }
//     return num;
// }
// void fun(char *p1, char *p2);
// int main(int argc, char const *argv[])
// {
//     char arr1[32] = "hello";
//     char arr2[32] = "world";
//     fun (arr1, arr2);
//     return 0;
// }
// void fun(char *p1, char *p2)
//     {
//         printf("%s\n", p1);
//         printf("%s\n", p2);
//         int l = strlen(p1);
//         int i = 0;
//         while (*(p2 + i) != '\0')
//         {
//             *(p1 + l + i) = *(p2 + i);
//             i++;
//         }

//         printf("%s\n", p1);
//     }

// 指针数组int验证
//  int main(int argc, char const *argv[])
//  {
//      int a1[4] = {1, 2, 3, 4};
//      int a2[5] = {5, 6, 7, 8, 9};
//      int a3[5] = {10, 11, 12, 13, 14};
//      int a4[2][5] = {{15, 16, 17, 18, 19}, {20, 21, 22, 23, 24}};
//      int *p[5] = {a1, a2, a3, *a4, *(a4 + 1)};
//      printf("%d\n", *(p[0] + 4));
//      printf("%d\n", p[1][4]);
//      printf("%d\n", p[2][4]);
//      printf("%d\n", p[3][4]);
//      printf("%d\n", p[4][4]);
//      printf("%d\n", p[1][0]);

//     return 0;
// }

// 指针数组字符串验证
// int main(int argc, char const *argv[])
// {
    // char a[32] = "world";
    // char *p[2] = {"hello", a};
    // printf("%c\n", *(*p + 1));
    // printf("%d\n", p[0][5]);
    // printf("%s\n", *p);
    // printf("%s\n", *(p + 1));
    // sizeof(p);
//     int a = 6;
//     void *p;
//     int *q = &a;
//     p = q;
//     printf("%d\n", *p);

//     return 0;
// }
char *fun(int b)
{
	// 在栈区开辟10字节，存放hello
    char *a = "hello";
    b = 2;
    return a;          
}
int main(int argc, char const *argv[])
{
    int b = 0;
    printf("%s\n", fun(b));
        printf(" %d\n", b);

    return 0;
}
