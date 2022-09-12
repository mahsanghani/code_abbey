//
// Created by Ahsan Ghani on 2022-09-12.
//
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

void Password();
void Teacher();
void Student();
void Public();

class STUDENT
{
private:
    char name[50];
    char fname[50];
    char mname[50];
    char date[15];
    char telno[15];
    int sclass;
    char div;
    int rno;
    char stream;
    float marks[5];
    char sec_code[5];
    int attct;
    float per;
    char grade;

    void getper()
    {
        per=(marks[0]+marks[1]+marks[2]+marks[3]+marks[4])/5;
    }

    void getgrade()
    {
        if(per>=80)
            grade='A';
        else if((per>=60)&&(per<=79))
            grade='B';
        else if((per>=40)&&(per<=59))
            grade='C';
        else if((per>=35)&&(per<=39))
            grade='D';
        else if(per<35)
            grade='E';
    }

};