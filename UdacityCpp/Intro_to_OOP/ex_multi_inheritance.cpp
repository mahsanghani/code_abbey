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