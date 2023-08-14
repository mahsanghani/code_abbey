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

void SetColorAndBackground(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}

int check_leapYear(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
		return 1;
	}
	return 0;
}

void increase_month(int* mm, int* yy) {
	++*mm;
	if (*mm > 12) {
		++*yy;
		*mm -= 12;
	}
}

void decrease_month(int* mm, int* yy) {
	--*mm;
	if (*mm < 1) {
		--*yy;
		if (*yy < 1600) {
			print("No record available");
			return;
		}
		*mm += 12;
	}
}

int getNumberOfDays(int month, int year) { //returns the number of days in given month
	switch (month) {                          //and year
	case 1: return(31);
	case 2: if (check_leapYear(year) == 1)
		return(29);
		  else
		return(28);
	case 3: return(31);
	case 4: return(30);
	case 5: return(31);
	case 6: return(30);
	case 7: return(31);
	case 8: return(31);
	case 9: return(30);
	case 10: return(31);
	case 11: return(30);
	case 12: return(31);
	default: return(-1);
	}
}

char* getName(int day) { //returns the name of the day
	switch (day) {
	case 0:return("Sunday");
	case 1:return("Monday");
	case 2:return("Tuesday");
	case 3:return("Wednesday");
	case 4:return("Thursday");
	case 5:return("Friday");
	case 6:return("Saturday");
	default:return("Error in getName() module.Invalid argument passed");
	}
}

void print_date(int mm, int yy) { //prints the name of month and year
	printf("---------------------------\n");
	gotoxy(25, 6);
	switch (mm) {
	case 1: printf("January"); break;
	case 2: printf("February"); break;
	case 3: printf("March"); break;
	case 4: printf("April"); break;
	case 5: printf("May"); break;
	case 6: printf("June"); break;
	case 7: printf("July"); break;
	case 8: printf("August"); break;
	case 9: printf("September"); break;
	case 10: printf("October"); break;
	case 11: printf("November"); break;
	case 12: printf("December"); break;
	}
	printf(" , %d", yy);
	gotoxy(20, 7);
	printf("---------------------------");
}

