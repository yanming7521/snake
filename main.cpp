#include<iostream>
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include"snakeh.h"
#include"snakef.h"
//using namespace std;
const char* ax = "̰����V1.0 -----Yanminng ";
/// <summary>
/// ���
/// </summary>
/// <returns></returns>
int main() {
	SetConsoleTitle(ax);
	gamestart();  
	gamecircle(); 
	endgame();    
	return 0;
}