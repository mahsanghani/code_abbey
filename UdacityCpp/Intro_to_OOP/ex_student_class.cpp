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

void Student::setName(std::string name) {
  if (name.length() <= 0) {
    throw "n/a";
  }
  this->name_ = name;
}

void Student::setGrade(int grade) {
  if (grade < 0) {
    throw "n/a";
  }
  this->grade_ = grade;
}

void Student::setGPA(double gpa) {
  if (gpa > 4.0 || gpa < 0.0) {
    throw "n/a";
  }
  this->gpa_ = gpa;
}

int main() {
  try {
    Student s1("jacky chan", 8, -1.0);
  } catch (const char *msg) {
    cerr << msg << endl;
  }

  Student s2;

  try {
    s2.setName("bruce lee");
  } catch (const char *msg) {
    cerr << msg << endl;
  }

  try {
    s2.setGrade(-2);
  } catch (const char *msg) {
    cerr << msg << endl;
  }

  try {
    s2.setGPA(4.3);
  } catch (const char *msg) {
    cerr << msg << endl;
  }

  cout << s1.getName() << endl;
  cout << s2.getName() << endl;

  return 0;
}