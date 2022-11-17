//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void modifyMessage(promise<string> &&promises, string message) {
  this_thread::sleep_for(chrono::milliseconds(4000)); // simulate work
  string modifiedMessage = message + " has been modified";
  promises.set_value(modifiedMessage);
}

int main() {
  string messageToThread = "My Message";

  promise<string> prms;
  future<string> ftr = prms.get_future();

  thread t(modifyMessage, move(prms), messageToThread);

  cout << "Original message from main(): " << messageToThread << endl;
  string messageToThread = ftr.get();
  cout << "Modified message from thread(): " << messageToThread << endl;

  t.join();
  return 0;
}