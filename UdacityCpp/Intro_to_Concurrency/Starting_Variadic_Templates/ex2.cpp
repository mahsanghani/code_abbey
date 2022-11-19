//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void printName(string name, int wait_time) {
  this_thread::sleep_for(chrono::milliseconds(wait_time));
  cout << "Name (from Thread) = " << name << endl;
}

int main() {
  string name_1 = "MyThread1";
  string name_2 = "MyThread2";

  thread t1(printName, name_1, 50);
  thread t2(printName, move(name_2), 100);

  t1.join();
  t2.join();

  cout << "Name (from Main) = " << name_1 << endl;
  cout << "Name (from Main) = " << name_2 << endl;

  return 0;
}