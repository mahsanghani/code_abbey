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

private:
  mutex mutex_;
  condition_variable cond_;
  deque<T> messages_;
};

int main() {
  shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);
  cout << "Spawning Threads..." << endl;
  vector<future<void>> futures;

  for (int i = 0; i < 10; i++) {
    int messages = i;
    futures.emplace_back(
        async(launch::async, &MessageQueue<int>::send, queue, move(message)));
  }

  cout << "Collecting Results..." << endl;

  while (true) {
    int message = queue->receive();
    cout << " Message #" << message << " has been removed from the queue"
         << endl;
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); });

  cout << "Finished!" << endl;

  return 0;
}