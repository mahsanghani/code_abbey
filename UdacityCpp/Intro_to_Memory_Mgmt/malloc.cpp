//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int *ptr = NULL;

  ptr = new (nothrow) int;

  ptr = static_cast<int *>(malloc(4 * sizeof(int)));
  for (int i = 0; i < 4; i++) {
    cout << &ptr[i] << ptr[i] << endl;
  }

  for (int i = 0; i < 4; i++) {
    memset(&ptr[i], ('A' + i), sizeof(int));
  }

  for (int i = 0; i < 4; i++) {
    cout << &ptr[i] << ptr[i] << endl;
  }

  return 0;
}
