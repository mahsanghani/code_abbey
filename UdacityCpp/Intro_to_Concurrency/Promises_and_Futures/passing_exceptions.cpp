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

int main() {
  promise<double> prms;
  future<double> ftr = prms.get_future();

  double num = 42.0;
  double denom = 0.0;

  thread t(divideByNumber, move(prms), num, denom);

  try {
    double result = ftr.get();
    cout << "Result = " << result << endl;
  } catch (const exception &e) {
    cout << e.what() << endl;
  }

  t.join();

  return 0;
}