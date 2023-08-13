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

