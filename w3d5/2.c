#include <stdio.h>

void c();


void b()
{
    printf("1");
    c();
}

void c()
{
    b();
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        
    }
    
    
    
    return 0;
}

