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
