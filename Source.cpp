#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include "windows.h"


using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

int main()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col = 15;

    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, col);

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 160, 240, true);



    int *pos = new int[2]  { 4,7 };
    int* cPos = new int[2] { 4,7 };
    int* score = new int [1] { 0 };

    char key = _getch();
    int kVal = key;
    
    const int arrX = 15;
    const int arrY = 9;


    string map[arrY][arrX] = 
    { 
        //9 columns by 15 rows 
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
    };
 


    for (;;) {


        string mapF[arrY][arrX];
        for (int i = 0; i < arrY; i++) {

            for (int j = 0; j < arrX; j++) {

                mapF[i][j] = map[i][j];

            }
        }

        switch (_getch()) {

        case KEY_UP:
            pos[0] -= 1;
            break;
        case KEY_DOWN:
            pos[0] += 1;
            break;
        case KEY_LEFT:
            pos[1] -= 1;
            break;
        case KEY_RIGHT:
            pos[1] += 1;
            break;
        case KEY_ESC:
            return 0;
            break;
        }

        if (pos[0] > (arrY - 1)) {
            pos[0] = 0;
        }
        if (pos[0] < 0) {
            pos[0] = 8;
        }
        if (pos[1] > (arrX - 1)) {
            pos[1] = 0;
        }
        if (pos[1] < 0) {
            pos[1] = 8;
        }


        int xPos = pos[0];
        int yPos = pos[1];



        int randIntX = 0 + (rand() % static_cast<int>(arrX - 1));
        int randIntY = 0 + (rand() % static_cast<int>(arrY - 1));

        if ((cPos[0] == yPos) && (cPos[1] == xPos))
        { 
            cPos[0] = randIntX;
            cPos[1] = randIntY;
            score[0] = score[0] + 1;
        }

        

        int cX = cPos[0];
        int cY = cPos[1];

        mapF[cY][cX] = "0";
        mapF[xPos][yPos] = "@";
        

        for (int i = 0; i < arrY; i++) {

            for (int j = 0; j < arrX; j++) {
                cout << mapF[i][j];
            }
            cout << endl;
        }

        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n" << "Score: " << score[0] << "\n";
        //cout << "\n" << "The player values of x and y are: " << pos[0] + 1 << " " << pos[1] + 1 << "\n";
        //cout << "\n" << "The coin values of x and y are: " << cPos[0] + 1 << " " << cPos[1] + 1 << "\n";

        key = _getch();
        kVal = key;
        SetConsoleTextAttribute(hConsole, 15);
    }
    
    return 0;
}
