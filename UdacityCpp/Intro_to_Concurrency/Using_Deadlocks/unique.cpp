//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

mutex mtx;
double result;

void printResult(int denom) {
  cout << "for denom = " << denom << ", the result is " << result << endl;
}

int main() {
  vector<future<void>> futures;
  for (double i = -5; i <= +5; ++i) {
    futures.emplace_back(async(launch::async, divideByNumber, 50.0, i));
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); });

  return 0;
}