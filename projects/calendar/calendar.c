#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

struct Date {
	int dd, mm, yy;
};
struct Date date;

struct Remainder {
	int dd, mm;
	char note[50];
};
struct Remainder r;

COORD xy = { 0,0 };

void gotoxy(int x, int y) {
	xy.X = x;
	xy.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void SetColor(int ForgC) {
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void ClearColor() {
	SetColor(15);
}

void ClearConsoleToColors(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

	SetConsoleTextAttribute(hStdOut, wColor);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}