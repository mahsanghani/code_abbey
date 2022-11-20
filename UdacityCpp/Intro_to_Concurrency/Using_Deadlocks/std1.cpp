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

void ThreadB() {
  lock_guard<mutex> lock_1(mutex_1);
  cout << "Thread B" << endl;
  lock_guard<mutex> lock_2(mutex_2);
}

void ExecuteThreads() {
  thread t1(ThreadA);
  thread t2(ThreadB);

  t1.join();
  t2.join();

  cout << "Finished" << endl;
}