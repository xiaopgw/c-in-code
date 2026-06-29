#include <stdio.h>

int main() {
    int n;
    // scanf("%d", &n);  // 运行时用户输入：5
    // int arr[n];  
    // printf("数组大小：%zu 字节\n", sizeof(arr));  // 20 字节
    // int *p = 0;
    int *p = "hello";
    printf("%c\n", *p);
    printf("%p\n", p);
    return 0;
}
