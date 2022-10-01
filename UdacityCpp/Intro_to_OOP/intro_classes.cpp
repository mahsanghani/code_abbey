//
// Created by Ahsan Ghani on 2022-10-01.
//
#include <iostream>

using namespace std;

class Date {
public:
  int day;
  int month;
  int year;

  void SetDate(int day, int month, int year);
};

void Date::SetDate(int day, int month, int year) {
  int day_numbers[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
    day_numbers[1]++;
  }

  if (year < 1 || day < 1 || month < 1 || month > 12 ||
      day > day_numbers[month - 1]) {
    throw domain_error("invalid date!");
  }

  Date::day = day;
  Date::month = month;
  Date::year = year;
}

int main() {
  Date date;
  date.SetDate(29, 2, 2020);
  cout << date.GetDay() << '/' << date.GetMonth() << '/' << date.GetYear()
       << endl;
}