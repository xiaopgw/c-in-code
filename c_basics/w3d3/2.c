#include <stdio.h>
#include <string.h>
// typedef struct student
// {
//     int ID;
//     char name[20];
//     int Ch;
//     int Ma;
//     int En;
// } st;

// int main(int argc, char const *argv[])
// {
//     printf("\033[38;2;255;255;200m");
//     st five[5];
//     int len = sizeof(five) / sizeof(five[0]);
//     for (int i = 0; i < len; i++)
//     {
//         scanf("%d %s %d %d %d", 
//             &five[i].ID, five[i].name, &five[i].Ch, &five[i].Ma, &five[i].En);
//         printf("ID:%d学生的姓名是:%s,他的三门课平均成绩为%d\n", 
//             five[i].ID, five[i].name, (five[i].Ch + five[i].Ma + five[i].En) / 3);
//     }
//     return 0;
// }

void Aa(char *s[], int l);
void abc(char *s[], int l);
void ij(char *s[], int l);
int lenn(char *s[]);


int main()
{
    char *str[10] = {"a1B2c3", "Hello", "C"};
    printf("%c\n", str[0][3]);
    
    int len = lenn(str);
    // printf("%d\n", len);
    // Aa(str, len);
    // abc(str, len);
    // ij(str, len);
}

int lenn(char *s[])
{
    int l = 0;
    while (s[l] != 0)
    {
        l++;
    }
    return l;
}
void Aa(char *s[], int l)
{
    if (s == 0)
    {
        printf("NULL");
        return;
    }
    for (int i = 0; i < l; i++)
    {
        printf("%d\n", i);
        if (s[i] == NULL)return 0;
        for (int j = 0; s[i][j] != 0; j++)
        {
            printf("%d\n", j);
            if(s[i][j] < 'A' || s[i][j] > 'z' || 
              (s[i][j] > 'Z' && s[i][j] < 'a'));
            else if (s[i][j] >= 'A' && s[i][j] <= 'Z')
            {
                s[i][j] += ' ';
            }
            else
            {
                s[i][j] -= ' ';
            }
        }
    }
}
void abc(char *s[], int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - 1 - i; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0);
            {
                for (int t = 0; s[j][t] != 0 || s[j + 1][t] != 0; t++)
                {
                    s[j][t] ^= s[j + 1][t];
                    s[j + 1][t] ^= s[j][t];
                    s[j][t] ^= s[j + 1][t];
                }
            }
        }
    }
}
void ij(char *s[], int l)
{
    for (int i = 0; i < l; i++)
    {
        // printf("%d", i);
        for (int j = 0; s[i][j] != 0; j++)
        {
            // printf("%d", j);
            printf("%c", s[i][j]);
        }
        putchar(10);
    }
}