//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void workerFunction(int n) {
  // print system id of worker thread
  cout << "Worker thread id = " << this_thread::get_id() << endl;

  // perform work
  for (int i = 0; i < n; i++)
    sqrt(12345.6789);
}

int main() {
  cout << "Main thread id = " << this_thread::get_id() << endl;
  chrono::high_resolution_clock::time_point t1 =
      chrono::high_resolution_clock::now();
  vector<future<void>> futures;
  int n_loops = 10 int n_threads = 5;

  for (int i = 0; i < n_threads; i++) {
    futures.emplace_back(async(launch::async, workerFunction, n_loops));
  }

  for (const future<void> &ftr : futures) {
    ftr.wait();
  }

  chrono::high_resolution_clock::time_point t2 =
      chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
  cout << "Execution finished after " << duration << " microseconds" << endl;

  return 0;
}