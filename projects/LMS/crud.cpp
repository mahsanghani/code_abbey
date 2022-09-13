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

void sort2() // 7.2. Sort by language score
{
  int j, i;
  char t1[20], t2[20];
  int t4, t5, t6;
  float t7;

  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if (m[j].less.chinesegrade <= m[j + 1].less.chinesegrade) // bubble sort
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

void sort3() // 7.3. Sort by math score
{
  int j, i;
  char t1[20], t2[20];
  float t4, t5, t6;
  float t7;

  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if (m[j].less.mathgrade <= m[j + 1].less.mathgrade) // bubble sort
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

void sort4() // 7.4. Sort by student number
{
  int j, i;
  char t1[20], t2[20];
  float t4, t5, t6;
  float t7;

  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if (m[j].num <= m[j + 1].num) // bubble sort
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

void sort5() // 7.5. Sort by total score from smallest to largest (bubble sort)
{
  int j, i;
  char t1[20], t2[20];
  int t4, t5, t6;
  float t7;

  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if ((m[j].less.chinesegrade + m[j].less.englishgrade +
           m[j].less.mathgrade) >=
          (m[j + 1].less.chinesegrade + m[j + 1].less.englishgrade +
           m[j + 1].less.mathgrade)) {
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

void sort6() // 7.6. Sort by total score from highest to lowest (bubble sort)
{
  int j, i;
  char t1[20], t2[20];
  int t4, t5, t6;
  float t7;

  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if ((m[j].less.chinesegrade + m[j].less.englishgrade +
           m[j].less.mathgrade) <=
          (m[j + 1].less.chinesegrade + m[j + 1].less.englishgrade +
           m[j + 1].less.mathgrade)) {
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

void sort() // 7. Student grades sorting tool
{
  cout << "  \n\n\n\n\n\n\n\t\t\tWelcome to   use the student grade ranking "
          "tool "
       << endl;
  cout << "                           ************************* " << endl;
  cout << "                           * 1. Sort by English score * " << endl;
  cout << "                           * 2. Sort by language score * " << endl;
  cout << "                           * 3. Sort by math score * " << endl;
  cout << "                           * 4. Sort by student number * " << endl;
  cout << "                           * 5. Sort by total score from smallest "
          "to largest * "
       << endl;
  cout << "                           * 6. Sort by total score from highest to "
          "lowest * "
       << endl;
  cout << "                           * 7. Exit the program * " << endl;
  cout << "                           ************************* " << endl;
  cout << "                           * Enter " 0 -
              7 " to enter the corresponding function * "
       << endl;
  int r;
  cin >> r;
  switch (r) {
  case 1:
    sort1();
    break;

  case 2:
    sort2();
    break;

  case 3:
    sort3();
    break;

  case 4:
    sort4();
    break;

  case 5:
    sort5();
    break;

  case 6:
    sort6();
    break;

  case 7:
    cout << " ---Exit to the home page --- " << endl;
    return;

    break;

  default:
    error();
  }
}

void statistics() // 8. Student information statistics tool, calculate the
                  // highest score, lowest score, average score, variance
{
  system(" cls "); // System clear screen

  /* ---Define various information--- */

  float sumc = 0, sume = 0, summ = 0;
  static float sum = 0;
  static float average = 0;
  static float fangcha = 0;
  char max_class[20], max_name[20], min_class[20], min_name[20];
  int i, j, c = 0;
  float count1 = 0, count2 = 0, count3 = 0;
  float maxc = m[0].less.chinesegrade, // Maximum language
      minc = m[0].less.chinesegrade,   // Minimum language
      pc,
        maxe = m[0].less.englishgrade, // English maximum
      mine = m[0].less.englishgrade,   // English minimum
      pe,
        maxm = m[0].less.mathgrade, // Maximum value
      minm = m[0].less.mathgrade,   // mathematical minimum
      pm,
        max_score = maxc + maxe + maxm, // Maximum total score
      min_score = minc + mine + minm,   // Minimum total score
      max_chinesegrade = 0, max_englishgrade = 0, max_mathgrade = 0, max_num,
        min_chinesegrade = 0, min_englishgrade = 0, min_mathgrade = 0, min_num;

  /* ---Calculate student scores--- */

  for (i = 1; i < e; i++) // Maximum, minimum, maximum total score, minimum
                          // total score student score
  {
    if (minc > m[i].less.chinesegrade) {
      minc = m[i].less.chinesegrade;
    }
    if (maxc < m[i].less.chinesegrade) {
      maxc = m[i].less.chinesegrade;
    }
    if (mine > m[i].less.englishgrade) {
      mine = m[i].less.englishgrade;
    }
    if (maxe < m[i].less.englishgrade) {
      maxe = m[i].less.englishgrade;
    }
    if (minm > m[i].less.mathgrade) {
      minm = m[i].less.mathgrade;
    }
    if (maxm < m[i].less.mathgrade) {
      maxm = m[i].less.mathgrade;
    }

    /* ---Calculate the maximum value--- */

    if (max_score < (m[i].less.chinesegrade + m[i].less.englishgrade +
                     m[i].less.mathgrade)) {
      max_score =
          m[i].less.chinesegrade + m[i].less.englishgrade + m[i].less.mathgrade;
      max_num = m[i].num;
      strcpy(max_name, m[i].name);
      strcpy(max_class, m[i].clas);
      max_chinesegrade = m[i].less.chinesegrade;
      max_englishgrade = m[i].less.englishgrade;
      max_mathgrade = m[i].less.mathgrade;
    }

    /* ---Calculate the minimum value--- */

    if (min_score > (m[i].less.chinesegrade + m[i].less.englishgrade +
                     m[i].less.mathgrade)) {
      min_score =
          m[i].less.chinesegrade + m[i].less.englishgrade + m[i].less.mathgrade;
      min_num = m[i].num;
      strcpy(min_name, m[i].name);
      strcpy(min_class, m[i].clas);
      min_chinesegrade = m[i].less.chinesegrade;
      min_englishgrade = m[i].less.englishgrade;
      min_mathgrade = m[i].less.mathgrade;
    }
  }

  /* ---Calculate the pass rate--- */

  for (j = 0; j < e; j++) {
    sumc = sumc + m[j].less.chinesegrade;
    if (m[j].less.chinesegrade >= 60) {
      ++count1;
    } // Language score
    sume = sume + m[j].less.englishgrade;
    if (m[j].less.englishgrade >= 60) {
      ++count2;
    } // English score
    summ = summ + m[j].less.mathgrade;
    if (m[j].less.mathgrade >= 60) {
      ++count3;
    } // Math score
  }
  pc = count1; // The Chinese score is assigned to pc
  pe = count2; // The English score is assigned to pe
  pm = count3; // The mathematics score is assigned to pm

  /* ---Display prompt--- */

  cout << " 1. Calculate the total score, average score, and variance of a "
          "student "
       << endl;
  cout << " 2. Calculate the total grade information of the whole class "
       << endl;

  /* ---Read input--- */

  int k;
  cin >> k;   // Enter a k
  if (k == 1) // Display the total score and average score of a student
  {
    cout << " Please enter student ID: " << endl;
    int t;
    cin >> t;
    for (i = 0; i < e; i++) {
      if (t == m[i].num) {
        sum = m[i].less.chinesegrade + m[i].less.englishgrade +
              m[i].less.mathgrade;
        average = sum / 3;
        fangcha = ((m[i].less.chinesegrade - average) *
                       (m[i].less.chinesegrade - average) +
                   (m[i].less.englishgrade - average) *
                       (m[i].less.englishgrade - average) +
                   (m[i].less.mathgrade - average) *
                       (m[i].less.mathgrade - average)) /
                  3;
        cout << " Name: " << m[i].name << "      Total score: " << sum
             << "      Average score: " << average
             << "      Variance: " << fangcha << endl;
        c++;
      }
    }
    if (c == 0) {
      error();
    }
  } else // The lowest and highest average pass rate of each subject
  {
    cout << " 1. Chinese Achievement " << endl;
    cout << " 2. English results " << endl;
    cout << " 3. Mathematics Achievement " << endl;
    cout << " 4. Class results " << endl;
    cout << " 5. Return      " << endl;
    cout << " Please enter the serial number: " << endl;
    int r;
    cin >> r;
    switch (r) {
    case 1:
      cout << " Highest score in Chinese:   " << maxc << endl;
      cout << "The lowest score in Chinese:   " << minc << endl;
      cout << "The average score of the whole Chinese class:   " << sumc / e
           << endl;
      cout << " Language passing rate:   " << pc / e << endl;
      break;

    case 2:
      cout << " Highest score in English:   " << maxe << endl;
      cout << "The lowest score in English:   " << mine << endl;
      cout << " English class average score:   " << sume / e << endl;
      cout << " English passing rate: " << pe / e << endl;
      break;

    case 3:
      cout << " Highest score in mathematics:   " << maxm << endl;
      cout << " Minimum score in mathematics:   " << minm << endl;
      cout << "The average score of the whole mathematics class:   " << summ / e
           << endl;
      cout << " Mathematics passing rate:   " << pm / e << endl;
      break;

    case 4:
      cout << " Highest score in the class:   " << max_score << endl;
      cout << " His information is:   " << endl;
      cout << setiosflags(ios::left) << setw(2) << " student number "
           << "    " << setw(10) << " Name " << setw(10) << " Class "
           << setw(10) << " Language " << setw(10) << " English " << setw(10)
           << " Mathematics " << endl;
      cout << setiosflags(ios::left) << setw(5) << max_num << "   " << setw(10)
           << max_name << setw(10) << max_class << setw(10) << max_chinesegrade
           << setw(10) << max_englishgrade << setw(10) << max_mathgrade << endl;
      cout << "The lowest score of the whole class:   " << min_score << endl;
      cout << " His information is:   " << endl;
      cout << setiosflags(ios::left) << setw(2) << " student number "
           << "    " << setw(10) << " Name " << setw(10) << " Class "
           << setw(10) << " Language " << setw(10) << " English " << setw(10)
           << " Mathematics " << endl;
      cout << setiosflags(ios::left) << setw(5) << min_num << "   " << setw(10)
           << min_name << setw(10) << min_class << setw(10) << min_chinesegrade
           << setw(10) << min_englishgrade << setw(10) << min_mathgrade << endl;
      break;

    case 5:
      cout << " ---Return--- " << endl;
      return;

      break;

    default:
      error();
      break;
    }
  }
}
void save() // 9. Write student information to file
{
  int i;
  ofstream outfile(" Student.dat ", ios::out);

  if (!outfile) {
    cerr << " open Student.dat error! " << endl;
    exit(1);
  }
  outfile << e << endl;
  for (i = 0; i < e; i++) {
    outfile << m[i].num << '  ';
    outfile << m[i].name << '  ';
    outfile << m[i].clas << '  ';
    outfile << m[i].less.chinesegrade << '  ';
    outfile << m[i].less.englishgrade << '  ';
    outfile << m[i].less.mathgrade << '  ';
    outfile << m[i].sum << '  ';
    outfile << m[i].average << '  ';
    outfile << endl;
  }
  outfile.close();
  cout << endl;
  cout << " ---Data has been successfully saved --- " << endl;
}

void load() // Load interface load
{
  system(" cls ");
  cout << setiosflags(ios::left) << setw(2) << " student number "
       << "    " << setw(10) << " Name " << setw(10) << " Class " << setw(10)
       << " Language " << setw(10) << " English " << setw(10) << " Mathematics "
       << endl;
  ifstream infile(" Student.dat ", ios::in);
  //     if(!infile)
  // 	{
  // 			cerr<<"open Student.dat error!"<<endl;
  // 			exit(1);
  // 	}
  infile >> e;
  for (int i = 0; i < e; i++) {
    infile >> m[i].num;
    infile >> m[i].name;
    infile >> m[i].clas;
    infile >> m[i].less.chinesegrade;
    infile >> m[i].less.englishgrade;
    infile >> m[i].less.mathgrade;
    infile >> m[i].sum;
    infile >> m[i].average;
  }
}

int main() // Main interface main
{
  system(" cls ");
  system(" color F1 ");
  welcome(); // Call the welcome interface
  load();    // Call the loading interface
  for (;;) {
    // system("cls"); //Clear the screen
    cout << "  \n\n\n\n\n\n\n\t\t\t    "
         << " ************************* " << endl;
    cout << "                           | Welcome to the student achievement "
            "management system | "
         << endl;
    cout << "                           |************************| " << endl;
    cout << "                           | Basic functions | " << endl;
    cout << "                           | 1. View student achievement "
            "information | "
         << endl;
    cout << "                           | 2. Enter student achievement "
            "information | "
         << endl;
    cout << "                           | 3. Delete student achievement "
            "information | "
         << endl;
    cout << "                           | 4. Student ID information query "
            "results | "
         << endl;
    cout << "                           | 5. Name information query results | "
         << endl;
    cout
        << "                           | 6. Course information query results | "
        << endl;
    cout << "                           | | " << endl;
    cout << "                           | Other tools | " << endl;
    cout << "                           | 7. Student grades sorting tool | "
         << endl;
    cout << "                           | 8. Student performance statistics "
            "tool | "
         << endl;
    cout << "                           | 9. Write student scores to file | "
         << endl;
    cout << "                           | | " << endl;
    cout << "                           | End operation | " << endl;
    cout << "                           | 0. Exit the student management "
            "system | "
         << endl;
    cout << "                           |************************| " << endl;
    cout << "                            Enter " 0 -
                9 " to enter the corresponding function "
         << endl;
    int n;
    cin >> n;
    if ((n >= 0) && (n <= 9)) // Enter different functions
    {
      switch (n) {
      case 1:
        show();
        break; // Browse student information

      case 2:
        input();
        save();
        break; // Enter student information

      case 3:
        delate();
        break; // Delete student information

      case 4:
        numsearch();
        break; // Student ID query

      case 5:
        namesearch();
        break; // Name query

      case 6:
        lesssearch();
        break; // course query

      case 7:
        sort();
        break; // sort

      case 8:
        statistics();
        break; // Statistics

      case 9:
        save();
        break; // write to file

      case 0:
        cout << " Welcome to use " << endl;
        exit(0); // Exit

      default:
        break;
      }
      cout << endl;
    }
  }
}