//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <iostream>

using namespace std;

class Abstraction {
private:
  static int counter;

  int number;
  char character;

  void ProcessAttributes(void);

public:
  Abstraction() { counter++; }

  void SetMyValues(int n, char c);
  void GetMyValues(void);
  int GetCounter(void);
};