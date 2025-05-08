#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

void SetConsoleSize(int width, int height);
void showArea(char area[][100], int gameCounter, int, string);
void car(char area[][100], int lane);
void delCar(char area[][100], int lane);
void obstacle(char area[][100]);
void buf(char area[][100]);
void Lose(char area[][100]);
bool pause();

int main() {
    setlocale(LC_ALL, "ru");

    SetConsoleSize(110, 30);

    const int rows = 21, columns = 100;
    char area[rows][columns], control;
    bool lose = true;
    int lane = 10,//Позиция автомобиля
        gameCounter = 0,
        countBuf = 0,
        speed = 10;

    srand(time(0));

    for (int i = 1; i < rows - 1; i++) {
        area[i][0] = area[i][99] = '*';
        for (int j = 1; j < columns - 1; j++) {
            area[i][j] = ' ';
        }
    }

    //Инициализация границ поля
    for (int j = 0; j < columns; j++) {
        area[0][j] = '*';
        area[20][j] = '*';
    }

    car(area, lane);

    //инициализация полос дороги
    for (int i = 1; i < columns-1; i+=3) {
        area[4][i] = '-';
        area[8][i] = '-';
        area[12][i] = '-';
        area[16][i] = '-';
    }


    while (lose) {
        gameCounter++;
        static int counter = 0,
            subCounterBuf = 0;
        /*if (gameCounter == 280) speed = 7;*/
        subCounterBuf = (subCounterBuf + 1) % 77;
        counter = (counter + 1) % speed;
        for (int i = 1, j =2; j < columns - 2 ||i < columns - 2;j++, i++) {
            static int subCounter = 0;
            subCounter = (subCounter + 1) % 3;

            area[4][i] = area[4][i + 1];
            area[8][i] = area[8][i + 1];
            area[12][i] = area[12][i + 1];
            area[16][i] = area[16][i + 1];

            area[4][columns - 2] = (subCounter == 2)?'-':' ';
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
            if (area[lane][i] != '#' &&  area[lane][i] != '+') area[lane][i] = ' ';
        }

        delCar(area, lane);
        if (_kbhit()) {
            control = _getch();
            switch (control) {
            case 'w': {
                if (lane > 2) {//ограничение поля
                    lane -= 4;
                }
                break;
            }
            case 's': {
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
            if (countBuf == 0) lose = false;
            else countBuf--;
        }//Завершение игры
        if (area[lane][8] == '+' || area[lane][9] == '+' || area[lane][10] == '+' || area[lane][11] == '+'|| area[lane][12] == '+') {
            if (countBuf < 3) countBuf++;
            else continue;
        }
            car(area, lane);



        if (counter == 1) {
            obstacle(area);
        }
        if (subCounterBuf == 74) buf(area);

        showArea(area, gameCounter, countBuf, " ");
        Sleep(30);
    }
    Lose(area);
    showArea(area, gameCounter, 0, "\nЧтобы вернуться в меню нажмите F");
    
    return 0;

}

void SetConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = { 0, 0, (SHORT)(width - 1), (SHORT)(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    COORD bufferSize = { (SHORT)width, (SHORT)height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);
}

void showArea(char area[][100], int gameCounter, int countBuf, string a = " ") {
    static string shot;
    shot.clear();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(hConsole, pos);

    for (int i = 0; i < 21; i++) {
        shot.append(area[i], 100);
        shot += '\n';
    }
    shot += '\n';
    shot.append("Счёт:");
    shot.append(to_string(gameCounter));
    shot.append(a);
    shot += '\n';
    shot.append("Жизни:");
    shot.append(to_string(countBuf));

    cout << shot;
}

void car(char area[][100], int lane) {
    area[lane][9] = '|';
    area[lane][10] = '=';
    area[lane][11] = '>';
}

void delCar(char area[][100], int lane) {
    area[lane][9] = ' ';
    area[lane][10] = ' ';
    area[lane][11] = ' ';
}

void obstacle(char area[][100]) {
    int posObstacle;

    srand(time(0));
    for (int i = 0; i < 4; i++) {

        posObstacle = rand() % 5 + 1;

        switch (posObstacle) {
        case 1: area[1][97] = '#';
            area[2][97] = '#';
            area[3][97] = '#';
            break;
        case 2: area[5][97] = '#';
            area[6][97] = '#';
            area[7][97] = '#';
            break;
        case 3: area[9][97] = '#';
            area[10][97] = '#';
            area[11][97] = '#';
            break;
        case 4: area[13][97] = '#';
            area[14][97] = '#';
            area[15][97] = '#';
            break;
        case 5: area[17][97] = '#';
            area[18][97] = '#';
            area[19][97] = '#';
            break;
        }
    }
}

void buf(char area[][100]) {
    int posBuf;
    srand(time(0));
    posBuf = rand() % 5 + 1;
    switch (posBuf) {
    case 1: {
        if (area[2][97] != '#') area[2][97] = '+';
        break;
    }
    case 2: {
        if (area[6][97] != '#') area[6][97] = '+';
        break;
    }
    case 3: {
        if (area[10][97] != '#') area[10][97] = '+';
        break;
    }
    case 4: {
        if (area[14][97] != '#') area[14][97] = '+';
        break;
    }
    case 5: {
        if (area[18][97] != '#') area[18][97] = '+';
        break;
    }
    }
}

void Lose(char area[][100]) {
    
}

bool pause() {
    char choseOfMenu = _getch();
    switch (choseOfMenu) {
    case 27: return 1;
    case 'l': return false;

    }

}

