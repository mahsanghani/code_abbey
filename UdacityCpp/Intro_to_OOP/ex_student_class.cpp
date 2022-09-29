//
// Created by Ahsan Ghani on 2022-09-28.
//
#include <iostream>

using namespace std;

class Student {
private:
  string name_;
  int grade_;
  double gpa_;

public:
  Student(string name, int grade, double gpa);
  Student();

  string getName() const;
  int getGrade() const;
  double getGPA() const;

  void setName(string name);
  void setGrade(int grade);
  void setGPA(double gpa);
};

Student::Student(std::string name, int grade, double gpa) {
  if (grade < 0 || gpa > 4.0 || gpa < 0.0) {
    throw "n/a";
  }
  this->name_ = name;
  this->grade_ = grade;
  this->gpa_ = gpa;
}

Student::Student() {}

string Student::getName() const { return this->name_; }

int Student::getGrade() const { return this->grade_; }

double Student::getGPA() const { return this->gpa_; }