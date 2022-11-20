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
