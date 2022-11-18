//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void printHello() {
  cout << "Hello from the Worker thread #" << this_thread::get_id();
}

int main() {
  vector<thread> threads;

  for (size_t i = 0; i < 5; i++) {
    threads.emplace_back(thread(printHello));
  }

  cout << "Hello from Main thread #" << this_thread::get_id() << endl;

  for (auto &t : threads) {
    t.join();
  }

  return 0;
}