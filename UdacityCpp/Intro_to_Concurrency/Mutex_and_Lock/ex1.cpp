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
  cout << "for denom = " << denom << ", the result is " << result << endl;
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

int main() {
  vector<future<void>> futures;
  for (double i = -5; i <= +5; i++) {
    futures.emplace_back(async(launch::async, divideByNumber, 50.0, i));
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); });
  return 0;
}