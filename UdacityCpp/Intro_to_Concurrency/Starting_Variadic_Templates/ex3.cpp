//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void printName(string &name,
               int wait_time) { // non-const reference, as a potential of a
                                // primary source for concurrency bugs
  this_thread::sleep_for(chrono::microseconds(wait_time));
  name += " (from Thread)";
  cout << name << endl;
}

int main() {
  string name("MyThread");
  thread t(printName, ref(name), 50);
  t.join();

  name += " (from Main)";
  cout << name << endl;

  return 0;
}