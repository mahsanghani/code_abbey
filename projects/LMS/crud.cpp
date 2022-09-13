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

void  show ()           // 1. Browse student information
{
    system ( " cls " );                   // Clear the screen
    int i;
    cout << setiosflags (ios::left)   // left justified
         << setw ( 2 ) << " student number " << "   "  //The output width is 2
         << setw ( 10 ) << " Name " << "   "
         << setw ( 12 ) << " Class "
         << setw ( 8 ) << " Language "
         << setw ( 8 ) << " English "
         << setw ( 8 ) << " Mathematics "
         << setw ( 8 ) << " Total score "
         << setw ( 10 ) << " Average score "
         << setw ( 10 ) << " variance "
         << endl;                                     // Display the first line category
    for (i = 0 ; i <e; i++)
    {
        m [i]. sum =
                (
                        m [i]. less . chinesegrade +
                        m [i]. less . englishgrade +
                        m [i]. less . mathgrade
                );                             // Total score calculation formula

        m [i]. average =
                (
                        m [i]. sum / 3
                );                             // Average score calculation formula

        m [i]. fangcha =
                (
                        (m [i]. less . chinesegrade -m [i]. average ) *
                        (m [i]. less . chinesegrade -m [i]. average ) +
                        (m [i]. less . englishgrade -m [i]. average ) *
                        (m [i]. less . englishgrade -m [i]. average ) +
                        (m [i]. less . mathgrade -m [i]. average ) *
                        (m [i]. less . mathgrade -m [i]. average )
                ) / 3 ;                           // Variance calculation formula

        cout << setiosflags (ios::left)
             << setw ( 5 ) << m [i]. num << "   "
             << setw ( 10 ) << m [i]. name
             << setw ( 14 ) << m [i]. clas
             << setw ( 8 ) << m [i]. less . chinesegrade
             << setw ( 8 ) << m [i]. less . englishgrade
             << setw(8) << m[i].less.mathgrade << setw(8) << m[i].sum
             << setw(10) << m[i].average << setw(10) << m[i].fangcha << endl;
        if (m[i].num == 0) {
          break; // output result
        }
    }
}

void input() {
  system(" cls ");
  int a;
  cout << " -----Enter student information ----- " << endl;
  cout << " Please enter the information, enter 0 to end the entry " << endl;
  cout << " Enter one by one: student ID name, class, language, English, "
          "mathematics "
       << endl;
  for (a = e; a < n; a++) {
    cin >> m[a].num;
    if (m[a].num == 0) {
      break;
    }
    cin >> m[a].name >> m[a].clas >> m[a].less.chinesegrade >>
        m[a].less.englishgrade >> m[a].less.mathgrade;
    e++;
  }
}
