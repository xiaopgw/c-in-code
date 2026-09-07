# Day2
# 1、作用域限定符::（掌握）
## 1.1 名字空间
```cpp
#include <iostream>

using namespace std;

int a = 2;

namespace my_space
{
    int a = 3;
    int b = 4;
}

// 声明名字空间
using namespace my_space;

int main()
{
    int a = 1;
    cout << a << endl;  // 1
    cout << ::a << endl;    // ::表示全局作用域 2
    cout << my_space::a << endl; // 3
    cout << b << endl;  // 4
    return 0;
}
```

## 1.2 类内声明，类外定义
```cpp
#include <iostream>

using namespace std;

class Demo
{
public:
    // 类内声明
    Demo();
    void test(string str);
};

// 类外定义
Demo::Demo()
{
    cout << "构造函数被调用了" << endl;
}

void Demo::test(string str)
{
    cout << str << endl;
}

int main()
{
    Demo d1;
    d1.test("hello");
    return 0;
}
```

# 2、this指针（掌握）
## 2.1 概念
this指针是一个特殊的指针，指向当前类对象的首地址。
成员函数（包括构造函数与析构函数）中都有this指针，因此this指针只能在类内进行使用。实际上this指向的就是当前成员函数所绑定的对象。
```cpp
#include <iostream>

using namespace std;

class Test
{
public:
    void test_this()
    {
        cout << this << endl;
    }
};

int main()
{
    Test t1;
    cout << &t1 << endl;    // 0x61fe8f
    t1.test_this();     // 0x61fe8f

    Test t2;
    cout << &t2 << endl;    // 0x61fe8e
    t2.test_this();         // 0x61fe8e


    Test *t3 = new Test;
    cout << t3 << endl;     // 0xf529c0
    t3->test_this();        // 0xf529c0
    delete t3;

    return 0;
}
```

## 2.2 功能
### 2.2.1 类内调用成员
- 成员（成员变量+成员函数），必须由对象调用。类中成员的调用都依赖于this指针。通常由编译器自动添加。
```cpp
#include <iostream>

using namespace std;

class Test
{
private:
    string name;
public:
    Test(string n)
    {
        // 编译器默认添加this指针指向的对象，调用成员
        this->name = n;
    }

    string get_name()
    {
        // 编译器默认添加this指针指向的对象，调用成员
        return this->name;
    }
};

int main()
{
    Test t1("zhangsan");
    cout << t1.get_name() << endl;


    Test t2("lisi");
    cout << t2.get_name() << endl;

    return 0;
}
```

### 2.2.2 区分重名的成员变量与局部变量
```cpp
#include <iostream>

using namespace std;

class Test
{
private:
    string name;
public:
    Test(string name)
        :name(name) // 构造初始化列表也能区分
    {
        // 通过this指针区分同名的成员变量与局部变量
        this->name = name;
    }

    string get_name()
    {
        
        return this->name;
    }
};

int main()
{
    Test t1("zhangsan");
    cout << t1.get_name() << endl;


    Test t2("lisi");
    cout << t2.get_name() << endl;

    return 0;
}
```

