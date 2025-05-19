#include "functions.h"
#include <fstream>

int main() {
    //SetConsoleOutputCP(437);
    //SetConsoleSize(110, 30);
    //setlocale(LC_ALL, "ru");
    pressKey(0x7A);
    const int rows = 21, columns = 100;
    char area[rows][columns], control;
    bool lose = true;
    int lane = 10,//Позиция автомобиля
        gameCounter,
        countHeal = 0,//Для спавна +
        speed = 10,
        endOfGame;

    
    
    
    while (true) {
        if (!menu())
            exit(0);
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        Sleep(50);
        title();

        gameCounter = 0;

        for (int i = 1; i < rows - 1; i++) {
            area[i][0] = area[i][99] = '*';
            for (int j = 1; j < columns - 1; j++) {
                area[i][j] = ' ';
            }
        }
        for (int j = 0; j < columns; j++) {
            area[0][j] = '*';
            area[20][j] = '*';
        }//Создание границ поля

        car(area, lane);

        //Создание полос дороги
        for (int i = 1; i < columns - 1; i += 3) {
            area[4][i] = '-';
            area[8][i] = '-';
            area[12][i] = '-';
            area[16][i] = '-';
        }

        static int counter,
            subCounterHeal;
        
        counter = 0;
        subCounterHeal = 0;
        

        while (lose) {
            gameCounter++;
            subCounterHeal = (subCounterHeal + 1) % 77;
            counter = (counter + 1) % speed;
            for (int i = 1, j = 2; j < columns - 2 || i < columns - 2; j++, i++) {
                static int subCounter = 0;
                subCounter = (subCounter + 1) % 3;

                area[4][i] = area[4][i + 1];
                area[8][i] = area[8][i + 1];
                area[12][i] = area[12][i + 1];
                area[16][i] = area[16][i + 1];

                area[4][columns - 2] = (subCounter == 2) ? '-' : ' ';
                area[8][columns - 2] = (subCounter == 2) ? '-' : ' ';
                area[12][columns - 2] = (subCounter == 2) ? '-' : ' ';
                area[16][columns - 2] = (subCounter == 2) ? '-' : ' ';

                //Перемещение препятствий
                area[1][i] = area[1][i + 1];
                area[2][i] = area[2][i + 1];
                area[3][i] = area[3][i + 1];
                area[5][i] = area[5][i + 1];
                area[6][i] = area[6][i + 1];
                area[7][i] = area[7][i + 1];
                area[9][i] = area[9][i + 1];
                area[10][i] = area[10][i + 1];
                area[11][i] = area[11][i + 1];
                area[13][i] = area[13][i + 1];
                area[14][i] = area[14][i + 1];
                area[15][i] = area[15][i + 1];
                area[17][i] = area[17][i + 1];
                area[18][i] = area[18][i + 1];
                area[19][i] = area[19][i + 1];
            }
            for (int i = 1; i < 9; i++) {
                if (area[lane][i] != '#' && area[lane][i] != '+') area[lane][i] = ' ';
            }

            delCar(area, lane);
            if (_kbhit()) {
                control = _getch();
                switch (control) {
                case 72: {
                    if (lane > 2) {//ограничение поля
                        lane -= 4;
                    }
                    break;
                }
                case 80: {
                    if (lane < 18) {//ограничение поля
                        lane += 4;
                    }
                    break;
                }
                case 27: {
                    lose = pause();
                    break;
                }
                }
            }
            if (area[lane][9] == '#' || area[lane][10] == '#' || area[lane][11] == '#' || area[lane][12] == '#') {
                if (countHeal == 0) lose = false;
                else countHeal--;
            }//Завершение игры
            if (area[lane][8] == '+' || area[lane][9] == '+' || area[lane][10] == '+' || area[lane][11] == '+' || area[lane][12] == '+') {
                if (countHeal < 3) countHeal++;
                else continue;
            }//Получение бонуса
            car(area, lane);



            if (counter == 1) {
                obstacle(area);
            }
            if (subCounterHeal == 74) heal(area);

            showArea(area, gameCounter, countHeal, " ");
            Sleep(50);
        }
        Lose(area);
        showArea(area, gameCounter, 0, "Press any key to come back");
        _getch();
        lose = true;
        system("cls");
    }
    
    return 0;

}
