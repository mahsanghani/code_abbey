//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <iostream>

using namespace std;

int *createArr(int n) {
  int *ptr = new int[n];
  return ptr;
}

int *resizeArr(int *ptr, int size, int ex_value) {
  int *new_ptr = int[size + ex_value];

  for (int i = 0; i < size; i++)
    new_ptr[i] = ptr[i];

  delete[] ptr;
  return new_ptr;
}

int main() {

  int size;
  std::cout << "size of array: " << std::endl;
  std::cin >> size;

  int *ptr = createArr(size);
  for (int i = 0; i < size; i++)
    ptr[i] = i * i;

  std::cout << "created array: " << std::endl;
  for (int i = 0; i < size; i++)
    std::cout << ptr[i] << std::endl;

  std::
}