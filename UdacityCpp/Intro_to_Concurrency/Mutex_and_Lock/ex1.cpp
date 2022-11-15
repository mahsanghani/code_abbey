//
// Created by Ahsan Ghani on 2022-11-15.
//
#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

double result;

void printResult(int denom) {
  std::cout << "for denom = " << denom << ", the result is " << result
            << std::endl;
}

void divideByNumber(double num, double denom) {
  try {
    if (denom != 0) {
      result = num / denom;
      this_thread::sleep_for(chrono::milliseconds(1));
      printResult(denom);
    } else {
      throw invalid_argument("Exception from thread: Division by zero!");
    }
  } catch (const invalid_argument &e) {
    cout << e.what() << endl;
    return;
  }
}