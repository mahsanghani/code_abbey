//
// Created by Ahsan Ghani on 2022-09-21.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename _Tf> void print(vector<_Tf> v) {
  for (_Tf i : v) {
    cout << i << endl;
  }
}
