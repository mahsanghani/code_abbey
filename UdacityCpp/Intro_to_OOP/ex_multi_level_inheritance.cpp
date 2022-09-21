//
// Created by Ahsan Ghani on 2022-09-21.
//
#include <iostream>

using namespace std;

class A {
private:
  int a_attr;

public:
  void SetA(int val_a);
  int GetA(void);
};

void A::SetA(int val_a) { A::a_attr = val_a; }

int A::GetA(void) { return A::a_attr; }

class B : public A {
private:
  int b_attr;

public:
  void SetAB(int val_a, int val_b);
  void PrintAB(void);
  int GetB(void);
};
