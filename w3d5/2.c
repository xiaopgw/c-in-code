#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    char arr[10] = "abc";
    for (size_t i = 0; arr[i]; i++)
    {
        printf("%c", arr[i]);
    }
    
    return 0;
}
