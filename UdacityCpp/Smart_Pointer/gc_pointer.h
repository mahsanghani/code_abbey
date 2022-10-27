//
// Created by Ahsan Ghani on 2022-10-26.
//
#include "gc_details.h"
#include "gc_iterator.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <typeinfo>

template <class T, int size = 0> class Pointer {
private:
  static std::list<PtrDetails<T>> ref_countainer;
  T *addr;
  bool is_array;
  unsigned array_size;
  static bool first;
  typename std::list<PtrDetails<T>>::iterator findPtrInfo(T *ptr);

public:
  typedef Iter<T> GCiterator;
  Pointer() { Pointer(NULL); }
  Pointer(T *);
  Pointer(const Pointer &);
  ~Pointer();
  static bool collect();
  T *operator=(T *t);
  Pointer &operator=(Pointer &rv);
  T &operator*() { return *addr; }
  T *operator->() { return addr; }
  T &operator[](int i) { return addr[i]; }
  operator T *() { return addr; }
  Iter<T> begin() {
    int _size;
    if (is_array)
      _size = array_size;
    else
      _size = 1;
    return Iter<T>(addr, addr, addr + _size);
  }
  Iter<T> end() {
    int _size;
    if (is_array)
      _size = array_size;
    else
      _size = 1;
    return Iter<T>(addr + _size, addr, addr + _size);
  }
  static int refContainerSize() { return ref_countainer.size(); }
  static void showlist();
  static void shutdown();
};

template <class T, int size>
std::list<PtrDetails<T>> Pointer<T, size>::ref_countainer;
template <class T, int size> bool Pointer<T, size>::first = true;

template <class T, int size> Pointer<T, size>::Pointer(T *t) {
  if (first)
    atexit(shutdown);
  first = false;
  typename std::list<PtrDetails<T>>::iterator p;
  p = findPtrInfo(t);
  if (p != ref_countainer.end())
    p->ref_count++; // increment ref count
  else {
    PtrDetails<T> gcObj(t, size);
    ref_countainer.push_front(gcObj); // insert before the head of the list
  }

  addr = t;
  array_size = size;
  if (size > 0)
    is_array = true;
  else
    is_array = false;
#ifdef DISPLAY
  std::cout << "Constructing Pointer (w/ garbage collector).";
  if (is_array)
    std::cout << " Size is " << array_size << std::endl;
  else
    std::cout << std::endl;
#endif
}
