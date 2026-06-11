#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char a[10] = "acdgjmno", b[10] = "befhil";
    char *p = a, *q = b;
    while (1)
    {
        if (*p < *q)
        {
            if (*p == '\0')
            {
                printf("%s", q);
                break;
            }
            else
            {
                printf("%c", *p);
                p++;
            }
        }
        else
        {
            if (*q == '\0')
            {
                printf("%s", p);
                break;
            }
            else
            {
                printf("%c", *q);
                q++;
            }
        }
    }
    printf("\n");
}
