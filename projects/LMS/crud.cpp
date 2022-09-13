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

void welcome() {
  char password[5];
  char num[5];

  strcpy(num, " 123 ");
loopback3:
  printf("  \n\n\n\n\n\n\n\n ");
  system(" color F1 ");
  printf(
      " \t\t\tWelcome to use the student performance management system! \n ");
  printf(" \t\t\t\tpassword : ");
  scanf(" %s ", &password);
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
      printf(" \t\t\t\t password error! ");
      Sleep(2000);
      system ( " cls " );
        goto loopback3;
    }
}

void show() {
  system(" cls ");
  int i;
  cout << setiosflags(ios::left) << setw(2) << " student number "
       << "   " << setw(10) << " Name "
       << "   " << setw(12) << " Class " << setw(8) << " Language " << setw(8)
       << " English " << setw(8) << " Mathematics " << setw(8)
       << " Total score " << setw(10) << " Average score " << setw(10)
       << " variance " << endl;
  for (i = 0; i < e; i++) {
    m[i].sum =
        (m[i].less.chinesegrade + m[i].less.englishgrade + m[i].less.mathgrade);

    m[i].average = (m[i].sum / 3);

    m[i].fangcha = ((m[i].less.chinesegrade - m[i].average) *
                        (m[i].less.chinesegrade - m[i].average) +
                    (m[i].less.englishgrade - m[i].average) *
                        (m[i].less.englishgrade - m[i].average) +
                    (m[i].less.mathgrade - m[i].average) *
                        (m[i].less.mathgrade - m[i].average)) /
                   3;

    cout << setiosflags (ios::left)
             << setw ( 5 ) << m [i]. num << "   "
             << setw ( 10 ) << m [i]. name
             << setw ( 14 ) << m [i]. clas
             << setw ( 8 ) << m [i]. less . chinesegrade
             << setw ( 8 ) << m [i]. less . englishgrade
             << setw(8) << m[i].less.mathgrade << setw(8) << m[i].sum
             << setw(10) << m[i].average << setw(10) << m[i].fangcha << endl;
        if (m[i].num == 0) {
          break;
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

void delete() {
  show();
  cout << " ---Enter the student ID to be deleted: --- ";
  int a;
  cin >> a;
  for (int i = 0; i < e; i++) {
    if (a == m[i].num) {
      int j;
      for (j = i; j < e - 1; j++) {
        strcpy(m[j].name, m[j + 1].name);
        strcpy(m[j].clas, m[j + 1].clas);
        m[j].less.chinesegrade = m[j + 1].less.chinesegrade;
        m[j].less.englishgrade = m[j + 1].less.englishgrade;
        m[j].less.mathgrade = m[j + 1].less.mathgrade;
        m[j].num = m[j + 1].num;
        m[j].sum = m[j + 1].sum;
        m[j].average = m[j + 1].average;
        m[j].fangcha = m[j + 1].fangcha;
      }

      for (i = 0; i < e - 1; i++) {
        cout << setw(5) << m[i].num << setw(10) << m[i].name << setw(15)
             << m[i].clas << setw(10) << m[i].less.chinesegrade << setw(10)
             << m[i].less.englishgrade << setw(10) << m[i].less.mathgrade
             << setw(10) << m[i].less.mathgrade << setw(8) << m[i].sum
             << setw(10) << m[i].average << setw(10) << m[i].fangcha << endl;
      }
      cout << " ---Student information deleted successfully --- " << endl;
      break;
    }
  }
}

void numsearch() {
  show();
  cout << " Please enter the student ID you are looking for: " << endl;
  int a;
  cin >> a;
  int BOOL = 0;
  for (int i = 0; i < n; i++) {
    if (a == m[i].num) {
      cout << setiosflags(ios::left) << setw(2) << " student number "
           << "    " << setw(10) << " Name " << setw(10) << " Class "
           << setw(10) << " Language " << setw(10) << " English " << setw(10)
           << " Mathematics " << endl;
      cout << setiosflags(ios::left) << setw(5) << m[i].num << "   " << setw(10)
           << m[i].name << setw(10) << m[i].clas << setw(10)
           << m[i].less.chinesegrade << setw(10) << m[i].less.englishgrade
           << setw(10) << m[i].less.mathgrade << endl;
      cout << endl;
      BOOL = 1;
    }
  }

  if (BOOL == 0) {
    cout << " ---There is no information you want to query! --- " << endl;
  }
}

void namesearch() {
  show();
  cout << " Please enter the name you are looking for: " << endl;
  string a;
  cin >> a;
  int BOOL = 0;
  for (int i = 0; i < n; i++) {
    if (a == m[i].name) {
      cout << setiosflags(ios::left) << setw(2) << " student number "
           << "    " << setw(10) << " Name " << setw(10) << " Class "
           << setw(10) << " Language " << setw(10) << " English " << setw(10)
           << " Mathematics " << endl;
      cout << setiosflags(ios::left) << setw(5) << m[i].num << "   " << setw(10)
           << m[i].name << setw(10) << m[i].clas << setw(10)
           << m[i].less.chinesegrade << setw(10) << m[i].less.englishgrade
           << setw(10) << m[i].less.mathgrade << endl;
      cout << endl;
      BOOL = 1;
    }
  }
  if (BOOL == 0) {
    cout << " ---Sorry there is no information you want to query --- " << endl;
  }
}

void lesssearch() // 6. Find output information by course
{
  show();
  cout << " ---Please enter the course you are looking for: --- " << endl;
  cout << " 1. Language " << endl;
  cout << " 2. English " << endl;
  cout << " 3. Mathematics " << endl;
  string a;
  cin >> a;
  cout << setiosflags(ios::left) << setw(2) << setw(10) << " Name " << setw(10)
       << " Result: " << endl;
  int BOOL = 0;
  for (int i = 0; i < e; i++) {
    if (a == " 1 ") {
      cout << setiosflags(ios::left) << setw(5) << setw(10) << m[i].name
           << setw(10) << m[i].less.chinesegrade << endl;
      BOOL = 1;
    } else if (a == " 2 ") {
      cout << setiosflags(ios::left) << setw(5) << setw(10) << m[i].name
           << setw(10) << m[i].less.englishgrade << endl;
      BOOL = 1;
    } else if (a == " 3 ") {
      cout << setiosflags(ios::left) << setw(5) << setw(10) << m[i].name
           << setw(10) << m[i].less.mathgrade << endl;
      BOOL = 1;
    }
  }
  if (BOOL == 0) {
    cout << " ---There is no information you want to query! --- " << endl;
  }
}

void sort1() // 7.1. Sort by English score
{
  int j, i;
  char t1[20], t2[20];
  int t4, t5, t6;
  float t7;

  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if (m[j].less.englishgrade < m[j + 1].less.englishgrade) // bubble sort
      {
        strcpy(t1, m[j].name);
        strcpy(t2, m[j].clas);
        t4 = m[j].less.chinesegrade;
        t5 = m[j].less.englishgrade;
        t6 = m[j].less.mathgrade;
        t7 = m[j].num;

        strcpy(m[j].name, m[j + 1].name);
        strcpy(m[j].clas, m[j + 1].clas);
        m[j].less.chinesegrade = m[j + 1].less.chinesegrade;
        m[j].less.englishgrade = m[j + 1].less.englishgrade;
        m[j].less.mathgrade = m[j + 1].less.mathgrade;
        m[j].num = m[j + 1].num;

        strcpy(m[j + 1].name, t1);
        strcpy(m[j + 1].clas, t2);
        m[j + 1].less.chinesegrade = t4;
        m[j + 1].less.englishgrade = t5;
        m[j + 1].less.mathgrade = t6;
        m[j + 1].num = t7;
      }
    }
  }
  show();
  cout << " sort sucess! " << endl;
  cout << endl;
  sort();
}
