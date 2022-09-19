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

int Animal::getAge() const { return this->age_; }

void Animal::setColor(string color) { this->color_ = color; }

void Animal::setName(string name) { this->name_ = name; }

void Animal::setAge(int age) { this->age_ = age; }

double Cat::getHeight() const { return this->height_; }

void Cat::setHeight(double height) { this->height_ = height; }

double Snake::getLength() const { return this->length_; }

void Snake::setLength(double length) { this->length_ = length; }

void Snake::makeSound() { cout << "Hiss-" << endl; }

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