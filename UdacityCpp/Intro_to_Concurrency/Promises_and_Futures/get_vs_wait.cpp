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

int main() {
  double input_data = 42.0;

  promise<double> prms;
  future<double> ftr = prms.get_future();

  thread t(computeSqrt, move(prms), input_data);

  auto status = ftr.wait_for(chrono::milliseconds(1000));

  if (status == future_status::ready) {
    cout << "Result = " << ftr.get() << endl;
  } else if (status == future_status::timeout ||
             status == future_status::deferred) {
    cout << "Result unavailable" << endl;
  }

  t.join();

  return 0;
}