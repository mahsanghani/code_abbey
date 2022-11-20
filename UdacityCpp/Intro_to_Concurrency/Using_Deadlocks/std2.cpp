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
  lock(mutex_1, mutex_2);
  lock_guard<mutex> lock_2(mutex_2, adopt_lock);
  cout << "Thread A" << endl;
  lock_guard<mutex> lock_1(mutex_1, adopt_lock);
}

void ThreadB() {
  lock_guard<mutex> lock_1(mutex_1, adopt_lock);
  cout << "Thread B" << endl;
  lock_guard<mutex> lock_2(mutex_2, adopt_lock);
}

void ExecuteThreads() {
  thread t1(ThreadA);
  thread t2(ThreadB);

  t1.join();
  t2.join();

  cout << "Finished" << endl;
}