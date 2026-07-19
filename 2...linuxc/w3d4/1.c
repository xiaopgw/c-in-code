#include <stdio.h>
enum b
{
    n1,
    n2,
    n3,
    n4,
    n5,
}a;

int main()
{
    // enum b c;
    // a = 4;
    // a = n1;
    // a = 4;
    // c = n5;
    // c = 1;
    // printf("%d\n", n1);
    int count = 0;
    char a[] = "abc      defg   h i jk       lm        n";
    printf("%s\n", a);

    char b[20] = {0};
    int len = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < len; i++)
    {
        if (a[i] != 32)
        {
            b[count] = a[i];
            count++;
        }
    }
    printf("%s\n", b);
}
//可以更简单，把赋值给a中;