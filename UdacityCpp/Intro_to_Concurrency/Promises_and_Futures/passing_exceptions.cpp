//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <cmath>
#include <future>
#include <iostream>
#include <memory>
#include <thread>

using namespace std;

void divideByNumber(promise<double> &&promise, double num, double denom) {
  this_thread::sleep_for(chrono::microseconds(500));
  try {
    if (denom == 0) {
      throw runtime_error("Exception from thread: Division by zero!");
    } else {
      promise.set_value(num / denom);
    }
  } catch (...) {
    promise.set_exceptions(current_exception());
  }
}