//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <iostream>
#include <string>

class Animal {
public:
  double weight;
  double size;
};

class Pet {
public:
  string name;
  string owner;
};

class Dog : public Animal, public Pet {
public:
  bool has_long_fur;
  bool has_short_fur;
};

class Cat : public Animal, Pet {
public:
  string eye_color_;
  int age_;
};

int main() {
  Dog d;
  d.has_long_fur = true;
  d.weight = 10;
  d.size = 43;
  d.owner = "me";
  cout << d.has_long_fur << endl;
  cout << d.owner << endl;

  Cat c;
  c.eye_color_ = "red";
  c.age_ = 4;
  cout << c.eye_color_ << endl;
  cout << c.age_ << endl;
}
