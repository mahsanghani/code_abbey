//
// Created by Ahsan Ghani on 2022-09-12.
//
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct lesson
{
    float chinesegrade;
    float englishgrade;
    float mathgrade;
};

struct student
{
    char name[10];
    char clas[20];
    int num;
    float sum;
    float average;
    float fangcha;
    lesson less;
};

m[100];
int n = 100;
static int e = 0;

void sort();

void error()
{
    cout << " ---The input is wrong, please re-enter --- " << endl;
    cout << " \n " ;
}