# 3、static关键字（掌握）
## 3.1 静态成员变量
- 静态成员变量，需要类内声明，类外定义
- 一个类的所有对象共用一份静态成员变量。
- 静态成员变量虽然可以通过对象进行调用，但是更建议直接使用类名加作用域的方式进行调用。（更推荐使用类名::的方式调用，因为代码可读性更好）
- 在程序开始运行时就开辟空间了，直到程序运行结束后进行销毁。
```cpp
#include <iostream>

using namespace std;

class Test
{
public:
    int a = 1;
//    static int b = 2; // 错误，静态成员变量需要类内进行声明，类外定义
    static int b;
};

// 静态成员变量的类外定义
int Test::b = 1;

int main()
{
    // 脱离对象使用
    cout << Test::b << " " << &Test::b << endl;

    Test t1;
    cout << t1.a << " " << &t1.a << endl; // 1 0x61fe8c
    cout << t1.b << " " << &t1.b << endl; // 1 0x403004

    t1.a++;
    t1.b++;
    cout << t1.a << " " << &t1.a << endl; // 2 0x61fe8c
    cout << t1.b << " " << &t1.b << endl; // 2 0x403004

    cout << "-------------------------" << endl;
    Test t2;
    cout << t2.a << " " << &t2.a << endl;   // 1 0x61fe88
    cout << t2.b << " " << &t2.b << endl;   // 2 0x403004


    cout << "-------------------------" << endl;
    Test *t3 = new Test;
    cout << t3->a << " " << &t3->a << endl;
    cout << t3->b << " " << &t3->b << endl;

    cout << "-------------------------" << endl;
    cout << Test::b << " " << &Test::b << endl;
    return 0;
}
```

## 3.2 静态成员函数
使用static修饰的成员函数，这样的函数就是静态成员函数
- 静态成员函数可以通过对象进行调用，也可以通过类名::的方式调用（更推荐使用类名::的方式）
- 静态成员函数中，没有this指针，因此不能在静态成员函数中调用同类其他的非静态成员。
- 静态成员函数可以调用当前类的静态成员
```cpp
#include <iostream>

using namespace std;

class Test
{
public:
    void func0()
    {
//        func1(); // 非静态成员函数可以调用静态成员函数
        cout << "非静态成员函数被调用了" << endl;
    }

    // 静态成员函数
    static void func1()
    {
        func2();
//        func0();
        cout << "静态成员函数1" << endl;
    }

    static void func2()
    {
        cout << "静态成员函数2" << endl;
    }
};


int main()
{
    Test::func2();

    Test t1;
//    t1.func0();
    t1.func1();
//    t1.func2();

    return 0;
}
```

# 4、const关键字（掌握）
## 4.1 const修饰成员函数
- 常成员函数，对于当前类的普通成员变量，可以访问，但是不能修改
- 对于当前类的普通成员函数，无法访问
- 常成员函数可以访问常成员函数
```cpp
#include <iostream>

using namespace std;

class Demo
{
private:
    int a;
public:
    Demo(int a)
    {
        this->a = a;
    }

    void func0()
    {
        cout << "func0被调用了" << endl;
    }

    int get_a()const
    {
        return a;
    }
    

    // 常成员函数
    void test()const
    {
        cout << a << endl; // 可以调用，但是不能修改
//        a++; // 错误，常成员函数，不能修改当前类的普通成员变量

//        func0(); // 常成员函数，不能调用普通成员函数

        cout << get_a() << endl; // 常成员函数可以调用常成员函数
    }

};

int main()
{
    Demo demo(1);
//    cout << demo.get_a() << endl;
//    demo.func0();
    demo.test();
    return 0;
}
```

# 5、继承（重点）
## 5.1 概念
继承是面向对象的三大特性之一，体现了代码复用的思想。
继承就是在一个已存在的类的基础上建立一个新的类，并拥有其特性。
    - 已存在的类被称为“基类”或者“父类”
    - 新建立的类被称为“派生类”或者“子类”
