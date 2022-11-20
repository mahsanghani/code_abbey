//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mutex_1;
mutex mutex_2;

void ThreadA() {
  lock_guard<mutex> lock_2(mutex_2);
  cout << "Thread A" << endl;
  lock_guard<mutex> lock_1(mutex_1);
}
