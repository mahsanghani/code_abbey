//
// Created by Ahsan Ghani on 2022-10-01.
//
#include <iostream>

using namespace std;

class ParentClass {

public:
  int var1;

protected:
  int var2;

private:
  int var3;
};

class ChildClass_1 : public ParentClass {};

class ChildClass_2 : protected ParentClass {};

class ChildClass_3 : private ParentClass {};
