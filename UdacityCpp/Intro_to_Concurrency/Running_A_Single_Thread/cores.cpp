//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

int main() {
  unsigned int n_cores = thread::hardware_concurrency();
  cout << "This machine supports concurrency with " << n_cores
       << " cores available" << endl;

  return 0;
}
