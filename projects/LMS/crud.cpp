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

void  welcome ()        // Enter the password to enter the system, welcome interface
{
    char password [ 5 ];
    char num [ 5 ];

    strcpy (num, " 123 " );
    loopback3: printf ( "  \n\n\n\n\n\n\n\n " );
    system ( " color F1 " );
    printf ( " \t\t\tWelcome to use the student performance management system! \n " );
    printf ( " \t\t\t\tpassword : " );
    scanf ( " %s " , &password);
    if ( strcmp (password, num) == 0 )
    {
        system ( " cls " );
        system ( " color F0 " );
        printf ( "  \n\n\n\n\n\n\n\n\n\t\t\tWelcome to use the student performance management system! " );
        Sleep ( 300 );
        system ( " cls " );
        system ( " color F2 " );
        printf ( "  \n\n\n\n\n\n\n\n\n\t\t\tWelcome to use the student performance management system! " );
        Sleep ( 300 );
        system ( " cls " );
        system ( " color F3 " );
        printf ( "  \n\n\n\n\n\n\n\n\n\t\t\tWelcome to use the student performance management system! " );
        Sleep ( 300 );
        system ( " cls " );
        system ( " color F4 " );
        printf ( "  \n\n\n\n\n\n\n\n\n\t\t\tWelcome to use the student performance management system! " );
        Sleep ( 300 );
        system ( " cls " );
        system ( " color F5 " );
        printf ( "  \n\n\n\n\n\n\n\n\n\t\t\tWelcome to use the student performance management system! " );
        Sleep ( 300 );
        system ( " cls " );
        system ( " color F0 " );
        printf ( "  \n\n\n\n\n\n\n\n\n\t\t\tWelcome to use the student performance management system! " );
        Sleep ( 300 );
    }
    else
    {
        printf ( " \t\t\t\t password error! " );            // re-output the password error
        Sleep ( 2000 );
        system ( " cls " );
        goto loopback3;
    }
}