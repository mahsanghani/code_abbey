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

public:
    void enter()
    {
        cout<<"\t\t\t  -------------------------------"<<"\n";
        cout<<"\t\t\t     ENTER THE STUDENT DETAILS"<<"\n";
        cout<<"\t\t\t  -------------------------------"<<"\n\n";
        cout<<"\t\tNAME OF THE STUDENT    : ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"\t\tFATHER'S NAME          : ";
        cin.getline(fname,50);
        cout<<"\t\tMOTHER'S NAME          : ";
        cin.getline(mname,50);
        cout<<"\t\tDATE OF BIRTH(DD/MM/YY): ";
        cin.getline(date,15);
        cout<<"\t\tTELEPHONE NUMBER       : ";
        cin.getline(telno,15);
        cout<<"\t\tSECURITY CODE          : ";
        cin.getline(sec_code,5);
        cout<<"\t\tCLASS                  : ";
        cin>>sclass;
        cout<<"\t\tDIVISION               : ";
        cin>>div;
        cout<<"\t\tROLL NUMBER            : ";
        cin>>rno;
        cout<<"\t\tDAYS PRESENT           : ";
        cin>>attct;
        cout<<"\n\t\tSTREAM('C' FOR COMPUTER OR 'B' FOR BIOLOGY): ";
        cin>>stream;
        cout<<"\n";
        if(stream=='C')
        {
            cout<<"\t\t\t  -----------------------------"<<"\n";
            cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
            cout<<"\t\t\t  -----------------------------"<<"\n\n";
            cout<<"\t\t\t       PHYSICS    : ";
            cin>>marks[0];
            cout<<"\t\t\t       CHEMISTRY  : ";
            cin>>marks[1];
            cout<<"\t\t\t       MATHEMATICS: ";
            cin>>marks[2];
            cout<<"\t\t\t       COMPUTER   : ";
            cin>>marks[3];
            cout<<"\t\t\t       ENGLISH    : ";
            cin>>marks[4];
        }
        else
        {
            cout<<"\t\t\t  -----------------------------"<<"\n";
            cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
            cout<<"\t\t\t  -----------------------------"<<"\n\n";
            cout<<"\t\t\t       PHYSICS    : ";
            cin>>marks[0];
            cout<<"\t\t\t       CHEMISTRY  : ";
            cin>>marks[1];
            cout<<"\t\t\t       MATHEMATICS: ";
            cin>>marks[2];
            cout<<"\t\t\t       BIOLOGY    : ";
            cin>>marks[3];
            cout<<"\t\t\t       ENGLISH    : ";
            cin>>marks[4];
        }
        cout<<"\n\n";
        getper();
        getgrade();
    }
};