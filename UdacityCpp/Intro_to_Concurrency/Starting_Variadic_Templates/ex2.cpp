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