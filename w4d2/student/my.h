#ifndef _MY_H
#define _MY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sl.h"

#define SAVE_LIVE "save.txt"//文件保存名字
#define SUBJECT 3           //学科数量
#define MENU_H 17           //菜单总高度
#define MENU_W 42           //菜单总宽度
#define DISTANCE_H  5       //菜单离边界距离高度
#define DISTANCE_W  10      //菜单离边界距离宽度

typedef struct
{
    int stnum;
    float subject[SUBJECT];
    float av;
}st;

void menu();
int print(int *q);
void Type();
void List();
int empty();
void Sort();
void Average();
void System_clear();
void savewrite();
int loadwrite();

void Sort2();
void Search();

extern st *student;
extern size_t count;

#endif
