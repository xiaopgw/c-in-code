#include <stdio.h>
#include <string.h>

int my_strcmp(const char *s1, const char *s2);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);

int main(int argc, char const *argv[])
{
    // int arr[10] = {0};
    // int *p = arr;
    // printf("%ld\n", sizeof(arr));
    // printf("%ld\n", sizeof(p));
    // return 0;
    char arr3[32] = "aaaaa";
    char arr4[33] = "caaaa";
    printf("%d\n", strcmp(arr3, arr4));
    char arr1[32] = "hello";
    char arr2[32] = "world";
    printf("%s\n", my_strcat(arr1, arr2));
    printf("%s\n", arr1);
    strcpy(arr1, "");
    printf("%s\n", arr1);
    printf("%s\n", my_strcpy(arr1, arr2));
    printf("%s\n", arr1);
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (1)
    {
        if (s1[i] == '\0' && s2[i] == '\0')
        {
            return 0;
        }
        else if (s1[i] == s2[i])
        {
            i++;
        }
        else if (s1[i] > s2[i])
        {
            return s1[i] - s2[i];
        }
        else
        {
            return s2[i] - s1[i];
        }
    }
}

char *my_strcat(char *dest, const char *src)
{
    int l = 0;
    while (1)
    {
        if (dest[l] == '\0')
        {
            break;
        }
        l++;
    }
    int i = 0;
    while (1)
    {
        if (src[i] == '\0')
        {
            return dest;
        }
        dest[l + i] = src[i];
        i++;
    }
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (1)
    {
        if (src[i] == '\0')
        {
            return dest;
        }
        else
        {
            dest[i] = src[i];
            i++;
        }
    }
}
