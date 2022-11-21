//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <cmath>
#include <future>
#include <iostream>
#include <memory>
#include <thread>

using namespace std;

double divideByNumber(double num, double denom) {
  this_thread::sleep_for(chrono::microseconds(500));
  if (denom == 0) {
    throw runtime_error("Exception from thread: Division by zero!");
  }
  return num / denom;
}

int main() {
  double num = 42.0;
  double denom = 0.0;

  future<double> ftr = async(divideByNumber, num, denom);

  try {
    double result = ftr.get();
    cout << "Result = " << result << endl;
  } catch (const exception &e) {
    cout << e.what() << endl;
  }

  return 0;
}