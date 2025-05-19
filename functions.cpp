#include "functions.h"

void SetConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = { 0, 0, (SHORT)(width - 1), (SHORT)(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    COORD bufferSize = { (SHORT)width, (SHORT)height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);
}

void showArea(char area[][100], int gameCounter, int countBuf, string a = " ") {
    static const int sizeShot = 21;
    static string shot;
    for (int i = 0; i < sizeShot; i++) {
        shot.clear();
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 12 };
    SetConsoleCursorPosition(hConsole, pos);

    for (int i = 0; i < 30; i++) {
        shot.append(" ");
    }
    for (int i = 0; i < sizeShot; i++) {
        shot.append(area[i], 100);
        shot += '\n';
        for (int i = 0; i < 30; i++) {
            shot.append(" ");
        }
    }
    shot += '\n';
    for (int i = 0; i < 30; i++) {
        shot.append(" ");
    }
    shot.append("Count:");
    shot.append(to_string(gameCounter));
    shot += '\n';

    for (int i = 0; i < 30; i++) {
        shot.append(" ");
    }
    shot.append("Health:");
    shot.append(to_string(countBuf));
    shot += '\n';
    for (int i = 0; i < 30; i++) {
        shot.append(" ");
    }
    shot.append(a);
    
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

void Lose(char area[][100]) {

}

bool pause() {
    char rectangle = char(219),
        upRight = char(187),
        downRight = char(188),
        upLeft = char(201),
        downLeft = char(200),
        horizont = char(205),
        vertical = char(186),
        space = char(32),

        singleUpRight = char(191),
        singleDownRight = char(217),
        singleUpLeft = char(218),
        singleDownLeft = char(192),
        singleHorizont = char(196),
        singleVertical = char(179);
   int const sizeTitlePause = 6;
   string titlePause[sizeTitlePause]{
       {rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,
       space,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,
       rectangle,rectangle,upRight,space,space,space,rectangle,rectangle,upRight,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight},

       {rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,upRight,space,
       rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,upRight,space,
       rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
       rectangle,rectangle,upLeft,horizont,horizont,horizont,horizont,downRight,space,
       rectangle,rectangle,upLeft,horizont,horizont,horizont,horizont,downRight,space},

       {rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upLeft,downRight,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,vertical,space,
       rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space},

       {rectangle,rectangle,upLeft,horizont,horizont,horizont,downRight,space,space,
       rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,vertical,space,
       rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
       downLeft,horizont,horizont,horizont,horizont,rectangle,rectangle,vertical,space,
       rectangle,rectangle,upLeft,horizont,horizont,downRight},

       {rectangle,rectangle,vertical,space,space,space,space,space,space,
       rectangle,rectangle,vertical,space,space,rectangle,rectangle,vertical,space,
       downLeft,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upLeft,downRight,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,vertical,space,
       rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight},

       {downLeft,horizont,downRight,space,space,space,space,space,space,
       downLeft,horizont,downRight,space,space,downLeft,horizont,downRight,space,
       space,downLeft,horizont,horizont,horizont,horizont,horizont,downRight,space,space,
       downLeft,horizont,horizont,horizont,horizont,horizont,horizont,downRight,space,
       downLeft,horizont,horizont,horizont,horizont,horizont,horizont,downRight,space}
   };

   //██████╗   █████╗  ██╗   ██╗ ███████╗ ███████╗
   //██╔══██╗ ██╔══██╗ ██║   ██║ ██╔════╝ ██╔════╝
   //██████╔╝ ███████║ ██║   ██║ ███████╗ █████╗
   //██╔═══╝  ██╔══██║ ██║   ██║ ╚════██║ ██╔══╝
   //██║      ██║  ██║ ╚██████╔╝ ███████║ ███████╗
   //╚═╝      ╚═╝  ╚═╝  ╚═════╝  ╚══════╝ ╚══════╝

   const int sizeRasume = 4;
   string rasume[sizeRasume]{
       {singleUpLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleUpRight},
       {singleVertical,space,space,space,space,space,space,'r','a','s','u','m','e',space,space,space,space,space,space,singleVertical},
       {singleDownLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleDownRight},
       {"       (space)        "}
   };

   const int sizeLeave = 4;
   string leave[sizeLeave]{
       {singleUpLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleUpRight},
       {singleVertical,'l','e','a','v','e',singleVertical},
       {singleVertical,'(','e','s','c',')',singleVertical},
       {singleDownLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleDownRight},
   };
   printElement(leave, sizeLeave, 31, 13, 11);
   printElement(titlePause, sizeTitlePause, 55, 17, 11);
   printElement(rasume, sizeRasume, 67, 25, 11);

   char choseOfMenu;
   for (;;) {
       choseOfMenu = _getch();
       if (choseOfMenu == 27 || choseOfMenu == 32)
           break;
   }
    switch (choseOfMenu) {
    case 27: return 0;
    case 32: return 1;
    }



}

void title() {
    short x = 57, y = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, 11);

    char rectangle = char(219),
        upRight = char(187),
        downRight = char(188),
        upLeft = char(201),
        downLeft = char(200),
        horizont = char(205),
        vertical = char(186),
        space = char(32);

    const int sizeGameName = 6;
    string gameName[sizeGameName] {
        {rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upRight, space, space,
        rectangle, rectangle, rectangle, rectangle, rectangle, upRight, space, space,
        rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upRight,
        rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upRight,
        rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upRight},
        
        {rectangle, rectangle, upLeft, horizont, horizont, rectangle, rectangle, upRight,
        rectangle, rectangle, upLeft, horizont, horizont, rectangle, rectangle, upRight,
        rectangle, rectangle, upLeft, horizont, horizont, horizont, horizont, downRight,
        rectangle, rectangle, upLeft, horizont, horizont, horizont, horizont, downRight,
        rectangle, rectangle, upLeft, horizont, horizont, rectangle, rectangle, upRight},
        
        {rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upLeft, downRight,
        rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, vertical,
        rectangle, rectangle, vertical, space, space, space, space, space,
        rectangle, rectangle, rectangle, rectangle, rectangle, upRight, space, space,
        rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upLeft, downRight},
        
        {rectangle, rectangle, upLeft, horizont, horizont, rectangle, rectangle, upRight,
        rectangle, rectangle, upLeft, horizont, horizont, rectangle, rectangle, vertical,
        rectangle, rectangle, vertical, space, space, space, space, space,
        rectangle, rectangle, upLeft, horizont, horizont, downRight, space, space,
        rectangle, rectangle, upLeft, horizont, horizont, rectangle, rectangle, upRight},
        
        {rectangle, rectangle, vertical, space, space, rectangle, rectangle, vertical,
        rectangle, rectangle, vertical, space, space, rectangle, rectangle, vertical,
        downLeft, rectangle, rectangle, rectangle, rectangle, rectangle, rectangle, upRight,
        rectangle, rectangle, rectangle, rectangle,rectangle, rectangle, rectangle, upRight,
        rectangle, rectangle, vertical, space, space, rectangle, rectangle, vertical},
        
        {downLeft, horizont, downRight, space, space, downLeft, horizont, downRight,
        downLeft, horizont, downRight, space, space, downLeft, horizont, downRight,
        space, downLeft, horizont, horizont, horizont, horizont, horizont, downRight,
        downLeft, horizont, horizont, horizont,horizont, horizont, horizont, downRight,
        downLeft, horizont, downRight, space, space, downLeft, horizont, downRight}
    };
    
    //██████╗  █████╗  ██████╗███████╗██████╗ 
    //██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗
    //██████╔╝███████║██║     █████╗  ██████╔╝
    //██╔══██╗██╔══██║██║     ██╔══╝  ██╔══██╗
    //██║  ██║██║  ██║╚██████╗███████╗██║  ██║
    //╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚═╝  ╚═╝
    
    printElement(gameName, sizeGameName, x, y, 11);
}

void printRules() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    SetConsoleTextAttribute(hConsole, 10); // Зеленый цвет

    int  horizont = char(205);
    

    const int sizeRules = 11;
    string rules[sizeRules]{};

    for (int i = 0; i < 16; i++) {
        rules[0] += horizont;
    }
    rules[0] += "RULES";
    for (int i = 0; i < 16; i++) {
        rules[0] += horizont;
    }
    rules[1] += "The goal of the game: to avoid ";
    rules[2] += "obstacles and score points!";
    rules[3] += "Control:";
    rules[4] += "W - upward movement";
    rules[5] += "S - downward movement";
    rules[6] += "ESC - pause";
    rules[7] += "  ";
    rules[8] += "Bonuses:";
    rules[9] += "+ - extra lives";
    for (int i = 0; i < 37; i++) {
        rules[10] += horizont;
    }
    system("cls");
    title();
    short x = 58, y = 10;
    for (int i = 0; i < sizeRules; i++) {
        pos = { x, y++ };
        SetConsoleCursorPosition(hConsole, pos);
        cout << rules[i];
    }
    pos = { x, y++ };
    SetConsoleCursorPosition(hConsole, pos);
    cout << "Press any key to come back...";


//════════════════ ПРАВИЛА ИГРЫ ════════════════
//Цель игры: избегать препятствий и набирать очки!
//Управление:
//  W    - движение вверх
//  S    - движение вниз
//  ESC    - пауза
//  F      - возврат в меню
//
//Бонусы:
//  +     - дают дополнительные жизни
//══════════════════════════════════════════════

    SetConsoleTextAttribute(hConsole, 7);
    
    _getch();
}

void printElement(string butt[], int size, short x, short y, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleTextAttribute(hConsole, color);
    SetConsoleCursorPosition(hConsole, pos);

    for (int i = 0; i < size; i++) {
        Sleep(10);
        cout << butt[i];
        pos = { x, ++y };
        SetConsoleCursorPosition(hConsole, pos);
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
