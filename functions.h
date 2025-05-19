#ifndef functions_h
#define functions_h

#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <conio.h>
#include <iomanip>


using namespace std;

void SetConsoleSize(int width, int height);
void showArea(char area[][100], int gameCounter, int, string);
void car(char area[][100], int lane);
void delCar(char area[][100], int lane);
void obstacle(char area[][100]);
void heal(char area[][100]);
void Lose(char area[][100]);
bool pause();
void title();
int menu();
void printElement(string[], int size, short x, short y, int color);
void printRules();
void pressKey(WORD keyCode);

#endif // !functions_h
