//
// Created by Ahsan Ghani on 2022-10-26.
//
class OutOfRangeExc {};

template <class T> class Iter {
  T *ptr;
  T *end;
  T *begin;
  unsigned length;

public:
  Iter() {
    ptr = end = begin = NULL;
    length = 0;
  }
  Iter(T *p, T *first, T *last) {
    ptr = p;
    end = last;
    begin = first;
    length = last - first;
  }
  unsigned size() { return length; }
  T &operator*() {
    if ((ptr >= end) || (ptr < begin))
      throw OutOfRangeExc();
    return *ptr;
  }
  T *operator->() {
    if ((ptr >= end) || (ptr < begin))
      throw OutOfRangeExc();
    return ptr;
  }
  Iter operator++() {
    ptr++;
    return *this;
  }
  Iter operator--() {
    ptr--;
    return *this;
  }
  Iter operator++(int notused) {
    T *tmp = ptr;
    ptr++;
    return Iter<T>(tmp, begin, end);
  }
  Iter operator--(int notused) {
    T *tmp = ptr;
    ptr--;
    return Iter<T>(tmp, begin, end);
  }
  T &operator[](int i) {
    if ((i < 0) || (i >= (end - begin)))
      throw OutOfRangeExc();
    return ptr[i];
  }
  bool operator==(Iter op2) { return ptr == op2.ptr; }
  bool operator!=(Iter op2) { return ptr != op2.ptr; }
  bool operator<(Iter op2) { return ptr < op2.ptr; }
  bool operator<=(Iter op2) { return ptr <= op2.ptr; }
  bool operator>(Iter op2) { return ptr > op2.ptr; }
  bool operator>=(Iter op2) { return ptr >= op2.ptr; }
  Iter operator-(int n) {
    ptr -= n;
    return *this;
  }
  Iter operator+(int n) {
    ptr += n;
    return *this;
  }
  int operator-(Iter<T> &itr2) { return ptr - itr2.ptr; }
};
