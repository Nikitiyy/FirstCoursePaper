#include "functions.h"

void showArea(char area[][100], int gameCounter, int countBuf, int record, string a) {
    const int sizeShot = 21;
    string shot;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 12 };
    SetConsoleCursorPosition(handle, pos);

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
    shot.append("Record: ");
    shot.append(to_string(record));
    shot += '\n';
    for (int i = 0; i < 30; i++) {
        shot.append(" ");
    }
    shot.append(a);


    cout << shot;
}

void printRules() {
    system("cls");
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    SetConsoleTextAttribute(handle, 10); // Зеленый цвет

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
    rules[4] += "Up arrow - upward movement";
    rules[5] += "Down arrow - downward movement";
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
        SetConsoleCursorPosition(handle, pos);
        cout << rules[i];
    }
    pos = { x, y++ };
    SetConsoleCursorPosition(handle, pos);
    cout << "Press any key to come back...";


    //════════════════ ПРАВИЛА ИГРЫ ════════════════
    //Цель игры: избегать препятствий и набирать очки!
    //Управление:
    //  W    - движение вверх
    //  S    - движение вниз
    //  ESC    - пауза
    //
    //Бонусы:
    //  +     - дают дополнительные жизни
    //══════════════════════════════════════════════

    SetConsoleTextAttribute(handle, 7);

    int a = _getch();
    system("cls");
}

void printElement(string butt[], int size, short x, short y, int color, int sleep) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleTextAttribute(handle, color);
    SetConsoleCursorPosition(handle, pos);

    for (int i = 0; i < size; i++) {
        cout << butt[i];
        pos = { x, ++y };
        SetConsoleCursorPosition(handle, pos);
        Sleep(sleep);
    }
    SetConsoleCursorPosition(handle, {0,0});
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
    short x = 59, y = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(handle, pos);
    SetConsoleTextAttribute(handle, 11);

    char rectangle = char(219),
        upRight = char(187),
        downRight = char(188),
        upLeft = char(201),
        downLeft = char(200),
        horizont = char(205),
        vertical = char(186),
        space = char(32);

    const int sizeGameName = 6;
    string gameName[sizeGameName]{
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

void printLose() {
    char rectangle = char(219),
        upRight = char(187),
        downRight = char(188),
        upLeft = char(201),
        downLeft = char(200),
        horizont = char(205),
        vertical = char(186),
        space = char(32);
    const int sizeGameOver = 6;
    string gameOver[sizeGameOver] = {
        {space,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,
        space,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,
        rectangle,rectangle,upRight,space,space,space,rectangle,rectangle,upRight,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,
        space,space,space,space,
        space,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,
        rectangle,rectangle,upRight,space,space,space,rectangle,rectangle,upRight,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,},

        {rectangle,rectangle,upLeft,horizont,horizont,horizont,horizont,downRight,space,space,
        rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,upRight,space,
        rectangle,rectangle,rectangle,upRight,space,rectangle,rectangle,rectangle,vertical,space,
        rectangle,rectangle,upLeft,horizont,horizont,horizont,horizont,downRight,
        space,space,space,space,
        rectangle,rectangle,upLeft,horizont,horizont,horizont,rectangle,rectangle,upRight,space,
        rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,upLeft,horizont,horizont,horizont,horizont,downRight,space,
        rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,upRight,},

        {rectangle,rectangle,vertical,space,space,rectangle,rectangle,rectangle,upRight,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,vertical,space,
        rectangle,rectangle,upLeft,rectangle,rectangle,upLeft,rectangle,rectangle,vertical,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,
        space,space,space,space,
        rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,space,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upLeft,downRight,},

        {rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,vertical,space,
        rectangle,rectangle,vertical,downLeft,horizont,downRight,rectangle,rectangle,vertical,space,
        rectangle,rectangle,upLeft,horizont,horizont,downRight,space,space,
        space,space,space,space,
        rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,upLeft,horizont,horizont,downRight,space,space,space,
        rectangle,rectangle,upLeft,horizont,horizont,rectangle,rectangle,upRight,},

        {downLeft,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,vertical,space,
        rectangle,rectangle,vertical,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,vertical,space,space,space,rectangle,rectangle,vertical,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,
        space,space,space,
        downLeft,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upLeft,downRight,space,
        downLeft,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upLeft,downRight,space,
        rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,rectangle,upRight,space,
        rectangle,rectangle,vertical,space,space,rectangle,rectangle,vertical,},

        {space,downLeft,horizont,horizont,horizont,horizont,horizont,horizont,downRight,space,
        downLeft,horizont,downRight,space,space,downLeft,horizont,downRight,space,
        downLeft,horizont,downRight,space,space,space,downLeft,horizont,downRight,space,
        downLeft,horizont,horizont,horizont,horizont,horizont,horizont,downRight,
        space,space,space,space,
        space,downLeft,horizont,horizont,horizont,horizont,horizont,downRight,space,space,
        space,downLeft,horizont,horizont,horizont,horizont,horizont,downRight,space,space,
        downLeft,horizont,horizont,horizont,horizont,horizont,horizont,downRight,space,
        downLeft,horizont,downRight,space,space,downLeft,horizont,downRight}
        };

  // ██████╗   █████╗  ██╗   ██╗ ███████╗     ██████╗  ██╗   ██╗ ███████╗ ██████╗
  //██╔════╝  ██╔══██╗ ███╗ ███║ ██╔════╝    ██╔═══██╗ ██║   ██║ ██╔════╝ ██╔══██╗
  //██║  ███╗ ███████║ ██╔██╔██║ █████╗      ██║   ██║ ██║   ██║ █████╗   ██████╔╝
  //██║   ██║ ██╔══██║ ██║╚═╝██║ ██╔══╝      ██║   ██║ ██║   ██║ ██╔══╝   ██╔══██╗
  //╚███████║ ██║  ██║ ██║   ██║ ███████╗    ╚██████╔╝ ╚██████╔╝ ███████╗ ██║  ██║
  // ╚══════╝ ╚═╝  ╚═╝ ╚═╝   ╚═╝ ╚══════╝     ╚═════╝   ╚═════╝  ╚══════╝ ╚═╝  ╚═╝

    int changeColor = 0;
    bool rasume = true;
    char a;

    while (rasume) {
        changeColor = (changeColor + 1) % 2;

        if(changeColor)
            printElement(gameOver, sizeGameOver, 41, 19, 11);
        else printElement(gameOver, sizeGameOver, 41, 19, 9);

        Sleep(500);
    
        if (_kbhit()) {
            a = _getch();
            switch (a) {
            case 13: rasume = 0;
            }
        }
            
    }
}