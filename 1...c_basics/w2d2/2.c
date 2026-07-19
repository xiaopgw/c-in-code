#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // char arr[] = {};
    // printf("%ld\n", sizeof(arr));
    // int a = strlen(arr);
    // printf("%d\n", a);
    // char a[] = "a\r\\\182";
    // int len = sizeof(a) / sizeof(a[0]);
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%c|\n", a[i]);
    // }

    // printf("%c\n", '\102');
    // scanf("%s", arr);
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int len = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < len - 1; i++)
    // {
    //     for (int j = 0; j < len - 1 - i; j++)
    //     {
    //         if (arr[j] < arr[j + 1]) // 这里应该是j
    //         {
    //             arr[j] ^= arr[j + 1];
    //             arr[j + 1] ^= arr[j];
    //             arr[j] ^= arr[j + 1];
    //         }
    //     }
    // }

    // for (int i = 0; i < len - 1; i++)
    // {
    //     int m = i;
    //     for (int j = 1 + i; j < len; j++)
    //     {
    //         if (arr[m] < arr[j])
    //         {
    //             m = j;
    //         }
    //     }
    //     if (i != m)
    //     {
    //         int t = 0;
    //         t = arr[m];
    //         arr[m] = arr[i];
    //         arr[i] = t;
    //     }
    // }
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    // char arr[5] = "abcde";
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%c\n", arr[i]);
    // }
    // char *p = &arr[4];
    // printf("%d\n", arr[5]);
    // printf("%d\n", *p);
    // printf("%d\n", *(p + 1));
    // *(p + 1) = 1;
    // printf("_%s\n", arr);
    // int arr[2][3] = {0};
    // printf("%ld\n", sizeof(arr));


    // char arr[2][3] = {"he"};
    // printf("%s\n", arr);


    // int arr[3][4] = {{1, 2, 3, 4}, {5, 12, 7, 8}, {9, 10, 11, 12}};
    // int len = sizeof(arr) / sizeof(arr[0][0]) / 4;
    // // printf("-%d\n", len);
    // int max1 = 0, max2 = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (arr[max1][max2] < arr[i][j])
    //         {
    //             max1 = i;
    //             max2 = j;
    //         }
    //     }
    // }

    // printf("%d%d", max1 + 1, max2 + 1);

    // int arr[2][3] = {1,2,3,4,5,6};
    // printf("%d\n", arr[1]);

    // int arr[10][10] = {0};
    // arr[0][0] = 1;
    // for (int i = 1; i < 10; i++)
    // {
    //     arr[i][0] = 1;
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    //     }
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         printf("%-3d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

printf(
"1\n"
"1   1\n"
"1   2   1\n"
"1   3   3   1\n"
"1   4   6   4   1\n"
"1   5   10  10  5   1\n"
"1   6   15  20  15  6   1\n"
"1   7   21  35  35  21  7   1\n"
"1   8   28  56  70  56  28  8   1\n"
"1   9   36  84  126 126 84  36  9   1\n"
);
}
