//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

void threadFunctionEven() {
  this_thread::sleep_for(chrono::milliseconds(1));
  cout << "Even thread!" << endl;
}

int main() {

  for (int i = 0; i < 6; i++) {
    if (i % 2 == 0) {
      thread t(threadFunctionEven);
      t.detach();
    } else {
      thread t(threadFunctionOdd);
      t.detach();
    }
  }

  this_thread::sleep_for(chrono::milliseconds(1));
  cout << "End of main is reached!" << endl;
  return 0;
}