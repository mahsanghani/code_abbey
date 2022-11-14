//
// Created by Ahsan Ghani on 2022-11-13.
//
#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

template <class T> class MessageQueue {
public:
  T receive() {
    unique_lock<mutex> u_lock(mutex_);
    cond_.wait(u_lock, [this] { return !messages_.empty(); });
    T msg = move(messages_.back());
    messages_.pop_back();
    return msg;
  }

  void send(T &&msg) {
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> u_lock(mutex_);
    cout << " Message #" << msg << " has been sent to the queue" << endl;
    messages_.push_back(move(msg));
  }
};