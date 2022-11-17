//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <cmath>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void computeSqrt(promise<double> &&promises, double input) {
  this_thread::sleep_for(chrono::milliseconds(2000));
  double output = sqrt(input);
  promises.set_value(output);
}