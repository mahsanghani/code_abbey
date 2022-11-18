//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

void threadFunction() {
  this_thread::sleep_for(chrono::microseconds(50)); // simulate work
  cout << "Finish work in thread\n";
}

int main() {
  thread t(threadFunction);
  t.detach();
  this_thread::sleep_for(chrono::milliseconds(50));
  cout << "Finished work in main!" << endl;
  return 0;
}
