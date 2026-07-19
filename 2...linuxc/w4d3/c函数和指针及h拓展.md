# 条件编译
编译器根据条件的真假，决定是否编译相关的代码
## 根据宏是否定义
```c
#ifdef 宏名
// 如果有宏名则执行这里
#else
// 如果没有宏名则执行这里
#endif
```
## 根据宏的值是否为真
```c
#if 宏名
// 如果宏名值为真 (非0
#else
// 如果宏名值为假 (0
#endif
```
## 根据宏是否定义
功能：防止头文件被重复包括
```c
#ifndef 宏
#define 宏
//如果没定义过宏名则执行` 
#endif
```
# 指针函数
本质是函数，返回指针
数据类型 函数名()
{
    return 指针;
}
```c
int *fun()
{
    static int arr[3] = {1, 2, 3};  //需要放在静态区或全局区否则函数结束就销毁了
    return arr; //返回指针
}
```
# 函数指针
本质是指针，指向函数
格式:
返回值类型(指针变量名)(参数类型列表);
参数类型:和函数参数一致
```c
int add(int a, int b) { return a + b;}

int (*p)(int, int) = add;
int result = p(3, 4);
```
可用typedef简化重定义
```c
typedef int (*MathAdd)(int, int);
MathAdd = add;
```
# 函数指针数组
本质是数组，存放函数指针
格式:
数据类型 (*数组名[元素个数])(参数列表)
```c
int add(int a, int b) { return a + b;}
int sub(int a, int b) { return a - b;}
int mul(int a, int b) { return a * b;}

int (*ops[3])(int, int) = {add, sub, mul};
int result = ops[0](3, 4);  //调用第一个数组第一个函数
```
## 回调函数
函数指针作为另一个函数的参数，实现"回调"

函数指针作为函数参数
```c
void test(int (*p)(int, int), int a, int b)
{
    int r = p(a, b);
    printf("%d\n", r);
}
```
这个函数指针可以随时调换，比如从指向add换成指向sub，更改起来就比较方便








