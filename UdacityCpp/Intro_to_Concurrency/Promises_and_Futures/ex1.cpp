//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

void printMessage(string message) {
  this_thread::sleep_for(chrono::milliseconds(10)); // simulate work
  cout << "Thread 1: " << message << endl;
}

int main() {
  string message = "My message";
  thread t1(printMessage, message);

  thread t2([message] {
    this_thread::sleep_for(chrono::milliseconds(10));
    cout << "Thread 2: " << message << endl;
  });

  t1.join();
  t2.join();
  return 0;
}