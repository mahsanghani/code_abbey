//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>

using namespace std;

class Date {
private:
  int day;
  int month;
  int year;
  string month_name;

public:
  void SetDate(int day, int month, int year);
  int GetDay();
  int GetMonth();
  int GetYear();
  string GetMonthName();
  string PrintDate(int day, string month_name, int year);
  string PrintDate(int day, int month, int year);
};

void Date::SetDate(int day, int month, int year) {}