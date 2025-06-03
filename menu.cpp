#include "functions.h"

bool menu() {
    char upRight = char(187),
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

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    title();

    int const rows = 23,
        columns = 100;

    string topMenu,
        midMenu,
        bottMenu;

    topMenu += upLeft;
    for (int i = 1; i < columns - 1; i++) {
        topMenu += horizont;
    }
    topMenu += upRight;

    midMenu += vertical;
    for (int i = 1; i < columns - 1; i++) {
        midMenu += space;
    }
    midMenu += vertical;

    bottMenu += downLeft;
    for (int i = 1; i < columns - 1; i++) {
        bottMenu += horizont;
    }
    bottMenu += downRight;

    string areaMenu[rows];
    areaMenu[0].append(topMenu);
    for (int i = 1; i < rows - 1; i++) {
        areaMenu[i].append(midMenu);
    }
    areaMenu[rows - 1].append(bottMenu);

    const int sizePlay = 7;
    string play[sizePlay]{
        {singleUpLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleUpRight},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,'P','L','A','Y',space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleDownLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleDownRight},
    };

    const int sizeRules = 5;
    string rules[sizeRules]{
        {singleUpLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleUpRight},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleVertical,space,space,space,space,space,space,space,'R','U','L','E', 'S',space,space,space,space,space,space,space,singleVertical},
        {singleVertical,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,singleVertical},
        {singleDownLeft,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleHorizont,singleDownRight},
    };

    const int sizeEsc = 3;
    string esc[sizeEsc]{
        {singleUpLeft,singleHorizont,singleHorizont,singleHorizont,singleUpRight},
        {singleVertical, 'E','S','C',singleVertical},
        {singleDownLeft,singleHorizont,singleHorizont,singleHorizont,singleDownRight}
    };

    int blue = 11,
        blackOnBlue = 176;
    int currentKey;
    //1 - play
    //2 - rules
    char chose;

    currentKey = 1;

    printElement(areaMenu, rows, 30, 10, blue, 15);
    printElement(esc, sizeEsc, 31, 11, blue);
    printElement(play, sizePlay, 65, 14, blackOnBlue);
    printElement(rules, sizeRules, 68, 23, blue);

    //13 - enter
    //72 - стрелка вверх
    //80 - стрелка вниз
    //27 - esc

    while (true) {
        for (;;) {
            chose = _getch();
            if (chose == 27 || chose == 72 || chose == 80 || chose == 13)
                break;
        }
        
        switch (chose) {
        case 27: {
            return 1;
        }
        case 80:
        case 72: {
            if (currentKey == 2) {
                printElement(play, sizePlay, 65, 14, blackOnBlue);
                printElement(rules, sizeRules, 68, 23, blue);
                currentKey = 1;
            }
            else {
                printElement(play, sizePlay, 65, 14, blue);
                printElement(rules, sizeRules, 68, 23, blackOnBlue);
                currentKey = 2;
            }
            break;
        }
        case 13: {
            if (currentKey == 1)
                return 0;
            else {
                SetConsoleTextAttribute(handle, 15);
                printRules();
                printElement(areaMenu, rows, 30, 10, blue, 15);
                printElement(esc, sizeEsc, 31, 11, blue);
                printElement(play, sizePlay, 65, 14, blackOnBlue);
                printElement(rules, sizeRules, 68, 23, blue);
                title();
                currentKey = 1;
            }
        }
        }
    }
}