#include <stdio.h>
// 55
int main(int argc, char const *argv[])
{
  for (int i = 1, z = 0; i <= 10; i++)
  {
    z += i;
    if (i == 10)
      printf("%d\n", z);
  }
  // 判断两数之间偶数和
  int a = 0, b = 0, c = 0, i = 0;
  printf("请先输入一个阿拉伯数字\n");
  scanf("%d", &a);
  if (getchar() != '\n')
  {
    printf("你丫输什么呢\n");
    return -1;
  }
  printf("请再输入一个阿拉伯数字\n");
  scanf("%d", &b);
  if (getchar() != '\n')
  {
    printf("你丫输什么呢\n");
    return -1;
  }
  if (a > b)
  {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  }
  if (a % 2 == 0)
  {
    i = a;
  }
  else
  {
    i = a + 1;
  }
  for (; i <= b; i += 2)
  {
    c += i;
  }
  printf("%d\n", c);
}