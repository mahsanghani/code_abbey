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

void B::SetAB(int val_a, int val_b) {
  B::SetA(val_a);
  b_attr = val_b;
}

void B::PrintAB() { cout << B::GetA() << B::b_attr << endl; }

int B::GetB() { return B::b_attr; }

class C : public B {
private:
  int c_attr;

public:
  void SetABC(int val_a, int val_b, int val_c);
  void PrintABC(void);
};

void C::SetABC(int val_a, int val_b, int val_c) {
  // multilevel inheritance

  C::SetAB(val_a, val_b);
  C::c_attr = val_c;
}

void C::PrintABC() { cout << C::c_attr << C::GetB() << C::GetA() << endl; }
