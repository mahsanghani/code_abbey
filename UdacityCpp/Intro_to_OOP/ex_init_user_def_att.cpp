//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <iostream>
#include <string>

using namespace std;

class A {
public:
  A(int a, double b, char c) : attr1(a), attr2(b), attr3(c) {
    std::cout << "A constructor" << endl;
  }
  void print() const {
    std::cout << "A: " << attr1 << " " << attr2 << " " << attr3 << endl;
  }

private:
  int attr1;
  double attr2;
  char attr3;
};

class B {
public:
  B(int num, int a, double b, char c)
      : number(num),
        attr(a, b, c) // In the initialization list,
                      // call the constructor of user defined attribute A
  {
    std::cout << "B constructor" << endl;
  }
  void print() const {
    std::cout << "B: " << number << " " << endl;
    attr.print();
  }

private:
  int number;
  A attr;
};

int main() {
  B obj(23, 2, 2.3, 'X');
  obj.print();
  return 0;
}