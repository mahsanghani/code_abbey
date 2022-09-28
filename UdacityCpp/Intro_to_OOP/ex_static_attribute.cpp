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

int Abstraction::counter = 0;

void Abstraction::ProcessAttributes() {
  Abstraction::number *= 6;
  Abstraction::character++;
}

void Abstraction::SetMyValues(int n, char c) {
  Abstraction::number = n;
  Abstraction::character = c;
}

int Abstraction::GetCounter() { return Abstraction::counter; }

int main() {
  Abstraction abstract;
  abstract.SetMyValues(100, 'x');
  abstract.GetMyValues();
  cout << abstract.GetCounter() << endl;

  Abstraction abstract2;
  abstract2.SetMyValues(10, 'a');
  abstract.GetMyValues();
  cout << abstract2.GetCounter() << endl;
}