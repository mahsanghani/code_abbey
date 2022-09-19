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

void Date::SetDate(int day, int month, int year) {
  int day_numbers[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string month_names[]{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
    day_numbers[1]++;
  }

  if (year < 1 || day < 1 || month < 1 || month > 12 ||
      day > day_numbers[month - 1]) {
    throw std::domain_error("Invalid date!");
  }

  Date::day = day;
  Date::month = month;
  Date::year = year;
  Date::month_name = month_names[month - 1];
}

int Date::GetDay() { return day; }

int Date::GetMonth() { return month; }

string Date::GetMonthName() { return month_name; }

int Date::GetYear() { return year; }

string Date::PrintDate(int day, int month, int year) {
  string result =
      to_string(day) + "/" + to_string(month) + "/" + to_string(year);
  cout << "Using int month version!" << endl;
  return result;
}

string Date::PrintDate(int day, std::string month_name, int year) {
  string result = month_name + " " + to_string(day) + ", " + to_string(year);
  cout << "Using string month_name version!" << endl;
  return result;
}
