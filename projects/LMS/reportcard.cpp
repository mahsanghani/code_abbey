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

    void display_report()
    {
        cout<<"----------------------------------------";
        cout<<"---------------------------------------\n";
        cout<<"                        THE EMIRATES NATIONAL SCHOOL\n\n";
        cout<<"                             STUDENT REPORT CARD\n";
        cout<<"----------------------------------------";
        cout<<"---------------------------------------\n\n";
        cout<<"                         ------------------------\n";
        cout<<"                             PERSONAL DETAILS\n";
        cout<<"                         ------------------------\n\n";
        cout<<"NAME: "<<name<<"\t\t";
        cout<<"CLASS: "<<sclass<<"\t";
        cout<<"DIV: "<<div<<"\t\t";
        cout<<"ROLL NO: "<<rno<<"\n\n";
        cout<<"DATE OF BIRTH: "<<date<<"\t";
        if(stream=='C')
        {
            cout<<"STREAM: "<<"COMPUTER"<<"\t";
        }
        else if(stream=='B')
        {
            cout<<"STREAM: "<<"BIOLOGY"<<"\t";
        }
        cout<<"TELEPHONE: "<<telno<<"\n\n";
        cout<<"FATHERS NAME: "<<fname<<"\t\t\t";
        cout<<"MOTHERS NAME: "<<mname<<"\n\n";
        cout<<"                        ----------------------------\n";
        cout<<"                            ACADEMIC PERFORMANCE\n";
        cout<<"                        ----------------------------\n\n";
        cout<<"                 ---------------------------------------\n";
        cout<<"                                  MARKS\n";
        cout<<"                 ---------------------------------------\n";
        if(stream=='C')
        {
            cout<<"\t\t\t  PHYSICS\t"<<marks[0]<<"\n";
            cout<<"\t\t\t  CHEMISTRY\t"<<marks[1]<<"\n";
            cout<<"\t\t\t  MATHS\t\t"<<marks[2]<<"\n";
            cout<<"\t\t\t  COMPUTER\t"<<marks[3]<<"\n";
            cout<<"\t\t\t  ENGLISH\t"<<marks[4]<<"\n";
        }
        else if(stream=='B')
        {
            cout<<"\t\t\t  PHYSICS\t"<<marks[0]<<"\n";
            cout<<"\t\t\t  CHEMISTRY\t"<<marks[1]<<"\n";
            cout<<"\t\t\t  MATHS\t\t"<<marks[2]<<"\n";
            cout<<"\t\t\t  BIOLOGY\t"<<marks[3]<<"\n";
            cout<<"\t\t\t  ENGLISH\t"<<marks[4]<<"\n";
        }
        cout<<"                -------------------        ------------\n";
        cout<<"                 PERCENTAGE: "<<per<<"%"<<"           ";
        cout<<"GRADE: "<<grade<<"\n";
        cout<<"                -------------------        ------------\n\n";
    }

    void display_all()
    {
        cout<<"\t\tNAME: "<<name<<"\n";
        cout<<"\t\tFATHER: "<<fname<<"\t"<<"MOTHER: "<<mname<<"\n";
        cout<<"\t\tROLL NO: "<<rno<<"\t"<<"SECURE CODE: "<<sec_code<<"\n";
        cout<<"\t\tCLASS: "<<sclass<<" "<<div<<"\t";
        cout<<"STREAM: "<<stream<<"\n";
        cout<<"\t\tTELEPHONE NO: "<<telno<<"\n\n";
        cout<<"\t\t                     MARKS"<<"\n";
        cout<<"\t\tPHY\tCHEM\tMATHS\tBIO/COMP\tENG"<<"\n";
        cout<<"\t\t"<<marks[0]<<"\t"<<marks[1]<<"\t"<<marks[2]<<"\t";
        cout<<marks[3]<<"\t\t"<<marks[4]<<"\n\n";
        cout<<"\t\tPERCENTAGE: "<<per<<"%\t\t"<<"GRADE: "<<grade<<"\n";
        cout<<"\t\tATTENDANCE: "<<attct;
    }

    friend void del();
    friend void modify();
    friend void search();
    friend void search_student();
    friend void sort();
    friend void sortmark();
    friend void sortper();
};

void add()
{
    STUDENT s;
    ofstream f("Record.dat",ios::binary|ios::app);
    s.enter();
    f.write((char*)&s,sizeof(s));
    f.close();
}

void dispall()
{
    STUDENT s;
    ifstream f("Record.dat");
    if(!f)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout<<"\n\n\n\n\n\n\n\n";
    }
    else
    {
        cout<<"\t\t\t  ---------------------------"<<"\n";
        cout<<"\t\t\t     LIST OF CLASS RECORDS"<<"\n";
        cout<<"\t\t\t  ---------------------------"<<"\n\n";
        while(f.read((char*)&s,sizeof(s)))
        {
            s.display_all();
            cout<<"\n\n\n\t\t---------------------------------------------\n\n\n";
        }
    }
    f.close();
}

void del()
{
    STUDENT s;
    ifstream f1("Record.dat");
    ofstream f2("Temp.dat",ios::binary);
    int n,flag=0;
    if(!f1)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout<<"\n\n\n\n\n\n\n\n";
    }
    else
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t";
        cout<<"ENTER THE ROLL NUMBER OF THE STUDENT: ";
        cin>>n;
        system("cls");
        while(f1.read((char*)&s,sizeof(s)))
        {
            if(n!=s.rno)
            {
                f2.write((char*)&s,sizeof(s));
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
            cout<<"\n\n\n\n\n\n\n\n";
        }
        else
        {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t";
            cout<<"THE RECORD WAS DELETED SUCCESSFULLY";
            cout<<"\n\n\n\n\n\n\n\n";
        }
    }
    f1.close();
    f2.close();
    remove("Record.dat");
    rename("Temp.dat","Record.dat");
}

void modify()
{
    STUDENT s;
    ifstream f1("Record.dat");
    ofstream f2("Temp.dat",ios::binary);
    int n,flag=0;
    if(!f1)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout<<"\n\n\n\n\n\n\n\n";
    }
    else
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t";
        cout<<"ENTER THE ROLL NUMBER OF THE STUDENT: ";
        cin>>n;
        system("cls");
        while(f1.read((char*)&s,sizeof(s)))
        {
            if(n==s.rno)
            {
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t";
                cout<<"ENTER THE MODIFIED DETAILS OF THE STUDENT";
                Sleep(3000);
                system("cls");
                s.enter();

                f2.write((char*)&s,sizeof(s));
                flag=1;
            }
            else
            {
                f2.write((char*)&s,sizeof(s));
            }
        }
        if(flag==0)
        {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
            cout<<"\n\n\n\n\n\n\n\n";
        }
    }
    f1.close();
    f2.close();
    remove("Record.dat");
    rename("Temp.dat","Record.dat");
}

