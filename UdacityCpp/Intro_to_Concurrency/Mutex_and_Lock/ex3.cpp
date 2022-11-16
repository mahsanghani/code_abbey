//
// Created by Ahsan Ghani on 2022-11-15.
//
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mutex_1;
mutex mutex_2;
mutex mutex_3;

void ThreadA() {
  mutex_2.lock();
  cout << "Thread A" << endl;
  mutex_1.lock();
  mutex_2.unlock();
  mutex_1.unlock();
}