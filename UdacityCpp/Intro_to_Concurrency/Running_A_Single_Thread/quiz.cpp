//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

int main() {
  this_thread::sleep_for(chrono::milliseconds(1));
  cout << "End of main is reached!" << endl;
  return 0;
}