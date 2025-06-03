#include "functions.h"

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

void heal(char area[][100]) {
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

void pressKey(WORD keyCode) {
    INPUT input[2] = { 0 };

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = keyCode;

    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = keyCode;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, input, sizeof(INPUT));
}