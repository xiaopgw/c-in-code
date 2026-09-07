// 多态
#include <iostream>

using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void eat()
    {
        cout << "动物" << endl;
    }
    virtual void play()
    {
        cout << "玩" << endl;
    }
};
// 创建
class Dog : public Animal
{
    public:
    // 覆盖基类的虚函数
    void eat()
    {
        cout << "狗" << endl;
    }
    void play()
    {
        cout << "骨头" << endl;
    }
};

class Cat : public Animal
{
    public:
    void eat()
    {
        cout << "猫"  << endl;
    }
    void play()
    {
        cout << "鱼" << endl;
    }
};

void animal_eat(Animal *any)
{
    any->eat();
    any->play();
}

int main()
{
    Dog *d1 = new Dog;
    animal_eat(d1);
    Cat *c1 = new Cat;
    animal_eat(c1);
    return 0;
}
// // 继承中的构造函数
// #include <iostream>
// using namespace std;

// class Father
// {
// private:
//     string name;

// public:
//     Father(string name)
//         : name(name)
//     {
//         cout << "调用了有参构造函数" << endl;
//     }
//     string get_name()
//     {
//         return name;
//     }
// };

// class Son : public Father
// {
// };

// int main()
// {
//     Father f1("fu");
//     // Son s1;
//     // Son s2("noooooo!");
//     5;
//     return 0;
// }

// 继承
// #include <iostream>

// using namespace std;

// // 基类
// class Father
// {
// private:
//     string name = "夜魔侠";

// public:
// // string name = "夜魔侠";
//     void set_name(string name)
//     {
//         this->name = name;
//     }
//     string get_name()
//     {
//         return name;
//     }
//     void work()
//     {
//         cout << "我的工作是超级英雄，我负责守护城市" << endl;
//     }
// };

// // 派生类
// class Son : public Father
// {
// public:
//     void init()
//     {
//         // name = "蜘蛛侠";
//         set_name("蜘蛛侠");
//     }
//     void work()
//     {
//         cout << "我的工作是超级英雄，我负责守护邻居" << endl;
//     }
// };

// int main()
// {
//     Son son;
//     son.init();
//     cout << son.get_name() << endl;
//     son.work();
//     return 0;
// }