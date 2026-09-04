# Day1
# 1、C++与C语言的关系
C++ 保留了 C 语言的大部分语法，并增加了类、对象、继承、多态、函数重载等能力。学员已经学过 C，因此本课程不重新讲变量、循环、数组和指针，而是重点学习 C++ 对程序结构的组织方式。

# 2、C++特点
1、在支持C语言的基础上，全面支持面向对象编程。
2、编程领域广泛，功能强大（最难的编程语言之一）。
3、C++语言的标准还一直保持着更新，本次课程主要以ISO C++98标准为主。
4、为数不多的支持低层操作的面向对象编程语言。
5、在面向对象的语言中执行效率极高。

# 3、面向对象编程的重要知识点
- 类
- 对象
- 封装
- 继承
- 多态
封装 、 继承、 多态 也被称为面向对象编程的三大特性。

# 4、面向过程与面向对象的区别
【例子】：把大象装进冰箱需要几步？
1、打开冰箱
2、把大象放进去
3、关闭冰箱
程序会编写成一组函数，数据在函数之间传递。

面向对象中关注“对象”。
- 大象具有移动等行为
- 冰箱具有打开、关闭、保存物品的功能。
- 程序通过对象之间的调用完成任务。

● 面向过程
主要关注”怎么做“
把程序拆成一步一步的流程、函数，以步骤为核心，数据和函数分离。
代表语言C语言

● 面向对象
关注”谁来做“
把程序拆解为对象（实体），将数据（属性）+操作数据的方法封在一起。
代表语言：java、C++、python

面向过程：按照流程解决问题
面向对象：把事物拆分类别，依靠类别的实体协作解决问题。

