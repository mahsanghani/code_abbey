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

class Cat : public Animal {
private:
  double height_;

public:
  double getHeight() const;

  void setHeight(double height);
};

class Snake : public Animal {
private:
  double length_;

public:
  double getLength() const;

  void setLength(double length);

  void makeSound();
};

string Animal::getColor() const { return this->color_; }

string Animal::getName() const { return this->name_; }

int AnimaL::getAge() const { return this->age_; }

int main() {
  Cat c;
  c.setName("ketty");
  c.setAge(6);
  c.setColor("black");
  c.setHeight(6.5);

  Snake s;
  s.setName("krystal"); // LOL player in LPL, LoL
  s.setAge(20);
  s.setColor("yellow");
  s.setLength(164.0);

  std::cout << "The Cat c has infomation: (name, age, color, height): "
            << c.getName() << ", " << c.getAge() << ", " << c.getColor() << ", "
            << c.getHeight() << std::endl;

  std::cout << "The Snake s has infomation: (name, age, color, length): "
            << s.getName() << ", " << s.getAge() << ", " << s.getColor() << ", "
            << s.getLength() << std::endl;

  // A little colorful egg....
  s.makeSound();

  // Not possible... I'm sorry, ketty.
  // c.makeSound();
}