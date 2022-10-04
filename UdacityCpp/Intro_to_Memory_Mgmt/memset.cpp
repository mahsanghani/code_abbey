//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char *ptr = new char('C');
  char str[4] = "AAA";
  char str2[4] = "AAA";

  cout << *ptr << endl;
  cout << str << endl;
  cout << str2 << endl;

  memset(ptr, 'A', 1);
  memset(str + 1, 'B', 1);
  memset(str2 + 1, 'B', 2);

  cout << *ptr << endl;
  cout << str << endl;
  cout << str2 << endl;

  delete ptr;

  return 0;
}