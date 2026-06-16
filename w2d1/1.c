// #include <stdio.h>
// int main(int argc, char const *argv[])
// {

//     int arr[] = {1, 1, 2, 2, 2, 2, 2, 2, 2};
//     int m = 0;
//     int ar2[9] = {0};
//     for (int i = 0; i < 9; i++)
//     {
//         ar2[m] = arr[i];
//         for (int j = i; j < 8; j++)
//         {
//             if (arr[j] == arr[j + 1])
//             {
//                 i++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         m++;
//     }
//     for (int i = 0; i < 9; i++)
//     {
//         if (i != 0)
//         {
//             if (ar2[i] == 0)
//             {
//                 break;
//             }
//         }
//         printf("%d", ar2[i]);
//     }
// }

#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf(" %d", arr[i]);
        }
    }
    return 0;
}