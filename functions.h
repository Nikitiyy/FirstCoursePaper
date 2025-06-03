#ifndef functions_h
#define functions_h

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>


using namespace std;

void showArea(char area[][100], int gameCounter, int, int, string a = " ");
void car(char area[][100], int lane);
void delCar(char area[][100], int lane);
void obstacle(char area[][100]);
void heal(char area[][100]);
bool pause();
void title();
void printLose();
bool menu();
void printElement(string[], int size, short x, short y, int color,int sleep = 0);
void printRules();
void pressKey(WORD keyCode);

#endif // !functions_h