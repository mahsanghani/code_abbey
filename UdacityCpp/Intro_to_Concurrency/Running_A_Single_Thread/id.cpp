//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

int main() {
  cout << "Hello concurrent world from main! Thread id = "
       << this_thread::get_id() << endl;

  return 0;
}