# 5、环境搭建
单纯论C++的开发环境，没有严格的要求，为了学习的方便，直接使用后面课程的开发环境。即QtCreator。
安装完成后 为了使其支持中文输出，更改下面的编码：
![图片](https://docimg4.docs.qq.com/image/AgAABovvK89BsZ3h-eRBlY_OGHLe4rF-.png?w=231&h=276)
![图片](https://docimg6.docs.qq.com/image/AgAABovvK8_mrxuwaDxIf62RaSGu79-_.png?w=1003&h=581)
设置完成后，重新启动Qt Creator，就可以新建一个C++的项目了。

1、点击
![图片](https://docimg3.docs.qq.com/image/AgAABovvK89s0DCimfxAw4k7rWBOL-Gn.png?w=159&h=50)
2、在弹出的窗口中，按照下图所示进行操作
![图片](https://docimg2.docs.qq.com/image/AgAABovvK8_JWB_j8cFGNJx48IyKA_os.png?w=882&h=556)

3、 在弹出的窗口中，输入项目名称，在设定项目路径，最后点击下一步。需要注意的是不得出现任何的中文字符和特殊字符。
![图片](https://docimg8.docs.qq.com/image/AgAABovvK89IkZiSSX9AIKf6a2XL7-7l.png?w=902&h=448)

4、在弹出的窗口中，直接点击下一步即可。
![图片](https://docimg6.docs.qq.com/image/AgAABovvK899uj5Ukw1KmYrZWblAnhDT.png?w=901&h=453)

5、在项目管理界面，直接点击完成
![图片](https://docimg6.docs.qq.com/image/AgAABovvK8_LBvzu3jZM0qxEBoZwI-jJ.png?w=898&h=446)

6、可以看到新项目中包含了两个文件
![图片](https://docimg6.docs.qq.com/image/AgAABovvK8_FsYGzEApIiKeqQfN8uWV4.png?w=318&h=190)
.pro文件为项目配置文件，通常无需手动编辑。

.cpp文件为C++的源代码文件，用于编写C++代码。
```cpp
// 包含头文件，标准输入输出流
// 在C++源码中，头文件不需要包含.h
#include <iostream>

// 使用标准名字空间，不要删
using namespace std;

// 主函数，程序的入口
int main()
{
    // 连续输出一个字符串和换行符
    cout << "Hello World!" << endl;
    // 返回一个0
    return 0;
}
```

点击左下角的小三角（快捷键：ctrl+R），即可运行项目
![图片](https://docimg1.docs.qq.com/image/AgAABovvK8_MMcNOd1hJBbTJAqHOr8U1.png?w=456&h=217)
补充几个快捷键的使用技巧：
1、ctrl+c 复制
2、ctrl+v 粘贴
3、ctrl+R 编译+运行
4、Alt+0 显式和隐藏边栏
5、ctrl+A 全选 ，再点击ctrl+i 对齐。    本页全部代码排版
6、ctrl+F搜索+替换
7、ctrl+z 回滚
8、ctrl+s 保存


# 6、键盘输入
可以使用cin把用户再命令行中输入的内容赋值到变量中。
```cpp
#include <iostream>


using namespace std;


int main()
{
    int a;

    // C++的字符串类型
    string str;

    cout << "请输入一个数字和字符串" << endl;
    cin >> a >> str;    // 接收键盘的输入，一个整数和一个字符串，可以连续操作
    cout << a << " " << str << endl;

    return 0;
}
```

如果cin输入的字符串需要包含空格，则可以使用下面的方式：
```cpp
#include <iostream>


using namespace std;


int main()
{
    // C++的字符串类型
    string str;

    cout << "请输入一个字符串" << endl;

    getline(cin,str);
    cout << str << endl;
    return 0;
}
```

# 7、引用

## 7.1 概念
指针相当于对于某一目标变量起一个别名。
      操作引用与操作原变量完全相同。
    ```cpp
#include <iostream>

using namespace std;


int main()
{
    int a = 1;
    // 表示b是a的引用
    int &b = a;

    cout << a << " " << &a << endl; // 1 0x61fe88
    cout << b << " " << &b << endl; // 1 0x61fe88
    return 0;
}
```
## 7.2 引用的特点
可以改变引用的值，但是不能再次成为其他变量的引用。
```cpp
#include <iostream>

using namespace std;


int main()
{
    int a = 1;
    // 表示b是a的引用
    int &b = a;

    int c = 3;
    b = c;  // 只是赋值，不是引用，此时b还是a的引用

    cout << a << " " << &a << endl; // 3 0x61fe88
    cout << b << " " << &b << endl; // 3 0x61fe88
    return 0;
}
```
声明引用时，必须要做初始化。
```cpp
#include <iostream>

using namespace std;


int main()
{
    int a = 1;

    int &b; // 错误，引用必须初始化

    cout << a << " " << &a << endl; // 3 0x61fe88
//    cout << b << " " << &b << endl; // 3 0x61fe88
    return 0;
}
```
声明引用的时候，不能直接初始化为NULL，如果想要给NULL取别名，需要使用const关键字修饰。
```cpp
#include <iostream>

using namespace std;


int main()
{
    int a = 1;

//    int &b = NULL; // 错误不能直接给NULL取别名
    const int &b = NULL; // 如果要给NULL取别名，需要const

    cout << a << " " << &a << endl; // 3 0x61fe88
    cout << b << " " << &b << endl; // 3 0x61fe88
    return 0;
}
```
声明引用的时候，初始化的值可以是纯数值，但是需要使用const进行修饰，表示该引用为常量引用，这样引用的值不可变。
```cpp
#include <iostream>

using namespace std;


int main()
{
    const int &b = 12;
//    b++; // 错误常量引用的数值无法被改变
    cout << b << " " << &b << endl;
    return 0;
}
```
## 7.3 引用作为函数参数
```cpp
#include <iostream>

using namespace std;

// 值传递
//void swap_value(int a,int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}

// 引用传递
void swap_value(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a1 = 10;
    int b1 = 20;
    swap_value(a1,b1);
    cout << a1 << " " << b1 << endl;
    return 0;
}
```

## 7.4 const 引用参数
如果函数只想读取参数，不修改参数，可以使用const引用。
```cpp
#include <iostream>

using namespace std;

void print_string(const string &str)
{
//    str = "world";
    cout << str << endl;
}

int main()
{
    string str1 = "hello";
    print_string(str1);
    cout << str1 << endl;
    return 0;
}
```

# 8、string 字符串类
string不是C++的基本数据类型，它是一个C++标准库中的字符串类，使用时需要引入头文件#include<string>不包含.h。
string 在绝大多数的情况下可以代替C语言的字符数组，不必担心内存是否足够和字符串长度等问题。其中还包含了很多字符串处理函数，可以完成各种情况下的字符串处理功能。

```cpp
#include <iostream>

using namespace std;

int main()
{
    string str = "helloworld";
    cout << str.size() << endl; // 10
    cout << str.length() << endl; // 10

    cout << str[1] << endl; // e
    cout << str.at(1) << endl; // e
    return 0;
}
```
两种方式都可以，但是在C++中更推荐使用at函数，原因是at函数更安全。但是[ ]的方式效率更高。
```cpp
#include <iostream>

using namespace std;

int main()
{
    string str = "helloworld";
    cout << str.size() << endl; // 10
    cout << str.length() << endl; // 10

//    cout << str[1] << endl; // e
    cout << str.at(100) << endl; // e
    cout << "helloworld" << endl;
    return 0;
}
```
string可以使用for循环将数据进行取出。
```cpp
#include <iostream>

using namespace std;

int main()
{
    string str = "helloworld";
    for(int i = 0; i < str.size(); ++i)
    {
        cout << str.at(i);
    }
    return 0;
}
```

# 9、函数重载
C++中允许多个函数使用同一个名称，这种用法就是函数重载。函数重载要求函数名称相同，但是参数不同（类型、数量、前后顺序）。与返回值等其他类型无关。
```cpp
#include <iostream>

using namespace std;

void print_show(int i)
{
    cout << "调用了int1重载:" << i << endl;
}

void print_show(int i,int i2)
{
    cout << "调用了int2重载:" << i << i2 << endl;
}


void print_show(double d)
{
    cout << "调用了double重载:" << d << endl;
}

void print_show(string s)
{
    cout << "调用了string重载:" << s << endl;
}


// 错误，返回值类型，不能作为重载条件
//double print_show(int i)
//{
//    cout << "调用了int1重载:" << i << endl;
//}

int main()
{
    print_show(1);
    return 0;
}
```

# 10、类与对象
## 10.1 概念
类：类是一个抽象的概念，用于描述同一类对象的特点。
对象：根据类的概念所创造的实体。

【思考】：一个对象可以没有对应的类吗？
不可以。

## 10.2 类的内容
类中最基础的内容包括两个部分，，一个是属性，一个是行为。
属性：表示一些特征项的数值，例如：身高、体重、年龄。颜色、型号等等，这些特征项的数值一般使用变量进行存储，而类中的变量也被称为“成员变量”。
行为：表示能执行的动作， 能做什么事情。例如：吃饭、睡觉、打游戏等，行为一般通过函数来实现，而类中的函数也被称为“成员函数”。

【例子】以手机为例，来说明类的定义。
规定手机能播放音乐、运行游戏、打电话。手机有品牌、型号、重量属性。
```cpp
#include <iostream>

using namespace std;

// 帕斯卡命名法（大驼峰命名法）
// 每个单词首字母是大写
class MobilePhone
{
public:     // 权限：public公有权限（最开放的权限）
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

    // 成员函数（行为）
    void play_music()
    {
        cout << "只因你太美，哒哒哒" << endl;
    }

    void run_game()
    {
        cout << "王者荣耀、元神启动、三角洲行动" << endl;
    }

    void call()
    {
        cout << "歪歪歪 你好呀" << endl;
    }

};

int main()
{

    return 0;
}
```

    ## 10.3 对象的创建
    在C++中存在两种类型的对象。
    栈内存对象
    对象所在的{}执行完毕后，自动被销毁。
    ```cpp
#include <iostream>

using namespace std;

// 帕斯卡命名法（大驼峰命名法）
// 每个单词首字母是大写
class MobilePhone
{
public:     // 权限：public公有权限（最开放的权限）
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

    // 成员函数（行为）
    void play_music()
    {
        cout << "只因你太美，哒哒哒" << endl;
    }

    void run_game()
    {
        cout << "王者荣耀、元神启动、三角洲行动" << endl;
    }

    void call()
    {
        cout << "歪歪歪 你好呀" << endl;
    }

};


int main()
{
    MobilePhone mp; // 栈内存对象mp
    mp.brand = "小米";
    mp.model = "15";
    mp.weight = 300;

    cout << mp.brand << " " << mp.model << " " << mp.weight << endl;

    mp.play_music();
    mp.run_game();
    mp.call();

    return 0;
}
```
    
    
    堆内存对象
必须使用new关键字创建，使用指针存储，使用delete销毁空间。如果不使用delete销毁，则堆内存对象将会持续存在，从而导致内存泄漏。
```cpp
#include <iostream>

using namespace std;

// 帕斯卡命名法（大驼峰命名法）
// 每个单词首字母是大写
class MobilePhone
{
public:     // 权限：public公有权限（最开放的权限）
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

    // 成员函数（行为）
    void play_music()
    {
        cout << "只因你太美，哒哒哒" << endl;
    }

    void run_game()
    {
        cout << "王者荣耀、元神启动、三角洲行动" << endl;
    }

    void call()
    {
        cout << "歪歪歪 你好呀" << endl;
    }

};


int main()
{
    MobilePhone* mp  = new MobilePhone; // 堆内存对象
    mp->brand = "华为";
    mp->model = "mate 80";
    mp->weight = 300;

    cout << mp->brand << " " << mp->model << " " << mp->weight << endl;

    mp->play_music();
    mp->run_game();
    mp->call();
    
    delete mp;  // 手动销毁
    
    return 0;
}
```

# 11、封装
在上一节中MobilePhone类与结构体差别不大，实际上可以认为结构体就是一种完全开放的类。
封装指的是，将类的一些属性和行为进行隐藏，重新提供外部的访问接口。封装可以提升代码的安全性，并且可以让程序员更关注上层架构而非内部细节。
```cpp
#include <iostream>

using namespace std;


// 要求（针对于类外）：
// 品牌：可以访问，可以修改
// 型号：可以访问，不能修改
// 重量：不能访问，只能修改
class MobilePhone
{
private:    // 权限：私有权限，也是最封闭权限，只能在类内访问
    // 成员变量（属性）
    string brand;   // 品牌
    string model = "14pro";   // 型号
    int weight;     // 重量

public:     // 权限：public公有权限（最开放的权限）
    // 品牌：可以访问
    string get_brand()
    {
        return brand;
    }

    // 可以修改
    void set_brand(string b)
    {
        brand = b;
    }

    // 型号：可以访问
    string get_model()
    {
        return model;
    }

    // 重量：只能修改
    void set_weight(int w)
    {
        weight = w;
    }
};


int main()
{
    MobilePhone* mp  = new MobilePhone; // 堆内存对象
    mp->set_brand("华为");
    mp->set_weight(300);

    cout << mp->get_brand() << " " << mp->get_model() << endl;

    delete mp;  // 手动销毁

    return 0;
}
```

# 12、构造函数
## 12.1 基本使用
构造函数是一种特殊的成员函数，用于创建对象时初始化。创建对象时必须直接或者间接调用当前类的任意一个构造函数，写法上有以下的要求：
1、函数名称必须与类名完全相同
2、创建对象时自动调用
3、构造函数没有返回值类型
4、可以进行重载
5、如果程序员不编写构造函数，编译器会自动添加一个无参的构造函数
![图片](https://docimg4.docs.qq.com/image/AgAABovvK88sPCy5exJHuZliOTD0g3oX.png?w=844&h=270)
手动添加构造函数后， 编译器将不会再自动添加默认无参构造函数了。
- 构造函数再创建对象时，常用于给对象的属性赋予初始值
```cpp
#include <iostream>

using namespace std;


class MobilePhone
{
private:    // 权限：私有权限，也是最封闭权限，只能在类内访问
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

public:     // 权限：public公有权限（最开放的权限）

    MobilePhone()
    {
        brand = "小米";
        model = "60 pro";
        weight = 200;
    }

    string get_brand()
    {
        return brand;
    }

    string get_model()
    {
        return model;
    }

    int get_weight()
    {
        return weight;
    }
};


int main()
{
    cout << "程序开始执行" << endl;
    MobilePhone* mp  = new MobilePhone; // 堆内存对象

    cout << mp->get_brand() << endl;
    cout << mp->get_model() << endl;
    cout << mp->get_weight() << endl;

    delete mp;  // 手动销毁

    return 0;
}
```
- 构造函数也支持函数重载
```cpp
#include <iostream>

using namespace std;


class MobilePhone
{
private:    // 权限：私有权限，也是最封闭权限，只能在类内访问
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

public:     // 权限：public公有权限（最开放的权限）

    MobilePhone()
    {
        brand = "小米";
        model = "60 pro";
        weight = 200;
    }

    // 有参构造函数
    MobilePhone(string b, string m,int w)
    {
        brand = b;
        model = m;
        weight = w;
    }

    string get_brand()
    {
        return brand;
    }

    string get_model()
    {
        return model;
    }

    int get_weight()
    {
        return weight;
    }
};


int main()
{
    cout << "程序开始执行" << endl;
    MobilePhone* mp  = new MobilePhone("8848","钛金手机",500); // 堆内存对象

    cout << mp->get_brand() << endl;
    cout << mp->get_model() << endl;
    cout << mp->get_weight() << endl;

    delete mp;  // 手动销毁

    MobilePhone mp2;        // 调用无参构造函数
    MobilePhone mp3("vivo","70",300); // 调用有参构造函数

    return 0;
}
```

## 12.2 构造初始化列表
构造初始化列表是一种更简单的给成员变量赋予初始值的写法。
```cpp
#include <iostream>

using namespace std;


class MobilePhone
{
private:    // 权限：私有权限，也是最封闭权限，只能在类内访问
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

public:     // 权限：public公有权限（最开放的权限）


    MobilePhone()
        :brand("小米"),model("60 pro"),weight(200)
    {
        cout << "构造函数被执行了" << endl;
//        brand = "华为";
    }

    // 有参构造函数
    MobilePhone(string b, string m,int w)
    {
        brand = b;
        model = m;
        weight = w;
    }

    string get_brand()
    {
        return brand;
    }

    string get_model()
    {
        return model;
    }

    int get_weight()
    {
        return weight;
    }
};


int main()
{
    MobilePhone mp2;        // 调用无参构造函数
    cout << mp2.get_brand() << endl;
    cout << mp2.get_model() << endl;
    cout << mp2.get_weight() << endl;

//    MobilePhone mp3("vivo","70",300); // 调用有参构造函数

    return 0;
}
```
当构造函数的局部变量与成员变量重名时，除了使用后面学习的this指针之外，也可以使用构造初始化列表来区分。
![图片](https://docimg2.docs.qq.com/image/AgAABovvK8-ADUKseplBTqn-NHRhDFte.png?w=1380&h=220)
## 12.3 拷贝构造函数
### 12.3.1 概念
当程序员不手动编写拷贝构造函数时，编译器会自动添加一个拷贝构造函数，使对象的创建可以通过这个构造函数实现。
![图片](https://docimg6.docs.qq.com/image/AgAABovvK8-jw3Eqya5Kc6BZ36FAKQQg.png?w=1043&h=375)
```cpp
#include <iostream>

using namespace std;


class MobilePhone
{
private:    // 权限：私有权限，也是最封闭权限，只能在类内访问
    // 成员变量（属性）
    string brand;   // 品牌
    string model;   // 型号
    int weight;     // 重量

public:     // 权限：public公有权限（最开放的权限）


    MobilePhone()
        :brand("小米"),model("60 pro"),weight(200)
    {
        cout << "构造函数被执行了" << endl;
//        brand = "华为";
    }

    // 有参构造函数
    MobilePhone(string brand, string model,int weight)
        :brand(brand),model(model),weight(weight)
    {
    }

    // 手动编写编译器默认添加的拷贝构造函数
    MobilePhone(const MobilePhone &mp)
    {
        brand = mp.brand;
        model = mp.model;
        weight = mp.weight;
    }

    string get_brand()
    {
        return brand;
    }

    string get_model()
    {
        return model;
    }

    int get_weight()
    {
        return weight;
    }
};


int main()
{
    MobilePhone mp1("小米","13",300); // 调用有参构造函数，栈内存对象

    MobilePhone mp2(mp1);   // 调用拷贝构造函数
    cout << mp2.get_brand() << endl;
    cout << mp2.get_model() << endl;
    cout << mp2.get_weight() << endl;

    return 0;
}
```

### 12.3.2 浅拷贝

```cpp
#include <iostream>
#include <string.h>

using namespace std;

class Dog
{
private:
    char *name;
public:
    Dog(char *n)
    {
        name = n;
    }

    void show_name()
    {
        cout << name << endl;
    }
};


int main()
{
    char arr[20] = "旺财";
    Dog d1(arr);    // 调用有参构造函数
    Dog d2(d1);     // 调用拷贝构造函数

    strcpy(arr,"大黄");

    d1.show_name(); // 大黄
    d2.show_name(); // 大黄


    return 0;
}
```
![图片](https://docimg9.docs.qq.com/image/AgAABovvK89ltKkxo-1J4Y6OGN_-W7Lf.png?w=1204&h=519)
这种情况必须手动编写拷贝构造函数，使每次赋值都创建一个新的副本，从而让每个对象单独持有自己的成员变量。这种方式也被称为“深拷贝”。

### 12.3.3 深拷贝
![图片](https://docimg2.docs.qq.com/image/AgAABovvK88fEe6yO1tNZ5NeUEPWmN2v.png?w=1108&h=708)
```cpp
#include <iostream>
#include <string.h>

using namespace std;

class Dog
{
private:
    char *name;
public:
    Dog(char *n)
    {
        name = new char[20];
        strcpy(name,n);
    }

    // 拷贝构造函数
    Dog(const Dog &d)
    {
        name = new char[20];
        strcpy(name,d.name);
    }

    void show_name()
    {
        cout << name << endl;
    }
};


int main()
{
    char arr[20] = "旺财";
    Dog d1(arr);    // 调用有参构造函数
    Dog d2(d1);     // 调用拷贝构造函数

    strcpy(arr,"大黄");

    d1.show_name(); // 旺财
    d2.show_name(); // 旺财


    return 0;
}
```

# 13、 析构函数
析构函数是与构造函数对立的函数。
|构造函数|析构函数|
|创建对象时手动调用|当对象销毁时，自动调用|
|函数名称是类名|函数名称是~类名|
|构造函数可以重载|析构函数没有参数，不能进行重载|
|用于创建对象时初始化|用于销毁对象时释放资源|
|没有返回值|没有返回值|

            构造函数
            析构函数
            创建对象时手动调用
            当对象销毁时，自动调用
            函数名称是类名
            函数名称是~类名
            构造函数可以重载
            析构函数没有参数，不能进行重载
            用于创建对象时初始化
            用于销毁对象时释放资源
            没有返回值
            没有返回值
```cpp
#include <iostream>
#include <string.h>

using namespace std;

class Dog
{
private:
    char *name;
public:
    Dog(char *n)
    {
        name = new char[20];
        strcpy(name,n);
    }

    // 拷贝构造函数
    Dog(const Dog &d)
    {
        name = new char[20];
        strcpy(name,d.name);
    }

    void show_name()
    {
        cout << name << endl;
    }

    ~Dog()
    {
        cout << "析构函数被调用了" << endl;
        delete []name;  // []表示销毁的是连续的空间
    }
};


int main()
{
    char arr[20] = "旺财";
    Dog d1(arr);    // 调用有参构造函数
    Dog d2(d1);     // 调用拷贝构造函数

    strcpy(arr,"大黄");

    d1.show_name(); // 旺财
    d2.show_name(); // 旺财


    return 0;
}

---

# 附：Day1 核心知识点总结

## 1. C++ 与 C 的关系
- C++ 保留 C 的大部分语法，新增类、对象、继承、多态、函数重载等面向对象能力。

## 2. C++ 特点
- 全面支持面向对象；领域广泛、功能强大；标准持续更新（本课以 C++98 为主）；支持底层操作；面向对象语言中执行效率极高。

## 3. 面向对象三大特性
- 封装、继承、多态。

## 4. 面向过程 vs 面向对象
- 面向过程：关注"怎么做"，把程序拆成步骤和函数，数据与函数分离（代表：C）。
- 面向对象：关注"谁来做"，把程序拆成对象，将数据（属性）与操作数据的方法（行为）封装在一起（代表：C++、Java、Python）。

## 5. 引用
- 概念：给变量起别名，操作引用与操作原变量完全相同（地址相同）。
- 特点：
  1. 声明时必须初始化；
  2. 一旦绑定不能再成为其他变量的引用（后续的 = 只是赋值）；
  3. 不能直接初始化为 NULL（给 NULL 取别名需 const）；
  4. 初始化为纯数值需 const（常量引用，值不可变）。
- 引用作函数参数：函数内修改会影响实参（区别于值传递）。
- const 引用参数：只想读取、不修改参数时使用。

## 6. string 字符串类
- 标准库字符串类（非基本类型），需 #include<string>（不带 .h）。
- 可替代字符数组，自动管理长度和内存。
- size()/length() 求长度；[ ] 和 at() 取字符，at() 更安全（越界检测），[ ] 效率更高。

## 7. 函数重载
- 同名函数、参数不同（类型/数量/顺序）即构成重载；与返回值类型无关。

## 8. 类与对象
- 类：抽象概念，描述一类对象的特点；对象：根据类创建的实体。
- 类包含：属性（成员变量）+ 行为（成员函数）。
- 命名：帕斯卡（大驼峰）命名法，每个单词首字母大写。
- 对象两种：
  - 栈内存对象：作用域（{}）结束自动销毁；
  - 堆内存对象：new 创建、指针存储、必须 delete 销毁，否则内存泄漏。

## 9. 封装
- 将属性和行为隐藏，对外提供访问接口，提升安全性。
- 权限：public（公有，类内外都可访问）、private（私有，仅类内访问）。
- 通过 getter（访问）/ setter（修改）函数对外提供接口。

## 10. 构造函数
- 特点：函数名与类名相同、创建对象时自动调用、无返回值、可重载、不写则编译器自动添加无参构造函数（手动添加后不再自动添加默认无参）。
- 用于创建对象时初始化属性。
- 构造初始化列表：`类名() : 成员(初值), 成员(初值) {}`，更简洁，也可区分成员变量与局部变量重名。
- 拷贝构造函数：不写则编译器自动添加；手动编写用 `类名(const 类名 &对象)` 形式，实现对象复制。

## 11. 浅拷贝 vs 深拷贝
- 浅拷贝：默认拷贝构造只复制指针值，多个对象指向同一块内存，一改全改。
- 深拷贝：手动编写拷贝构造，为成员重新分配内存并复制内容，使每个对象独立持有数据；含指针成员时必须深拷贝。

## 12. 析构函数
- 与构造函数对立，对象销毁时自动调用。
- 函数名是 ~类名，无参数、不能重载、无返回值。
- 用于销毁对象时释放资源（如 delete 堆空间）。

```