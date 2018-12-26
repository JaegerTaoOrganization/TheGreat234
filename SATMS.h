#pragma once
#include <graphics.h>
#include <time.h>
#include <math.h>
#include<Windows.h>
#include<iostream>
using namespace std;
//图片输出函数
void putBackgroundimgsky();//输出菜单背景图片
void putBgMap();//输出地图背景
void putline(int a, int b, int c, int d);//画出点(a,b)到(c,d)的道路
void putMenu();//输出主菜单
void putFunMenu();//输出功能菜单

int input();//从键盘读入一个数字字符，返回该数字int型
int inputInfoY();//输入Y坐标值，并返回该值
int inputInfoX();//输入X坐标值，并返回该值

