//
// Created by Ahsan Ghani on 2022-09-11.
//
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class attend
{
    float p=0, t=0, w;
public:
    int enter();
    void calculate();
};

int attend::enter()
{
    int date, month, year;
    int i, n, k, a, c;
    int z[20];
    cout << ">>ENTER ANY KEY TO GIVE THE DATE..." << endl;
    cin >> i;

    while(i)
    {
        cout << "->Enter DATE/MONTH/YEAR: " << endl;
        cin >> date >> month >> year;
        cout << endl;
        if(month== 1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            if(date>31||date==0)
            {
                c=0;
            }
            else
            {
                c=1;
            }
        }
        if(month== 4||month==6||month==9||month==11)
        {
            if(date>30 ||date==0)
            {
                c=0;
            }
            else
            {
                c=1;
            }
        }
        if(month==2)
        {
            if(date>29||date==0)
            {
                c=0;
            }
            else
            {
                c=1;
            }
        }
        if(month>12)
        {
            c=0;
        }
        if(month==0||year==0)
        {
            c=0;
        }
    }
}