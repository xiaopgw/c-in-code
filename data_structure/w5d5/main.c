#include"my.h"
int main(int argc, char const *argv[])
{
    datatype data = 1;
    // binnode_p root = PushBinary(arr[i]);

    // int arr[] = {1, 2, 3, -1,-1,4,-1,-1,5,6,-1,7,8,9,-1,10,-1,-1};

    // int len = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < len; i++)
    // {
    //     PushBinary(arr[i]);
    // }
    int n = 5;
    binnode_p root = CreateBinary(data, n);
    ShowBinary(root, n);
    // ShowBinary(root);
    
    return 0;
}