```cpp
#include <iostream>

using namespace std;

// 基类
class Father
{
private:
    string name = "张三";
public:
    void set_name(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return name;
    }

    void work()
    {
        cout << "我的工作是厨师，我负责炒菜" << endl;
    }
};

// 派生类继承Father
class Son : public Father
{

};

int main()
{
    Son son;
    cout << son.get_name() << endl;
    son.work();

    return 0;
}
```
在继承结构中，派生类往往会做出一些与基类的差异化。
    - 修改继承下来的内容
    属性：公有属性可以直接修改。私有属性，派生类中无法进行访问和修改
    行为：函数，函数隐藏。通过派生类实现一个与基类函数同名函数，来隐藏基类同名的函数。
    - 新增派生类的内容
    ```cpp
#include <iostream>

using namespace std;

// 基类
class Father
{
private:
    string name = "张三";
public:

    void set_name(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return name;
    }

    void work()
    {
        cout << "我的工作是厨师，我负责炒菜" << endl;
    }
};

// 派生类继承Father
class Son : public Father
{
public:
    void init()
    {
        set_name("李四");
    }

    void work()
    {
        cout << "我的工作是使用电脑控制挖掘机炒菜" << endl;
    }

    void game()
    {
        cout << "我除了工作，我还会打游戏，元神启动" << endl;
    }
};

int main()
{
    Son son;
    cout << son.get_name() << endl; // 张三
    son.work();

    son.init();
    cout << son.get_name() << endl; // 李四

    son.Father::work(); // 调用被隐藏的函数
    return 0;
}
```
## 5.2 构造函数
### 5.2.1 派生类与基类构造函数的关系
构造函数与析构函数不能被继承。
```cpp
#include <iostream>

using namespace std;

class Father
{
private:
    string name;
public:
    Father(string name)
        :name(name){}

    string get_name()
    {
        return name;
    }
};

class Son : public Father
{

};

int main()
{
//    Son s1; // 错误 找不到基类的无参构造函数

//    Son s2("hello"); // 错误 找不到派生类的有参构造函数

    return 0;
}
```
 派生类的任意一个构造函数，都必须直接或者间接调用基类的任意一个构造函数。
