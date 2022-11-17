//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

using namespace std;

int main() {
  vector<thread> threads;

  for (size_t i = 0; i < 10; i++) {
    threads.emplace_back([i]() {
      this_thread::sleep_for(chrono::milliseconds(10 * i));
      cout << "Hello from the Worker thread # " << i << endl;
    });
  }

  cout << "Hello from the Main thread!" << endl;

  for (auto &t : threads) {
    t.join();
  }

  return 0;
}