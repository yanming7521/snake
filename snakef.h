#pragma once
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"snakeh.h"
/// <summary>
/// 结束标记
/// </summary>
static int end = 0;
/// <summary>
/// 初始化坐标
/// </summary>
/// <param name="x坐标"></param>
/// <param name="y坐标"></param>
void Pos(int x,int y){  //设置光标
    COORD pos;
    pos.X = x;
    pos.Y = y;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}
/// <summary>
/// 画地图
/// </summary>
void map() {  //地图
    int i = 0;
    for (i = 0; i < 58; i += 2)//打印上下边框
    {
        Pos(i, 0);
        printf("■");      
        Pos(i, 26);
        printf("■");
    }
    for (i = 1; i < 26; i++)//打印左右边框
    {
        Pos(0, i);
        printf("■");
        Pos(56, i);
        printf("■");
    }
}
/// <summary>
/// 初始snake
/// </summary>
void instersna() {  //初始化snake
    snake* sp = new snake;
    int i;
    sp->ix = 24;
    sp->iy = 5;
    sp->next = NULL;
    for (i = 1; i <= 4; i++)
    {
        head = new snake;
        head->next = sp;
        head->ix = 24 + 2 * i;
        head->iy = 5;
        sp = head;
    }
    while (sp)
    {
        Pos(sp->ix, sp->iy);
        printf("■");
        sp = sp->next;
    }
}
/// <summary>
/// 自杀
/// </summary>
/// <returns></returns>
int ifove() {  //咬自己
    snake* self;
    self = head->next;
    while (self)
    {
        if (self->ix == head->ix && self->iy == head->iy)
        {
            return 1;
        }
        self = self->next;
    }
    return 0;
}
/// <summary>
/// food生成
/// </summary>
void cfood() {  //产生食物
    srand((unsigned)time(NULL));
    while ((food->ix % 2) != 0)
    {
        food->ix = rand() % 52 + 3;
    }
    food->iy = rand() % 24 + 1;
    sn = head;
    while (sn->next)
    {
        if (sn->ix == food->ix && sn->iy == food->iy)
        {
            delete(food);
            cfood();
        }
        sn = sn->next;
    }
    Pos(food->ix, food->iy);
    colourin(8, 8, 6, 7, "■");
}
/// <summary>
/// 开始
/// </summary>
void welcometogame()//开始界面
{
    Pos(40, 12);
    printf("欢迎来到贪食蛇游戏\n");
    Pos(40, 25);
   // printf("Programed By HSF.\n");
    system("pause");
    system("cls");
    Pos(35, 12);
    printf("用↑.↓.←.→分别控制蛇的移动\n");
    Pos(40, 25);
    system("pause");
    system("cls");
    Pos(35, 12);
    printf("选择难度：1.简单  2.困难  3.恶魔\n");
    int nandu;
    Pos(35, 14);
    char a = _getche();
    nandu = int(a)-48;
    if (nandu == 1)
    {
        sleeptime = 250;
    }
    if (nandu == 2)
    {
        sleeptime = 150;
    }
    if (nandu == 3)
    {
        sleeptime = 30;
    }
    system("cls");
}
/// <summary>
/// 结束
/// </summary>
void endgame()//结束游戏
{

    system("cls");
    Pos(24, 12);
    if (end == 1)
    {
        printf("对不起，您撞到墙了。游戏结束.");
    }
    else if (end == 2)
    {
        printf("对不起，您咬到自己了。游戏结束.");
    }
    else if (end == 3)
    {
        printf("您的已经结束了游戏。");
    }
    Pos(32, 15);
    printf("您的得分是%d\n\n", zongfen);
    Pos(32, 25);
    system("pause");
    exit(0);
}
/// <summary>
/// 初始化
/// </summary>
void gamestart()//游戏初始化
{
    system("color 87");
    system("mode con cols=100 lines=30");
    welcometogame();
    map();
    instersna();
    cfood();
}
/// <summary>
/// 暂停
/// </summary>
void pause()//暂停
{
    while (true)
    {
        Sleep(300);
        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

    }
}
/// <summary>
/// 越界
/// </summary>
void cantcrosswall()//不能穿墙
{
    if (head->ix == 0 || head->ix == 56 || head->iy == 0 || head->iy == 26)
    {
        end = 1;
        endgame();
    }
}
/// <summary>
/// 移动
/// </summary>
void snakemove()//蛇前进,上U,下D,左L,右R
{
    cantcrosswall();
    snake* nexthead = new snake;
    
    if (status == U)
    {
        nexthead->ix = head->ix;
        nexthead->iy = head->iy - 1;
        if (nexthead->ix == food->ix && nexthead->iy == food->iy)
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            zongfen = zongfen + add;
            cfood();
        }
        else                                               
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn->next->next != NULL)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            Pos(sn->next->ix, sn->next->iy);
            printf("  ");
            free(sn->next);
            sn->next = NULL;
        }
    }
    if (status == D)
    {
        nexthead->ix = head->ix;
        nexthead->iy = head->iy + 1;
        if (nexthead->ix == food->ix && nexthead->iy == food->iy)  
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            zongfen = zongfen + add;
            cfood();
        }
        else                               
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn->next->next != NULL)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            Pos(sn->next->ix, sn->next->iy);
            printf("  ");
            free(sn->next);
            sn->next = NULL;
        }
    }
    if (status == L)
    {
        nexthead->ix = head->ix - 2;
        nexthead->iy = head->iy;
        if (nexthead->ix == food->ix && nexthead->iy == food->iy)
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            zongfen = zongfen + add;
            cfood();
        }
        else                                
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn->next->next != NULL)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            Pos(sn->next->ix, sn->next->iy);
            printf("  ");
            free(sn->next);
            sn->next = NULL;
        }
    }
    if (status == R)
    {
        nexthead->ix = head->ix + 2;
        nexthead->iy = head->iy;
        if (nexthead->ix == food->ix && nexthead->iy == food->iy)
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            zongfen = zongfen + add;
            cfood();
        }
        else                                         
        {
            nexthead->next = head;
            head = nexthead;
            sn = head;
            while (sn->next->next != NULL)
            {
                Pos(sn->ix, sn->iy);
                printf("■");
                sn = sn->next;
            }
            Pos(sn->next->ix, sn->next->iy);
            printf("  ");
            free(sn->next);
            sn->next = NULL;
        }
    }
    if (ifove() == 1)       
    {
        end = 2;
        endgame();
    }
}
/// <summary>
/// 控制
/// </summary>
void gamecircle()//控制游戏        
{
    Pos(64, 15);
    printf("不能穿墙，不能咬到自己\n");
    Pos(64, 17);
    printf("用↑.↓.←.→分别控制蛇的移动.\n");
    Pos(64, 19);
    printf("ESC ：退出游戏.  space：暂停游戏.");
    status = R;
    while (true)
    {
        Pos(64, 10);
        printf("得分：%d  ", zongfen);
        Pos(64, 12);
        printf("每个食物得分：%d分", add);
        if (GetAsyncKeyState(VK_UP) && status != D)
        {
            status = U;
        }
        else if (GetAsyncKeyState(VK_DOWN) && status != U)
        {
            status = D;
        }
        else if (GetAsyncKeyState(VK_LEFT) && status != R)
        {
            status = L;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && status != L)
        {
            status = R;
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            pause();
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            end = 3;
            break;
        }        
        Sleep(sleeptime);
        snakemove();
    }
}
/// <summary>
/// 颜色控制
/// </summary>
/// <param name="x1">修改底色</param>
/// <param name="x2">原底色</param>
/// <param name="y1">修改字色</param>
/// <param name="y2">原字色</param>
/// <param name="s">修改字符串</param>
/// <returns></returns>
bool colourin(int x1, int x2, int y1, int y2, const char* s) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x1 | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y1 | BACKGROUND_INTENSITY);
    printf(s);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x2 | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y2 | BACKGROUND_INTENSITY);
    return true;
}


