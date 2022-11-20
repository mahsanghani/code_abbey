//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <cmath>
#include <future>
#include <iostream>
#include <memory>
#include <thread>

using namespace std;

double divideNumber(double num, double denom) {
  cout << "Worker thread id = " << this_thread::get_id() << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  if (denom == 0) {
    throw runtime_error("Exception from thread#: Division by zero!");
  }
  return num / denom;
}