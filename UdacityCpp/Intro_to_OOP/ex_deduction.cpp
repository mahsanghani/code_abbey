//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename _Tf> bool func(_Tf x, _Tf y) { return (x < y); }

template <typename _Tf> void print(vector<_Tf> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}

int main() {
  std::vector<double> v = {9, 3, 2, 32.32, 10.323, 10.0003, 4.9789};
  std::vector<char> v2 = {'a', 'Z', 'M', 'x', 'Y', 'c', 'U'};

  print(v);

  sort(v.begin(), v.end(), func<double>);

  print(v);
  print(v2);

  sort(v2.begin(), v2.end(), func<char>);

  print(v2);
}