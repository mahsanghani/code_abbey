//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
  string color_;
  string name_;
  int age_;

public:
  string getColor() const;
  string getName() const;
  int getAge() const;

  void setColor(string color);
  void setName(string name);
  void setAge(int age);
};