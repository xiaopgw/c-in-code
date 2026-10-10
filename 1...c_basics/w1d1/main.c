#include <stdio.h>
#define a 25
int main(int argc, char const *argv[])
{
    
    #ifdef a
    printf("%d", a);
    #endif
    // int a, b;
    // for(a = 1, b= 1; a<= 100; a++)
    // {
    //     if(b>=10)
    //     break;
    //     if (b % 3 == 1)
    //     {
    //         b+=3;
    //         continue;
    //     }
    // }
    // printf("%d\n", a);

//     int k = 4, m = 1, p;
//     p = func(k, m);
//     p = func(k, m);
//     printf("%d", p);
//     return 0;
// }
// func(int a, int b)
// {
//     static int m = 0, i = 2;
//     i += m + 1;
//     m = i + a + b;
//     return (m);

    // __uint8_t Data[10] = {0x98, 0x68, 0x00, 0x52, 0x21, 0x37, 0x50, 0x41,0x38, 0x27};
    // for(int i = 0; i < 10; i++)
    // {
    //     char a = Data[i];
    //     char b = Data[i] >> 4;
    //     Data[i] = a << 4 | b;
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%#x,", Data[i]);
    // }

    // char * p = "18190";
    // printf("%c", *p++);
    // printf("%c", p[1]);

    #ifdef a
    printf("%d", a);
    #endif
    return 0;
}