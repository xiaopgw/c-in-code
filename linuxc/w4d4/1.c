#include"my.h"

int main()
{
    int arr[64] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int post = 5;
    int data = 788;
    int l = 0;
    // l = InsertIntoA(arr, n, post, data);
    l = DeleteFromA(arr, n, post);
    Show(arr, l);
}