![图片](https://docimg1.docs.qq.com/image/AgAABovvK89u_XqGxsZPU5o46qw1m0t5.png?w=1567&h=708)
### 5.2.2 解决方案
#### 5.2.2.1 补充基类的无参构造函数
```cpp
#include <iostream>

using namespace std;

class Father
{
private:
    string name;
public:
    // 有参构造函数
    Father(string name)
        :name(name){}

    // 无参构造函数
    Father()
    {
        name = "张三";
    }

    string get_name()
    {
        return name;
    }
};

class Son : public Father
{

};

int main()
{
    Son s1;
    cout << s1.get_name() << endl;
//    Son s2("hello"); // 错误 找不到派生类的有参构造函数

    return 0;
}
```

#### 5.2.2.2 透传构造
在派生类的构造函数中，调用基类的构造函数。实际上编译器自动添加的派生类调用基类无参构造函数时，就是采用的透传构造。
```cpp
#include <iostream>

using namespace std;

class Father
{
private:
    string name;
public:
    // 有参构造函数
    Father(string name)
        :name(name){}

    // 无参构造函数
    Father()
    {
        name = "张三";
    }

    string get_name()
    {
        return name;
    }
};

class Son : public Father
{
public:
    // 透传构造
    // 调用基类的无参构造函数
    Son():Father(){}
    // 调用基类的有参构造函数
//    Son():Father("李四"){}

//    Son(string name):Father(){}
    Son(string name):Father(name){}
};

int main()
{
    Son s1;
    cout << s1.get_name() << endl;
    Son s2("hello"); // 错误 找不到派生类的有参构造函数
    cout << s2.get_name() << endl;
    return 0;
}
```

# 6、权限（掌握）
## 6.1 权限修饰符
三种权限一共对应了九种场景，要做到心中有表，遇到任何一种场景都能够直接反映出来是否能够访问。
| |类内|派生类中|全局|
|private|√|×|×|
|protected|√|√|×|
|public|√|√|√|

            
            类内
            派生类中
            全局
            private
            √
            ×
            ×
            protected
            √
            √
            ×
            public
            √
            √
            √
```cpp
#include <iostream>

using namespace std;

class Base
{
protected:
    string s = "保护权限";
public:
    Base()
    {
        cout << s << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << s << endl;
    }
};

int main()
{
    Son s1;
//    s1.s; // 错误s是保护权限

    return 0;
}
```

## 6.2 不同权限的继承（熟悉）
### 6.2.1 公有继承
之前的代码中一直使用的就是公有继承。公有继承也是所有继承方式中使用最多的一种方式。
在公有继承中，派生类会继承基类的成员，不可以访问基类的私有成员，基类的保护成员与公有成员，在派生类中可以访问。基类继承下来的内容，权限在派生类中保持不变。
```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    string str1 = "私有成员";
protected:
    string str2 = "保护成员";
public:
    string str3 = "公有成员";

};

class Son : public Base
{
public:
    Son()
    {
//        cout << str1 << endl; // 错误str1为私有成员，派生类中无法访问
        cout << str2 << endl;
        cout << str3 << endl;
    }
};


int main()
{
    Son s1;
//    s1.str1;  // 类外无法访问
//    s1.str2;  // 类外无法访问
    s1.str3;

    return 0;
}
```

### 6.2.2 保护继承
在保护继承中，派生类可以继承基类的成员。
      不可以访问基类的私有成员。
      基类的公有成员在派生类中为保护权限，其他权限的成员，权限保持不变。
```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    string str1 = "私有成员";
protected:
    string str2 = "保护成员";
public:
    string str3 = "公有成员";

};

class Son : protected Base
{
public:
    Son()
    {
//        cout << str1 << endl; // 错误str1为私有成员，派生类中无法访问
        cout << str2 << endl;
        cout << str3 << endl;
    }
};


int main()
{
    Son s1;
//    s1.str1;  // 类外无法访问
//    s1.str2;  // 类外无法访问
//    s1.str3;  // 类外无法访问

    return 0;
}
```

### 6.2.3 私有继承
在私有继承中，派生类可以继承基类的成员。
       但是不可以访问基类的私有成员。
基类的公有成员与保护成员在派生类中都为私有权限。
```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    string str1 = "私有成员";
protected:
    string str2 = "保护成员";
public:
    string str3 = "公有成员";

};

class Son : private Base
{

public:
    Son()
    {
//        cout << str1 << endl; // 错误str1为私有成员，派生类中无法访问
        cout << str2 << endl;
        cout << str3 << endl;
    }
};


int main()
{
    Son s1;
//    s1.str1;  // 类外无法访问
//    s1.str2;  // 类外无法访问
//    s1.str3;  // 类外无法访问

    return 0;
}
```

# 7、多态（重点）
## 7.1 概念
多态可以理解为“一种接口，多种状态”，只需要编写一个函数接口，根据传入的参数类型，执行不同的策略代码。
多态的实现需要有三个前提条件：
    - 公有继承
    - 函数覆盖
    - 基类的指针或者引用指向派生类对象
    多态的优点：多态的优势包括代码的灵活性、可扩展性和可维护性。它能够使代码更具通用性，减少重复代码的编写，并且能够轻松地添加新的派生类或扩展现有的功能。
    多态的缺点：多态的缺点包括代码的复杂性、运行效率、易读性。当类的继承关系复杂时，理解和维护多态性相关的代码会变得困难。多态在运行中会产生一些额外的开销。

## 7.2 函数覆盖
函数覆盖、函数隐藏，函数隐藏不支持多态，函数覆盖是多态的必要条件。
    - 函数隐藏：派生类中存在一个与基类同名的函数，编译器会将基类中所有同名的函数进行隐藏。
    - 函数覆盖：基类中定义了一个虚函数，派生类编写了一个同名同参的函数，将基类中同名同参的虚函数进行隐藏。

## 7.3 虚函数的定义
一个函数使用virtual关键字修饰，就是虚函数，虚函数是函数覆盖的前提。在QtCreator中使用斜体字。
```cpp
#include <iostream>

using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void eat()
    {
        cout << "动物爱吃饭" << endl;
    }

};

int main()
{


    return 0;
}
```
虚函数具有以下的性质：
虚函数具有传递性，基类中被覆盖的函数是虚函数，派生类中新覆盖的函数也是虚函数。
```cpp
#include <iostream>

using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void eat()
    {
        cout << "动物爱吃饭" << endl;
    }
};

class Dog : public Animal
{
public:
    // 覆盖基类中的虚函数，派生类virtual可写可不写
    void eat()
    {
        cout << "狗爱吃骨头" << endl;
    }
};

int main()
{


    return 0;
}
```
只有普通成员函数与析构函数可以声明为虚函数。
```cpp
#include <iostream>

using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void eat()
    {
        cout << "动物爱吃饭" << endl;
    }

    // 错误 构造函数不能声明为虚函数
//    virtual Animal()
//    {
//        cout << "测试构造函数，声明为虚函数" << endl;
//    }

    // 错误 静态成员函数不能声明为虚函数
//    virtual static void testStatic()
//    {
//        cout << "测试静态成员函数，声明为虚函数" << endl;
//    }

};

class Dog : public Animal
{
public:
    // 覆盖基类中的虚函数，派生类virtual可写可不写
    void eat()
    {
        cout << "狗爱吃骨头" << endl;
    }
};

int main()
{


    return 0;
}
```

## 7.4 多态的实现
要是实现多态，需要有三个前提条件：
    - 公有继承
    - 函数覆盖
    - 基类的指针或者引用，指向派生类对象
```cpp
#include <iostream>

using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void eat()
    {
        cout << "动物爱吃饭" << endl;
    }

};

class Dog : public Animal
{
public:
    // 覆盖基类中的虚函数，派生类virtual可写可不写
    void eat()
    {
        cout << "狗爱吃骨头" << endl;
    }
};

int main()
{
    // 基类的指针指向派生类对象
    Animal *a1 = new Dog;
    a1->eat();  // 狗爱吃骨头

    // 基类的引用给派生类起别名
    Dog d1;
    Animal &d2 = d1;
    d2.eat();   // 狗爱吃骨头

    return 0;
}
```
```cpp
#include <iostream>

using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void eat()
    {
        cout << "动物爱吃饭" << endl;
    }

};

class Dog : public Animal
{
public:
    // 覆盖基类中的虚函数，派生类virtual可写可不写
    void eat()
    {
        cout << "狗爱吃骨头" << endl;
    }
};

class Cat : public Animal
{
public:
    // 覆盖基类中的虚函数，派生类virtual可写可不写
    void eat()
    {
        cout << "猫爱吃鱼" << endl;
    }
};

void animal_eat(Animal *a1)
{
    a1->eat();
}

int main()
{
    Dog *d1 = new Dog;
    animal_eat(d1);
    d1->eat();

    Cat *c1 = new Cat;
    animal_eat(c1);

    return 0;
}
```

## 7.5 多态的原理（熟悉）
具有虚函数的类会存在一张虚函数表。每个类的对象内部，会有一个隐藏的虚函数表指针成员，指向当前类的虚函数表。

![图片](https://docimg4.docs.qq.com/image/AgAABovvK8_N8-wA6SRCMbcc8q4RMyOc.png?w=1515&h=724)
![图片](https://docimg8.docs.qq.com/image/AgAABovvK8-fAQROipZExpr-R8pzx5-i.png?w=1554&h=706)

在代码运行时，通过对象的虚函数表指针找到虚函数表，在表中定位到虚函数的调用地址，从而执行对应的虚函数内容。

# 8、虚析构函数（熟悉）
当基类的指针指向派生类对象时，delete销毁对象时，只能触发基类的析构函数。派生类内存空间出现泄漏的问题。
这种情况需要使用虚析构函数，来解决。
因此我们建议，把每一个可能为基类的类，它的析构函数都声明为虚析构函数。
```cpp
#include <iostream>

using namespace std;

class Animal
{
public:
    virtual ~Animal()
    {
        cout << "Animal 析构函数被调用了" << endl;
    }
};

class Dog : public Animal
{
public:
    ~Dog()
    {
        cout << "Dog的析构函数" << endl;
    }
};


int main()
{
    Animal *a1 = new Dog;
    delete a1;

    return 0;
}
```