#pragma once
#include<iostream>
#define U 1
#define D 2
#define L 3
#define R 4 
/// <summary>
/// snake节点...坐标
/// </summary>
struct snake { 
	int ix;
	int iy;
	struct snake* next;
};

int zongfen = 0, add = 10;   //分数
snake* head;				 //snake本身							
snake* sn;                   //画snake
snake* food = new snake;     //食物
int status, sleeptime = 100; //难度

void Pos(int x,int y);       //设置光标
void map();					 //画地图
void instersna();            //初始化
int ifove();                 //自杀判断
void cfood();                //产生食物
void welcometogame();        //开始
void endgame();              //结束
void gamestart();            //进入游戏
void pause();                //暂停
void gamecircle();           //控制
void snakemove();            //移动
void cantcrosswall();        //越界判断
bool colourin(int x1, int x2, int y1, int y2, const char* s);  //颜色
