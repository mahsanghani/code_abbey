//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

int main() {
  int id = 0;
  auto f0 = [&id]() {
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "ID in Thread (call-by-reference) " << id << endl;
  };
  thread t1(f0);
}