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