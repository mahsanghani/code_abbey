#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int i, j, main_exit;
void menu();

struct date {
	int month, day, year;
};

struct {
	char name[60];
	int age, acc_no;
	char address[60];
	char citizenship[15];
	double phone;
	char acc_type[10];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
} add, upd, rem, check, transaction;

