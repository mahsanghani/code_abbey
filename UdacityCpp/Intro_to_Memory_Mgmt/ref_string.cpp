//
// Created by Ahsan Ghani on 2022-10-15.
//
#import <iostream>
#import <string>

using namespace std;

void addSpaces(const char *&str) {
  char *temp = new char(sizeof(str) * 2);

  char *start = temp;

  while (*str != '\0') {
    *temp++ = *str++;
    *temp++ = ' ';
  }
  str = start;
}

int main() {
  string str = "Hello World";
  const char *ptr = str.c_str();
  cout << "string is: " << ptr << endl;
  addSpaces(ptr);

  cout << "string is: " << ptr << endl;
  return 0;
}