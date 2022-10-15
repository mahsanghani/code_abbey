//
// Created by Ahsan Ghani on 2022-10-15.
//
#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
  void classMethod() { cout << "MyClass::classMethod()" << endl; }
};

int main() {
  unique_ptr<MyClass> ptr_1(new MyClass);
  ptr_1->classMethod();

  cout << ptr_1.get() << endl;

  unique_ptr<MyClass> ptr_2 = std::move(ptr_1); // needs to use std::move()
  ptr_2->classMethod();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;

  unique_ptr<MyClass> ptr_3 = std::move(ptr_2);
  ptr_3->classMethod();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;
  cout << ptr_3.get() << endl;

  return 0;
}