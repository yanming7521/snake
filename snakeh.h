#pragma once
#include<iostream>
#define U 1
#define D 2
#define L 3
#define R 4 
/// <summary>
/// snake�ڵ�...����
/// </summary>
struct snake { 
	int ix;
	int iy;
	struct snake* next;
};

int zongfen = 0, add = 10;   //����
snake* head;				 //snake����							
snake* sn;                   //��snake
snake* food = new snake;     //ʳ��
int status, sleeptime = 100; //�Ѷ�

void Pos(int x,int y);       //���ù��
void map();					 //����ͼ
void instersna();            //��ʼ��
int ifove();                 //��ɱ�ж�
void cfood();                //����ʳ��
void welcometogame();        //��ʼ
void endgame();              //����
void gamestart();            //������Ϸ
void pause();                //��ͣ
void gamecircle();           //����
void snakemove();            //�ƶ�
void cantcrosswall();        //Խ���ж�
bool colourin(int x1, int x2, int y1, int y2, const char* s);  //��ɫ
