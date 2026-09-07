# Day3

# 1、Qt是什么？
这门课程的定位：
    - 系统性的认识图形用户界面编程。
    
    Qt是一个基于C++的图形用户界面（GUI）开发框架，Qt不仅仅能够开发界面，还包括了很多传统编程的技术：多线程、数据库、图像处理、网络编程、文件IO。。。。。等等。
    以下是Qt开发的具体产品：
    ![图片](https://docimg7.docs.qq.com/image/AgAABovvK8_CH20tUndDgICAr8flae6a.png?w=942&h=281)
    ![图片](https://docimg3.docs.qq.com/image/AgAABovvK8-Sw1IdioJJqJ8gI5JVXuUI.png?w=617&h=671)
    ![图片](https://docimg6.docs.qq.com/image/AgAABovvK8-qO0K1SAlM_6oXc4BWkn9q.png?w=882&h=250)
    ![图片](https://docimg3.docs.qq.com/image/AgAABovvK8_lzfXYJURNWYGeO4WGOHqr.png?w=820&h=379)
    ![图片](https://docimg10.docs.qq.com/image/AgAABovvK8_RbNnYlFtC9YlH-72o2iTM.png?w=1199&h=493)
    等等等，包括但不限于以上的场景。
    Qt主要的优势就是优良的跨平台特性。（一次编程，到处编译）
    另外Qt也有一些常规的特性：
        - 面向对象开发（C++开发）
        -  丰富的API调用接口，配套了对应的开发文档手册。
        - 易用的开发软件
        - 开源（源代码开放，学习资料多）
    
    # 2、新建项目
    本次Qt开发仍然使用C++课程中的Qt Creator，但是需要把软件的编码恢复到utf-8.
    ![图片](https://docimg2.docs.qq.com/image/AgAABovvK889ZiiPmTtB97jLUJH3-dVV.png?w=815&h=331)
    更改完成后，重新启动Qt Cretaor，即可创建一个支持中文的Qt项目了。
    1、在Qt Creator中，点击
    ![图片](https://docimg1.docs.qq.com/image/AgAABovvK88JKUDzrmRAL4Vv-taCDGJE.png?w=162&h=45)
    2、在弹出的窗口中，按照下图所示进行操作
    ![图片](https://docimg10.docs.qq.com/image/AgAABovvK8-dzoQOrndHmIoISKDWP5LR.png?w=895&h=561)
    
    3、在弹出的窗口中设置项目的名称和路径，注意：不能包含中文字符和特殊字符。
    ![图片](https://docimg8.docs.qq.com/image/AgAABovvK8-Z_t3egZBFGppyasJUgQVw.png?w=930&h=450)
    4、直接点击下一步
    ![图片](https://docimg6.docs.qq.com/image/AgAABovvK8_GzNiiJ2NFh6dBHlTLGVmh.png?w=924&h=453)
    
    5、在弹出的窗口中，选择基类为“QDialog”，取消“创建界面”选项，然后点击“下一步”
    ![图片](https://docimg9.docs.qq.com/image/AgAABovvK88NOwbPQtlBIqDiI10DU-JF.png?w=913&h=490)
    
    6、在项目管理界面，直接点击完成
    ![图片](https://docimg9.docs.qq.com/image/AgAABovvK89fwGeOuRBNA5zgwiQ11mA8.png?w=947&h=477)
    
    可以看到项目将中包含的文件：
    ![图片](https://docimg9.docs.qq.com/image/AgAABovvK88_PF7Sq4BCFontx5PXvlDZ.png?w=287&h=215)
    7、点击运行项目，项目运行后，可以看到一个可视化的窗口界面。
    ![图片](https://docimg6.docs.qq.com/image/AgAABovvK888jCCI14hC87BvIlTXmC-3.png?w=656&h=563)
    
    # 3、构建目录和工作目录
    项目运行后，存在两个重要的目录：构建目录和工作目录
    ## 3.1 构建目录
    存放编译过程中生成的文件，这个目录的位置：
    ![图片](https://docimg7.docs.qq.com/image/AgAABovvK88yU6ro5M5FMK60mDsOGlje.png?w=1418&h=703)
    
    ## 3.2 工作目录
    工作目录就是创建项目时所设置的目录，用于存放项目的源代码文件等开发文件。
    工作目录可以通过下面的方式进行定位：
    ![图片](https://docimg3.docs.qq.com/image/AgAABovvK8-jHlb_ObVJoYASAgoPElf3.png?w=390&h=155)
    
    工作目录中包含以下的文件：
    ![图片](https://docimg2.docs.qq.com/image/AgAABovvK88xk3mCeBpDj5CYM7ihPXA4.png?w=1158&h=419)
    
    # 4、项目结构
    ## 4.1 项目配置文件.pro
    在windows的文件管理器中，直接双击pro即可导入项目
    ![图片](https://docimg3.docs.qq.com/image/AgAABovvK8_S4LFrieVJxYRYrsRriiuA.png?w=876&h=259)
    ![图片](https://docimg6.docs.qq.com/image/AgAABovvK8-7ILhiYsBH5rD2TdqGbkyS.png?w=1392&h=761)
    ```cpp
#-------------------------------------------------
#
# Project created by QtCreator 2026-08-31T14:32:40
#
#-------------------------------------------------
# 添加core核心模块，gui传统图形界面模块
QT       += core gui

# 当Qt的主版本号大于4的时候，添加新的图形界面模块widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 生成可执行文件exe的名称：831_hello_qt
TARGET = 831_hello_qt
# 项目架构模式
TEMPLATE = app

# 项目中包含的源文件
SOURCES += main.cpp\
        dialog.cpp

# 项目中包含的头文件
HEADERS  += dialog.h
```
    
    ## 4.2 用户文件.user
    用户文件在Qt Creator中不可见，但是确实存在与工作目录中。
    此文件是Qt根据当前计算机开发环境自动生成的，每个计算机中几乎不通用此文件，因此在提交代码时，先删除此文件。
    
    ## 4.3 主文件main.cpp
    程序的入口，包含主函数，通常不需要改变主文件的代码
    ```cpp
#include "dialog.h"
// QApplication类管理GUI应用程序的控制流和主设置
#include <QApplication>

// main主函数，程序的入口
int main(int argc, char *argv[])
{
    // 创建一个关键类栈内存对象，管理整个应用程序
    QApplication a(argc, argv);

    // 创建了一个自定义对话框窗口类的栈内存对象
    Dialog w;
    // 显式，创建的对话框窗口
    w.show();

    // 进入主事件循环
    return a.exec();
}
```
    
    ## 4.4 头文件dialog.h
    在Qt中一个自定义类的声明都写在.h中，这个类所用到的其他类头文件，也在此文件中引入。
    ```cpp
#ifndef DIALOG_H
#define DIALOG_H

// 添加头文件QDialog对话框基类，Qt自带类型通常以Q开头
#include <QDialog>

/**
 * @brief The Dialog class 自定义对话框窗口类
 * 继承自：QDialog
 */
class Dialog : public QDialog
{
    // 不要删除
    Q_OBJECT
// 权限，公有权限
public:
    Dialog(QWidget *parent = 0);   // 构造函数
    // 虚析构函数
    ~Dialog();
};

#endif // DIALOG_H
```
    
    ## 4.5 源文件dialog.cpp
    包含与同名的头文件配套的类外定义。
    ```cpp
#include "dialog.h"

/**
 * @brief Dialog::Dialog 构造函数类外实现
 * @param parent  参数
 */
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)   // 透传构造
{
}

// 析构函数
Dialog::~Dialog()
{

}
```
    
    # 5、调试信息展示
    Qt中使用qDebug()将调试信息输出到后台中。
          自动在多个值之间添加空格，并在语句结束后换行。
    ```cpp
#include "dialog.h"
#include <QDebug>

/**
 * @brief Dialog::Dialog 构造函数类外实现
 * @param parent  参数
 */
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)   // 透传构造
{
    qDebug() << "程序启动" << "你好吗";
    qDebug() << "value" << 10;
}

// 析构函数
Dialog::~Dialog()
{

}
```
    注意：
    当程序正在运行时，如果更改代码，再次运行可能会出现下面的情况，只需要关闭当前正在运行的项目重新运行即可。
    ![图片](https://docimg2.docs.qq.com/image/AgAABovvK89nl9uSVV9Mjqg-NaW1Yn2E.png?w=923&h=163)
    
    # 6、帮助文档
    1、在Qt Creator中直接点击帮助选项，可以打开一个内嵌的Assistant程序。
    ![图片](https://docimg3.docs.qq.com/image/AgAABovvK8-oT4QvxJtOwJtGpxSjPBXP.png?w=64&h=55)
    ![图片](https://docimg4.docs.qq.com/image/AgAABovvK88aXj6hfVNAsZhQgeofDSXP.png?w=855&h=576)
    
    2、光标定位到要查询的内容上，双击键盘的F1，可以直接跳转到对应的文件内容中。
    ![图片](https://docimg9.docs.qq.com/image/AgAABovvK8-wYqxLA5lEcKXDq4Yuu6VZ.png?w=1630&h=889)
    
    
    # 7、QWidget基础
    ## 7.1 窗口基础属性
    QWidget类是所有组件和窗口的基类，内部包含了一些最基础的界面特性。
    ![图片](https://docimg5.docs.qq.com/image/AgAABovvK89b8R8-rj9G-73d8YH7Kqdp.png?w=703&h=807)
    常用的属性：
    1、修改宽高
    - width : const int
    宽度，不包含边框
    - height : const int
    高度，不包含边框
```cpp
// 修改窗口的大小
// 参数1：新的宽度
// 参数2：新的高度
void	resize(int w, int h)
```
2、修改坐标
    - x : const int
    横坐标，以每个组件的左上角为定位点。横轴的零点在屏幕的最坐边，正方向向右。
    - y : const int
    纵坐标，每个组件的左上角为定位点，纵轴的零点在屏幕的最上边，正方向向下。
    ```cpp
// 移动
// 参数1：新的横坐标
// 参数2：新的纵坐标
void	move(int x, int y)
```

3、修改样式
    - styleSheet : QString
```cpp
// 设置样式表
setStyleSheet("background-color:red");
```

## 7.2 添加子组件
上面的窗口中什么都没有，实际上可以向窗口中添加若干个组件，来实现不同的显式和交互效果，本节以QPushButton组件为例。
构造函数如下：
```cpp
// 参数1：按钮上显式的文字
// 参数2：在那个窗口中显示
QPushButton::​QPushButton(const QString & text, QWidget * parent = 0)
```
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

#define QPushButton_STYTLE (QString("\
/*按钮普通态*/\
QPushButton\
{\
    font-family:Microsoft Yahei;\
    /*字体大小为20点*/\
    font-size:20pt;\
    /*字体颜色为白色*/\
    color:white;\
    /*背景颜色*/\
    background-color:rgb(14 , 150 , 254);\
    /*边框圆角半径为8像素*/\
    border-radius:8px;\
}\
/*按钮悬停态*/\
QPushButton:hover\
{\
    /*背景颜色*/\
    background-color:rgb(100 , 20 , 190);\
}\
/*按钮按下态*/\
QPushButton:pressed\
{\
    /*背景颜色*/\
    background-color:rgb(14 , 135 , 10);\
    /*左内边距为3像素，让按下时字向右移动3像素*/\
    padding-left:3px;\
    /*上内边距为3像素，让按下时字向下移动3像素*/\
    padding-top:3px;\
}"))


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    QPushButton *btn;
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,500);
    btn = new QPushButton("按钮显式的文字",this);
    btn->move(200,300);
    btn->setStyleSheet(QPushButton_STYTLE);
}

Dialog::~Dialog()
{
    delete btn;
}
```

# 8、信号槽
## 8.1 概念
信号和槽是两种函数，这是Qt在C++的基础上新增的特性。
信号槽通过程序员提前设定的约定，可以实现对象之间的通信。
    - 通信的对象必须是从QObject类中派生类出来的
    - 类中要有Q_OBJECT宏
    
## 8.2 函数原型
信号槽需要在使用之前进行约定，这个约定也被称为链接。使用connect函数进行连接。
【例子】：如果小张考试考了100分，那么小王请客吃饭。
```cpp
// 参数1：发射者【小张】
// 参数2：信号函数【考了100分】
// 参数3：接收者【小王】
// 参数4：槽函数【请客吃饭】
connect(const QObject * sender, const char * signal, const QObject * receiver, const char * method) [static]
```

## 8.3 实现
为了学习，把信号槽分为三种连接方式：
- 自带信号-》自带槽
- 自带信号-》自定义槽
- 自定义信号

### 8.3.1 自带信号→自带槽
这种方式是最简单的，因为信号函数和槽函数都是Qt内置的，只需要在文档中找到对应的函数，使用connect函数连接即可。
【例子】点击按钮，关闭窗口
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

#define QPushButton_STYTLE (QString("\
/*按钮普通态*/\
QPushButton\
{\
    font-family:Microsoft Yahei;\
    /*字体大小为20点*/\
    font-size:20pt;\
    /*字体颜色为白色*/\
    color:white;\
    /*背景颜色*/\
    background-color:rgb(14 , 150 , 254);\
    /*边框圆角半径为8像素*/\
    border-radius:8px;\
}\
/*按钮悬停态*/\
QPushButton:hover\
{\
    /*背景颜色*/\
    background-color:rgb(100 , 20 , 190);\
}\
/*按钮按下态*/\
QPushButton:pressed\
{\
    /*背景颜色*/\
    background-color:rgb(14 , 135 , 10);\
    /*左内边距为3像素，让按下时字向右移动3像素*/\
    padding-left:3px;\
    /*上内边距为3像素，让按下时字向下移动3像素*/\
    padding-top:3px;\
}"))


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    QPushButton *btn;
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,500);
    btn = new QPushButton("按钮显式的文字",this);
    btn->move(150,200);
    btn->setStyleSheet(QPushButton_STYTLE);

    // 点击按钮，关闭窗口
    // 参数1：发射者（按钮对象）
    // 参数2：信号函数（点击信号）
    // 参数3：接收者（this）
    // 参数4：close关闭当前窗口
    connect(btn,SIGNAL(clicked()),
            this,SLOT(close()));
}

Dialog::~Dialog()
{
    delete btn;
}
```

### 8.3.2 自带信号→自定义槽
Qt不可能内置所有的执行动作代码，特别是一些复杂的动作，需要开发者手动进行编写槽函数，这种方式也是所有连接方式中使用最多的。
槽函数实际上也是一个成员函数，在声明的时候权限的作用主要是修饰其作为普通成员函数的使用效果，不影响信号槽的连接效果。
【例子】点击按钮，窗口向下向右，移动十个像素。
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    QPushButton *btn;

    // 声明自定义槽函数
private slots:
    void mySlot();
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,500);
    btn = new QPushButton("移动",this);
    btn->move(200,250);

    connect(btn,SIGNAL(clicked()),
            this,SLOT(mySlot()));

}

void Dialog::mySlot()
{
    // 先获取当前窗口的坐标
    int x = this->x();
    int y = this->y();

    // 移动窗口坐标
    move(x+10,y+10);

}

Dialog::~Dialog()
{
    delete btn;
}
```

### 8.3.3 自定义信号
为了讲解，强行使用自定义信号，并非问题的最优解，主要学习写法。
信号函数是一种非常特殊的函数，因为其只有声明，没有定义，即没有函数体，因此无法调用，只能发射信号（推荐使用emit关键字进行发射）
【例子】点击按钮，关闭窗口
8.3.1 节的连接方式
![图片](https://docimg9.docs.qq.com/image/AgAABovvK88PcNswVVNL37LiKo0zhr96.png?w=1104&h=260)
本节强行在中间加一层自定义信号的转发过程。
![图片](https://docimg6.docs.qq.com/image/AgAABovvK89z88XWnjJITK9dp3UTBIm2.png?w=1638&h=543)
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    QPushButton *btn;

    // 声明自定义槽函数
private slots:
    void mySlot();

    // 自定义信号
signals:
    void mySignal();    // 没有函数体
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,500);
    btn = new QPushButton("移动",this);
    btn->move(200,250);

    connect(btn,SIGNAL(clicked()),
            this,SLOT(mySlot()));

    connect(this,SIGNAL(mySignal()),
            this,SLOT(close()));

}

void Dialog::mySlot()
{
    // 在mySlot中发射自定义信号
    emit mySignal();
}

Dialog::~Dialog()
{
    delete btn;
}
```

## 8.4 信号槽传参
【例子】：点击按钮，按钮上显式点击的次数。
- 创建按钮对象
- 使用connect函数将按钮对象的点击信号，与窗口对象的自定义槽函数进行连接
- 将点击次数进行累加
- 将累加次数，刷新到按钮上

```cpp
// 设置按钮上的文字
void	setText(const QString & text)
```
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    QPushButton * btn;

    int count;

private slots:
    void mySlot();
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,500);
    btn = new QPushButton("0",this);
    btn->move(200,200);

    connect(btn,SIGNAL(clicked()),
            this,SLOT(mySlot()));

    count = 0;
}

void Dialog::mySlot()
{
    count++;

    // 类型转换int -> QString
    QString text = QString::number(count);

    // 更改按钮显式的文字
    btn->setText(text);
}

Dialog::~Dialog()
{
    delete btn;
}
```
强行把上面的案例改为信号槽传参。
![图片](https://docimg5.docs.qq.com/image/AgAABovvK89B_eU-qHdOgKAVcPtdQHGa.png?w=1635&h=713)
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    QPushButton * btn;

    int count;

private slots:
    void mySlot();
    void mySlot2(int);

signals:
    void mySignal(int);
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,500);
    btn = new QPushButton("0",this);
    btn->move(200,200);

    connect(btn,SIGNAL(clicked()),
            this,SLOT(mySlot()));

    connect(this,SIGNAL(mySignal(int)),
            this,SLOT(mySlot2(int)));

    count = 0;
}

void Dialog::mySlot()
{
    count++;
    emit mySignal(count);

}

void Dialog::mySlot2(int count)
{
    // 类型转换int -> QString
    QString text = QString::number(count);

    // 更改按钮显式的文字
    btn->setText(text);
}

Dialog::~Dialog()
{
    delete btn;
}
```
需要注意：
- 理论上来说可以传递任意多个参数，建议最多写两个参数，多了会很冗余，如果非得传递多个参数，可以定义成一个类，传递对象
- 信号的参数个数必须大于等于槽函数的参数个数。
- 信号的参数类型要与槽的参数类型匹配

# 9、Designer设计师
Qt包含了一个Designer程序，用于通过可视化的界面设计用户开发界面，保存的文件格式为.ui（界面文件）格式。界面文件内部都是使用xml语法的标签式语言。

Qt包含了一个Designer程序，用于通过可视化的界面设计用户开发界面，保存的文件格式为.ui（界面文件）格式。界面文件内部都是使用xml语法的标签式语言。
![图片](https://docimg7.docs.qq.com/image/AgAABovvK8-lUUNLsr9G5I62o_Hihiuu.png?w=897&h=468)
![图片](https://docimg4.docs.qq.com/image/AgAABovvK881vrIy1dRGN5HEhbM-Ycws.png?w=294&h=220)

![图片](https://docimg5.docs.qq.com/image/AgAABovvK888uOVX8y1JqLBgI6gUajDI.png?w=1822&h=960)
所有Designer中的操作都可以使用C++代码实现。
# 10、布局Layout
可以把布局看做成一个透明的盒子，内部可以放置子组件，这些内部的子组件会按照布局预设的规则自动排序。
![图片](https://docimg1.docs.qq.com/image/AgAABovvK89HQxvAKnBG_rnmyvmSNZ3s.png?w=1037&h=677)
垂直布局：内部的组件竖着排成一列
水平布局：内部组件横着排成一排
格栅布局：内部组件排布成n*m的表格
表单布局：用于搭建用户输入的布局效果
![图片](https://docimg7.docs.qq.com/image/AgAABovvK899ydtLgcVCMaqyhIavR1Lk.png?w=944&h=388)

布局是可以打破的，选中布局后，点击下面的按键，即可打破布局
![图片](https://docimg8.docs.qq.com/image/AgAABovvK89xqLQMDUpKsrG7siuEv_rz.png?w=36&h=32)

布局可以贴合窗口，只需要选中窗口对象后，再次点击下面的按钮之一即可。
![图片](https://docimg4.docs.qq.com/image/AgAABovvK8-P4dv2ToBEFIkDf2yTvwCG.png?w=395&h=119)

布局可以嵌套，对于外层布局而言，内层布局相当于外层布局的子组件。
![图片](https://docimg6.docs.qq.com/image/AgAABovvK88-VKfFgkdHeYghBvlUPYuI.png?w=1220&h=285)

# 11、UI中的QWidget属性
QWidget的属性在Designer中显示为淡黄色。
![图片](https://docimg10.docs.qq.com/image/AgAABovvK8_tPK_H-JlEoYpXkJ7EWpKI.png?w=785&h=641)
添加字体

![图片](https://docimg2.docs.qq.com/image/AgAABovvK8_qFyhj6I5LDqkdKUYw3_Tf.png?w=1363&h=571)
添加样式：
![图片](https://docimg1.docs.qq.com/image/AgAABovvK8-TpC0Ik2JI3JFWSml_RPlm.png?w=498&h=471)
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8-spZhgOBhFlppBuLcjsLiW.png?w=570&h=513)

# 12、界面文件与C++代码的关系
![图片](https://docimg6.docs.qq.com/image/AgAABovvK89vX0EBvspFzpOYUxwxmxVV.png?w=1872&h=790)













































# Day4
# 1、QLabel标签
## 1.1 基本属性
QLabel用于显示文字或图片，需要注意的是，QLabel不能与用户交互（不能点击），只能展示使用，因此没有合适的信号函数。
![图片](https://docimg1.docs.qq.com/image/AgAABovvK88KhRwW-2dOcYGpsW2OWBfh.png?w=977&h=546)

## 1.2 添加资源库
把图片导入到下项目中，成为项目的资源，直接使用Qt的虚拟路径导入项目图片，可以在任何的环境中使用这些资源图片了。

Qt支持以下几种常见的图片格式：
jpg（不包含透明度）、png（包含透明度）、gif等等
注意导入的图片不能特别大（分辨率过高或者文件体积过大），因为图片的操作非常消耗资源。
下面是导入图片成为项目资源的操作步骤：
1、把命名好的图片放置到项目的工作目录中
2、在QtCreator中选中项目名称，鼠标右键点击添加新文件。
3、在弹出的窗口中，按照下图所示进行操作
![图片](https://docimg7.docs.qq.com/image/AgAABovvK889CUy2GE5EP4Yv464FLk79.png?w=893&h=556)

4、在弹出的窗口中给资源文件命名，例如res
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8_pvL7gu9lP34b3su2nTPSe.png?w=824&h=501)
5、在项目管理界面，直接点击完成，可以看到项目中多了一个.qrc格式的资源文件。

![图片](https://docimg3.docs.qq.com/image/AgAABovvK8-PAdt-Xo1JTb0PHLW8qCen.png?w=285&h=279)
6、选中qrc文件，点击添加前缀，可以给资源文件新建一个虚拟路径。
![图片](https://docimg6.docs.qq.com/image/AgAABovvK897_0pRyb1D2ZnK5E5-yBMB.png?w=132&h=104)
7、选中qrc文件，点击添加文件，可以导入图片到项目中成为资源
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8_S8_i8Fx1Kp6LgksMomGMq.png?w=163&h=105)
8、导入成功后，可以在qrc文件中看到导入成功的图片
![图片](https://docimg7.docs.qq.com/image/AgAABovvK8-Afwz1s2lAT6tzhIs3IkjS.png?w=993&h=413)

## 1.3 使用资源库
1、点击小锤子图标，重新构建项目。这样就可以在Designer中使用了。
![图片](https://docimg2.docs.qq.com/image/AgAABovvK8_auTiBivlDIYrref4VqAxD.png?w=659&h=478)
![图片](https://docimg10.docs.qq.com/image/AgAABovvK8_Jz5LE0A1AWZSsxcz4rP3j.png?w=1323&h=758)
![图片](https://docimg4.docs.qq.com/image/AgAABovvK8_NCNpHDvZBlb6GLQVJr0KL.png?w=1352&h=725)

## 1.4 使用代码添加图片
1、可以通过代码来加载图片，已经修建图片尺寸 等。
![图片](https://docimg2.docs.qq.com/image/AgAABovvK8_BmJuP9JdGVqUZnfWtH_U9.png?w=801&h=402)

2、如果要通过代码来加载图片，还需要使用include<QPixmap>头文件，图片类头文件。
3、创建一个图片类对象
```cpp
// 图片类构造函数
// 参数1：图片类资源路径
// 参数2：样板格式，使用默认即可
// 参数3：图片颜色格式，使用默认即可
QPixmap::​QPixmap(const QString & fileName, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor)
```

4、当前已经创建了图片类对象，但是还需要进行缩放，指定图片的输出模式。
```cpp
// 缩放函数
// 参数1：宽度
// 参数2：高度
// 参数3：三种缩放模式， 是一个枚举类型
// 参数4：以速度优先还是以质量优先。两种模式，默认是以速度优先，也是一个枚举值
// 返回值：转换后的QPixmap对象
QPixmap QPixmap::​scaled(int width, int height, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation) const
```
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 创建QPixmap栈内存对象
    QPixmap pic(":/new/prefix1/g.jpg");

    // 图片缩放
    pic = pic.scaled(ui->label->width(),ui->label->height(),
               Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // 显式图片
    ui->label->setPixmap(pic);
}

Dialog::~Dialog()
{
    delete ui;
}
```

# 2、QLineEdit 单行文本输入框
QLineEdit用于输入一个单行文本。
![图片](https://docimg5.docs.qq.com/image/AgAABovvK88gIpaP9a9KqrAnBr6bdaOy.png?w=1190&h=485)
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void btnClickedSlot();
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(btnClickedSlot()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::btnClickedSlot()
{
    QString text = ui->lineEdit->text();
    qDebug () << "第一个QLineEdit的内容：" << text;

    text = ui->lineEdit_2->text();
    qDebug () << "第二个QLineEdit的内容：" << text;
}
```

# 3、Qt数据类型
 Qt是一个跨平台的开发框架，所以必须保证各个平台下的数据类型长度一致。
因为Qt为常见的基本数据类型定义了新的类型符号。
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8_z0yp24ZRLhraPm703cY-b.png?w=996&h=747)
在Qt环境下，可以直接使用。
![图片](https://docimg2.docs.qq.com/image/AgAABovvK88N6SQo0clHiZgFql3TCaGl.png?w=423&h=133)

# 4、QTimer定时器类
QTimer类可以实现一个延时任务或者周期任务。
    
    使用定时器，需要包含头文件#include<QTimer>。
    
    QLcdNumber组件，使用此组件，显示出11:21:23.
    ![图片](https://docimg7.docs.qq.com/image/AgAABovvK8-2k6Cgwf5Bpq2iHx9A6ezL.png?w=1860&h=891)
    dialog.h
    ```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>   // 定时器
#include <QDateTime> // 时间和日期头文件

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QTimer *timer;  // 定时器对象

private slots:
    void timeoutSlot();
};

#endif // DIALOG_H
```
    dialog.cpp
    ```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    // 提前刷新组件
    timeoutSlot();


    // 设置时间间隔（单位毫秒）
    timer->setInterval(500);

    // 默认为周期任务，如果想要设置为延时任务需要用到以下的函数
    timer->setSingleShot(false);    // 周期任务

    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeoutSlot()));

    timer->start();
}

Dialog::~Dialog()
{
    delete timer;
    delete ui;
}

void Dialog::timeoutSlot()
{
    // 获取当前的系统时间
    QDateTime dateTime = QDateTime::currentDateTime();
    QString str = dateTime.toString("hh:mm:ss");
    // 并且将时间显式到lcd组件中
    ui->lcdNumber->display(str);
}
```

# 5、QMessageBox消息对话框
QMesageBox继承自QDialog，显式一个模态对话框，用于用户前台信息展示和询问用户问题并接收问题的答案。
![图片](https://docimg2.docs.qq.com/image/AgAABovvK898tzvpuMhOsI9iahKuEgfQ.png?w=1133&h=450)
```cpp
// 参数1：parent参数
// 参数2：窗口标题
// 参数3：信息内容，窗口展示的信息
// 返回值：用户点击的按钮类型
StandardButton	critical(QWidget * parent, const QString & title, const QString & text)

StandardButton	information(QWidget * parent, const QString & title, const QString & text)

StandardButton	question(QWidget * parent, const QString & title, const QString & text)

StandardButton	warning(QWidget * parent, const QString & title, const QString & text)
[static]

```
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void btnClickedSlotQ();
    void btnClickedSlotI();
    void btnClickedSlotW();
    void btnClickedSlotC();

};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButtonQ,SIGNAL(clicked()),
            this,SLOT(btnClickedSlotQ()));

    connect(ui->pushButtonI,SIGNAL(clicked()),
            this,SLOT(btnClickedSlotI()));

    connect(ui->pushButtonW,SIGNAL(clicked()),
            this,SLOT(btnClickedSlotW()));

    connect(ui->pushButtonC,SIGNAL(clicked()),
            this,SLOT(btnClickedSlotC()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::btnClickedSlotQ()
{
    QMessageBox::StandardButton stdb = QMessageBox::question(this,"question","是否需要关闭？");
    if(stdb == QMessageBox::Yes)
    {
        close();
    }
}

void Dialog::btnClickedSlotI()
{
    QMessageBox::information(this,"information","已经加载完成");

}

void Dialog::btnClickedSlotW()
{
    QMessageBox::warning(this,"warning","您的输入有误");

}

void Dialog::btnClickedSlotC()
{
    QMessageBox::critical(this,"critical","程序异常，运行失败");

}
```

# 6、parent参数
parent参数表示子组件位于那个窗口中。

实际上parent参数还表示了Qt的内存回收机制，如果对象a作为对象b的构造函数时parent参数，表示对象a是对象b的父对象，这是一种内存回收的依赖关系。即对象b跟随对象a销毁时一并销毁。此时无需控制对象b的销毁过程（手动编写delete）
如果堆内存对象创建时不传递parent参数，表示对对象的销毁需要手动编写delete。

绝大多数情况下，建议传递parent参数。
      这样做也有缺点，缺点就是内存占用，如果a窗口还存在，b对象窗口就不会被销毁。

# 7、堆栈窗口
通常作为独立窗口的内嵌窗口(组件)，并且与QListWidget进行联动。
![图片](https://docimg3.docs.qq.com/image/AgAABovvK88egya8NtpPXbucUuVIoflg.png?w=1003&h=682)
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
```

dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),
            ui->stackedWidget,SLOT(setCurrentIndex(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
```

# 8、新建自定义窗口类
1、在Qt Creator中选中项目名称，鼠标右键点击添加新文件。
2、在弹出的窗口中，按照下图所示进行操作。
![图片](https://docimg5.docs.qq.com/image/AgAABovvK8-wIBTGCkFNxqv0SlL_VmJW.png?w=879&h=551)

3、在弹出的窗口中，选择界面模板后，点击下一步
![图片](https://docimg7.docs.qq.com/image/AgAABovvK8-S40HVq29NP4XX3gNnSfIm.png?w=785&h=576)

4、在弹出的窗口中，输入类名（帕斯卡命名法/大驼峰），点击下一步
![图片](https://docimg3.docs.qq.com/image/AgAABovvK89GBaZwyRNIrrJ6rp4GuuD0.png?w=825&h=584)
5、在项目管理界面直接点击完成，可以看到新的窗口类文件已经添加到项目中了。
![图片](https://docimg5.docs.qq.com/image/AgAABovvK8_FTxygAOdMrI-kd4le6XoA.png?w=283&h=303)
ui如下
![图片](https://docimg7.docs.qq.com/image/AgAABovvK88RFd37yGlAvI49f8j_Uh-_.png?w=1347&h=579)
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mydialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void btnClickedSlot();
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(btnClickedSlot()));
}

void Dialog::btnClickedSlot()
{
    MyDialog *mydlg = new MyDialog(this);
    mydlg->show();
}

Dialog::~Dialog()
{
    delete ui;
}
```

# 9、对象传值
## 9.1 父对象→子对象
此处指的是Qt的parent参数的依赖关系，并非继承关系。
【需求】：转动主窗口中的球， 子窗口中的球跟着转。 
这种情况最佳的解决方案，就是使用C++的成员函数传参。
![图片](https://docimg6.docs.qq.com/image/AgAABovvK88mz5hrZ85HEYiKIAoweI3m.png?w=1372&h=574)
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include "mydialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    MyDialog *mydlg;

private slots:
    void btnClickedSlot();
    void valueChangedSlot(int);
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(btnClickedSlot()));

}

void Dialog::btnClickedSlot()
{
    mydlg = new MyDialog(this);
    mydlg->show();

    connect(ui->dial,SIGNAL(valueChanged(int)),
            this,SLOT(valueChangedSlot(int)));
}

void Dialog::valueChangedSlot(int value)
{
//    qDebug() << value;
    mydlg->myDialogSetValue(value);
}

Dialog::~Dialog()
{
    delete ui;
}
```
myDialog.h
```cpp
#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
    void myDialogSetValue(int);

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
```
myDialog.cpp
```cpp
#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::myDialogSetValue(int value)
{
    ui->dial->setValue(value);
}
```

## 9.2 子对象→父对象
此处指的是Qt的parent参数的依赖关系，并非继承关系。
【需求】：转动子窗口中的球，主窗口中的球跟着转。
这种情况最佳的解决方案是信号槽传参，子对象发射带参数的信号函数，父对象使用参数的槽函数进行接收。
dialog.h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include "mydialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    MyDialog *mydlg;

private slots:
    void btnClickedSlot();
    void valueChangedSlot(int);
    void valueSlot(int);
};

#endif // DIALOG_H
```
dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(btnClickedSlot()));

}

void Dialog::btnClickedSlot()
{
    mydlg = new MyDialog(this);
    mydlg->show();

    connect(ui->dial,SIGNAL(valueChanged(int)),
            this,SLOT(valueChangedSlot(int)));

    connect(mydlg,SIGNAL(valueSignal(int)),
            this,SLOT(valueSlot(int)));
}

void Dialog::valueChangedSlot(int value)
{
//    qDebug() << value;
    mydlg->myDialogSetValue(value);
}

void Dialog::valueSlot(int value)
{
    ui->dial->setValue(value);
}

Dialog::~Dialog()
{
    delete ui;
}
```
myDialog.h
```cpp
#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
    void myDialogSetValue(int);

private:
    Ui::MyDialog *ui;

private slots:
    void myDialogValueChanedSlot(int);

signals:
    void valueSignal(int);
};

#endif // MYDIALOG_H
```
myDialog.cpp
```cpp
#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    connect(ui->dial,SIGNAL(valueChanged(int)),
            this,SLOT(myDialogValueChanedSlot(int)));
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::myDialogSetValue(int value)
{
    ui->dial->setValue(value);
}

void MyDialog::myDialogValueChanedSlot(int value)
{
    // 发射带参数的自定义信号给父对象
    emit valueSignal(value);
}
```












































# Day5
# 1、串口类
在Qt中，处理串口通信主要使用QSerialPort和QSerialPortInfo两个类。
QSerialPort：用于负责串口数据的读写。
QSerialPortInfo：负责获取系统的串口信息。

## 1.1 添加模块
需要在项目配置文件中添加对应的模块。
![图片](https://docimg7.docs.qq.com/image/AgAABovvK8-kDysXLtZPDqE9ACX996wF.png?w=1262&h=399)
## 1.2 基础使用
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8-qZEnv_tBK75IU3hQ6wiyu.png?w=1599&h=681)
1、串口初始化
![图片](https://docimg10.docs.qq.com/image/AgAABovvK88raKEVNrtKHonkXXF1je2Y.png?w=1156&h=432)

dialog .h
```cpp
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QSerialPort *m_serial;

private slots:
    void btnClickedConnectSlot();
    void btnClickedSendSlot();

    void serialReadyReadSlot();
};

#endif // DIALOG_H
```

dialog.cpp
```cpp
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButtonIConnect,SIGNAL(clicked()),
            this,SLOT(btnClickedConnectSlot()));

    connect(ui->pushButtonSend,SIGNAL(clicked()),
            this,SLOT(btnClickedSendSlot()));

    // 串口对象创建
    m_serial = new QSerialPort(this);

    // 连接串口数据接收信号
    connect(m_serial,SIGNAL(readyRead()),
            this,SLOT(serialReadyReadSlot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::btnClickedConnectSlot()
{
    // 打开串口
//    qDebug () << ui->comboBox->currentText();
    m_serial->setPortName(ui->comboBox->currentText());
    if(m_serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "串口打开成功";
    }
    else
    {
        qDebug() << "串口打开失败";
    }
}

void Dialog::btnClickedSendSlot()
{
    // 接收用户输入的内容
    QString str = ui->textEditSend->toPlainText();

    // 将数据从字符串类型，转换为字符类型。并存储到字符数组
    QByteArray data = str.toUtf8();

    // 发送数据
    m_serial->write(data);
}

void Dialog::serialReadyReadSlot()
{
    // 读取数据
    QByteArray data = m_serial->readAll();

    // 显式到text中
    ui->textEditRead->append(QString(data));
}
```

## 1.3 调试串口
![图片](https://docimg4.docs.qq.com/image/AgAABovvK8_LXSJmhvZNSrzkR7LhAo-w.png?w=123&h=119)
将此软件下载到本地，并进行安装。
安装完成后，直接打开，可以看到如下界面：
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8_71wZFexJBO5oFehhLF9p-.png?w=762&h=526)

选择连接的串口号，并点击添加
![图片](https://docimg2.docs.qq.com/image/AgAABovvK8_e2XbjSCJMx7fAbemb34-k.png?w=775&h=532)
添加完成后，可以看到如下界面
![图片](https://docimg5.docs.qq.com/image/AgAABovvK8-Dhg3c4sBLH7NB53ia5POE.png?w=763&h=500)
此时打开串口调试工具
运行自己的程序。
![图片](https://docimg3.docs.qq.com/image/AgAABovvK8-pAhO--MxGap5RmHShjq_f.png?w=1940&h=813)
![图片](https://docimg9.docs.qq.com/image/AgAABovvK8-tlWBWww5BgaO7PgdtB_mw.png?w=1877&h=814)
虚拟串口使用完毕后，建议删除，否则虚拟串口会一直存在并开启。
![图片](https://docimg7.docs.qq.com/image/AgAABovvK89aumS4ZvdPEZIp2eO8kGWF.png?w=772&h=537)
# 2、关于项目
本次项目需要设计一个串口调试工具。界面可以参考以下的界面：
![图片](https://docimg2.docs.qq.com/image/AgAABovvK8-w8rPEy3pF35UFUiuwgkv4.png?w=914&h=829)
使用trae等其他的ai工具来完成项目。
必做要求：
    - 实现串口的收发
    -  串口号可以自动索引当前系统的可用串口
    - 支持用户手动选择要连接的串口号、波特率、数据位等。
    - 接收设置存在两种，ASCII码接收，以及HEX接收
    - 接收到的内容展示到接收窗口中，并且需要显示接收时间
    - 支持一键清空接收区功能
    - 发送功能，发送支持ASCII码发送，以及HEX发送。
    - 并且支持周期循环发送
    - 支持一键清空发送区功能
    - 支持中英文切换功能
    - 界面美化

选做：
    - 项目打包
    - 支持接收数据存储功能
    - 支持错误日志记录功能
    - 支持状态栏显式操作
    - 使用子线程进行数据存储功能，防止主线程阻塞