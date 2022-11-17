//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

void threadFunction() {
  this_thread::sleep_for(chrono::milliseconds(50));
  cout << "Finished work 1 in thread!" << endl;

  this_thread::sleep_for(chrono::milliseconds(50));
  cout << "Finished work 2 in thread!" << endl;
}