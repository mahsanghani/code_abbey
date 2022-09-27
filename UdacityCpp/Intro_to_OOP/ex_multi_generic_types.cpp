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

template <typename _Tf_1, typename _Tf_2>
void scale(_Tf_1 num, _Tf_2 &container) {
  for (auto &i : container) {
    i *= num;
  }
}
