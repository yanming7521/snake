#include<iostream>
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include"snakeh.h"
#include"snakef.h"
const char* ax = "Ì°³ÔÉßV1.0 -----Yanminng ";
/// <summary>
/// Èë¿Ú
/// </summary>
/// <returns></returns>
int main() {
	SetConsoleTitle(ax);
	gamestart();  
	gamecircle(); 
	endgame();    
	return 0;
}