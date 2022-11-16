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
  mutex_1.lock();
  cout << "Thread A" << endl;
  mutex_2.lock();
  mutex_2.unlock();
  mutex_1.unlock();
}

void ThreadB() {
  mutex_1.lock();
  cout << "Thread B" << endl;
  mutex_2.lock();
  mutex_1.unlock();
  mutex_2.unlock();
}

void ExecuteThreads() {
  thread t1(ThreadA);
  thread t2(ThreadB);

  t1.join();
  t2.join();

  cout << "Finished!" << endl;
}