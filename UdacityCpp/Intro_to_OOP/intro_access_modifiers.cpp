//
// Created by Ahsan Ghani on 2022-10-01.
//
#include <iostream>

class Date {
private:
  int day;
  int month;
  int year;

public:
  void SetDate(int day, int month, int year);
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;
};
