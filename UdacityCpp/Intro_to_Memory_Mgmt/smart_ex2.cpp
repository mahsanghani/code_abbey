//
// Created by Ahsan Ghani on 2022-10-15.
//
#include <iostream>
#include <memory>

using namespace std;

class A {
public:
  void classAMethod() { cout << "A::classAMethod()" << endl; }
};

int main() {
  shared_ptr<A> p1(new A);
  cout << p1.get() << endl;

  shared_ptr<A> p2(p1);
  cout << p1.get() << endl;
  cout << p2.get() << endl;

  cout << p1.use_count() << endl;
  cout << p2.use_count() << endl;

  p1.reset();
  cout << "p1 after reset: " << p1.get() << endl; // p1 becomes NULL
  cout << p2.use_count() << endl;
  cout << p2.get() << endl;

  return 0;
}