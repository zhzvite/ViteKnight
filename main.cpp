#include<iostream>
#include<string>
#include<cstdio>
#include<Windows.h>

#define  wchar_t TCHAR
//#include"Role.h"
const int ScreenWidth = 160;
const int ScreenHeight = 60;
const int minmapWidth = 20;
const int minmapHeight = 10;

using namespace std;
void SetWindowsSize(int ScreenWidth, int ScreenHeight) {
    wchar_t** screen = new wchar_t* [ScreenHeight];

    for (int i = 0; i < ScreenHeight; i++) {
        screen[i] = new wchar_t[ScreenWidth];
    }
    for (int i = 0; i < ScreenHeight; i++) {
        for (int j = minmapHeight; j < ScreenWidth; j++) {
            if ((i == 0 && j == minmapHeight) || (i == ScreenHeight - 1 && j == minmapHeight) || ((i == ScreenHeight - 1) && (j == ScreenWidth - 1)) || (i == 0 && j == ScreenWidth - 1))screen[i][j] = L'+';
            else if (i == 0 || i == ScreenHeight - 1)screen[i][j] = L'-';
            else if (j == minmapHeight || j == ScreenWidth - 1)screen[i][j] = L'|';
            else screen[i][j] = L' ';
        }
    }

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
    COORD buffersize = { ScreenWidth,ScreenHeight };
    SetConsoleScreenBufferSize(hConsole, buffersize);
    SMALL_RECT windowsize = { 0,0,ScreenWidth - 1,ScreenHeight - 1 };
    SetConsoleWindowInfo(hConsole, TRUE, &windowsize);

    // Game Logic
    while (1) {
        /* for (int y = 0; y < minmapHeight; ++y) {
             for (int x = 0; x < minmapWidth; ++x) {
                 WriteConsoleOutputCharacter(hConsole, L"#", 1, { static_cast<SHORT>(x), static_cast<SHORT>(y) }, &dwBytesWritten);
             }
         }*/
        for (int y = 0; y < ScreenHeight; ++y) {
            for (int x = minmapWidth; x < ScreenWidth; ++x) {
                WriteConsoleOutputCharacter(hConsole, &screen[y][x], 1, { static_cast<SHORT>(x), static_cast<SHORT>(y) }, &dwBytesWritten);
            }
        }

        //WriteConsoleOutputCharacter(hConsole, screen, ScreenWidth * ScreenHeight, { 0,0 }, &dwBytesWritten);

    }
}
int main() {
   
    //init screen

    
    SetWindowsSize(ScreenWidth, ScreenHeight);



    return 0;
}
/*
   -
 <-H-<=
  / \
  O
 >|<
 / \

*/

